#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <iostream>


using namespace cv;
using namespace std;

MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->information->setText(QString("Placer votre main dans le carré rouge et amorcez un mouvement lent vers le bas pour lancer la partie"));
    bool firsTime = true;
    totalTime = new QTime(0,0,0);

    distance = 0;

    cap.open(0);
    if(!cap.isOpened()){
        return;
    }

    // On redimensionne la webcam
    int frameWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH);
    int frameHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
    frameWidth = frameWidth/2;
    frameHeight = frameHeight/2;
    cap.set(CV_CAP_PROP_FRAME_WIDTH, frameWidth);
    cap.set(CV_CAP_PROP_FRAME_HEIGHT, frameHeight);

    minLoc = Point(-1,-1);
    maxLoc = Point(-1,-1);

    // Définition du rectangle template
    templateRect = Rect((frameWidth-templateWidth)/2, 0, templateWidth,templateHeight);

    //On connecte le timer à l'affichage de la caméra
    displayCamTimer = new QTimer(this);
    connect(displayCamTimer, SIGNAL(timeout()), this, SLOT(displayCam()));
    displayCamTimer->start(20);

    connect(ui->difficulty, SIGNAL(currentIndexChanged(int)), this, SLOT(changeLevel(int)));


}

void MainWindow::changeLevel(int lvl){
    ui->widget->setLevel(lvl);
    ui->targetremainding_value->setText(QString::number(nbRunsRemainded[ui->difficulty->currentIndex()]));
}

/**
 * Affiche la caméra et le le carré rouge au milieu pour mémoriser la forme de la main.
 * @brief MainWindow::displayCam
 *
 */
void MainWindow::displayCam(){
    cap.read(matOriginal);

    if (matOriginal.empty() == true)  return;

    flip(matOriginal, matOriginal, 1);
    Mat templatedImg;
   if (maxLoc.x = -1){
       templatedImg = matOriginal;
   } else {
       int heightRect = 30;
       int xRect = maxLoc.x-heightRect;
       int yRect = maxLoc.y -heightRect;
       int width = templateWidth +heightRect *2;
       int height = templateHeight +heightRect*2;
       Rect roi = Rect(xRect, yRect, width, height);
       templatedImg = Mat(matOriginal, roi);
   }
   // On stocke la zone de l'image située dans le rectangle.
   if (firsTime){
      templateImage = Mat(templatedImg, templateRect).clone();

      // On dessine le rectangle sur la frame
      rectangle(matOriginal, templateRect, Scalar(0,0,255),2,8,0);
      yPreviousFrame = templateRect.y;
      firsTime = false;
   }

   // On recherche l'image dans la zone prédéfinie et on stocke le résultat dans resultImage
   matchTemplate(templatedImg, templateImage, resultImage, TM_CCORR_NORMED);
   minMaxLoc(resultImage, &minVal, &maxVal, &minLoc, &maxLoc, Mat());
   resultRect = Rect(maxLoc.x, maxLoc.y, templateWidth, templateHeight);

   templateImage = Mat(matOriginal, resultRect).clone();

   Mat normResultImage;
   normalize(resultImage, normResultImage, 1, 0, NORM_MINMAX);
   cvtColor(normResultImage,normResultImage, CV_GRAY2RGB);
   rectangle(normResultImage, Rect(maxLoc.x, maxLoc.y,3,3),Scalar(0,0,1),2,8,0);
   rectangle(matOriginal, resultRect, Scalar(0,0,255),2,8,0);

   if (yPreviousFrame < maxLoc.y){
       distance += (maxLoc.y - yPreviousFrame );
   } else {
       distance =0;
   }

   if (distance >= 100){
       displayCamTimer->stop();

       processTimer = new QTimer(this);
       connect(processTimer, SIGNAL(timeout()), this, SLOT(getCoordinate()));

       totalTime->start();
       ui->targetremainding_value->setText(QString::number(nbRunsRemainded[ui->difficulty->currentIndex()]));
       ui->information->setText(QString("Contrôler le trébuchet avec votre main et déclenchez le tir à l'aide d'un mouvement rapide vers le bas"));
       connect(processTimer, SIGNAL(timeout()), this, SLOT(updateTotalTime()));
       processTimer->start(20);

       connect(this, SIGNAL(yRotationChanged(int)), ui->widget, SLOT(setYRotation(int)));
       connect(this, SIGNAL(xRotationChanged(int)), ui->widget, SLOT(setXRotation(int)));


   }


   // Affichage de la frame
   cvtColor(matOriginal, matOriginal, CV_BGR2RGB);
   QImage originalImage = QImage((uchar*)matOriginal.data, matOriginal.cols, matOriginal.rows, matOriginal.step, QImage::Format_RGB888);
   ui->camera->setPixmap(QPixmap::fromImage(originalImage));

   yPreviousFrame = maxLoc.y;
}

void MainWindow::updateTotalTime(){
    QTime n = QTime(0,0,0);
    QTime t;
    t = n.addMSecs(totalTime->elapsed());
    ui->total_time_value->setText(t.toString());
}


void MainWindow::getCoordinate(){
    if(cap.read(matOriginal)){
        flip(matOriginal, matOriginal,1);
         Mat templatedImg;
        if (maxLoc.x = -1){
            templatedImg = matOriginal;
        } else {
            int heightRect = 30;
            int xRect = maxLoc.x-heightRect;
            int yRect = maxLoc.y -heightRect;
            int width = templateWidth +heightRect *2;
            int height = templateHeight +heightRect*2;
            Rect roi = Rect(xRect, yRect, width, height);
            templatedImg = Mat(matOriginal, roi);
        }


        matchTemplate(templatedImg, templateImage, resultImage, TM_CCORR_NORMED);

        minMaxLoc(resultImage, &minVal, &maxVal, &minLoc, &maxLoc, Mat());
        resultRect = Rect(maxLoc.x, maxLoc.y, templateWidth, templateHeight);
        templateImage = Mat(matOriginal, resultRect).clone();

        Mat normResultImage;
        normalize(resultImage, normResultImage, 1, 0, NORM_MINMAX);
        cvtColor(normResultImage,normResultImage, CV_GRAY2RGB);
        rectangle(normResultImage, Rect(maxLoc.x, maxLoc.y,3,3),Scalar(0,0,1),2,8,0);
        rectangle(matOriginal, resultRect, Scalar(0,255,0),2,8,0);
        cvtColor(matOriginal, matOriginal, CV_BGR2RGB);
        QImage image = QImage((uchar*)matOriginal.data, matOriginal.cols, matOriginal.rows, matOriginal.step, QImage::Format_RGB888);

        ui->camera->setPixmap(QPixmap::fromImage(image));
        //TODO A refaire
        int yAngle = maxLoc.x * 360 / matOriginal.cols - 180;
        emit yRotationChanged(yAngle);
        int xAngle = maxLoc.y *-40 / matOriginal.rows;
        emit xRotationChanged(xAngle);


    }
}

MainWindow::~MainWindow()
{
    delete ui;
}






