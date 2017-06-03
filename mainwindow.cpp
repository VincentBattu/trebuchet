#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <iostream>

using namespace cv;
using namespace std;

MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
    templateRect = new Rect((frameWidth-templateWidth)/2, 2*(frameHeight-templateHeight)/3, templateWidth,templateHeight);

    //On connecte le timer à l'affichage de la caméra
    displayCamTimer = new QTimer(this);
    connect(displayCamTimer, SIGNAL(timeout()), this, SLOT(displayCam()));
    displayCamTimer->start(20);

    connect(ui->difficulty, SIGNAL(currentIndexChanged(int)), ui->widget, SLOT(setLevel(int)));


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
    templateImage = Mat(templatedImg, *templateRect).clone();
    rectangle(matOriginal, *templateRect, Scalar(0,0,255),2,8,0);

    cvtColor(matOriginal, matOriginal, CV_BGR2RGB);
    QImage originalImage = QImage((uchar*)matOriginal.data, matOriginal.cols, matOriginal.rows, matOriginal.step, QImage::Format_RGB888);
    ui->camera->setPixmap(QPixmap::fromImage(originalImage));
}

/**
 * Quand on clique sur le bouton pour sauvegarder l'image de la main, le simple affichage s'arrête.
 * @brief MainWindow::on_save_clicked
 */
void MainWindow::on_save_clicked()
{
    if (displayCamTimer->isActive()){
        displayCamTimer->stop();
        ui->save->setVisible(false);
        processTimer = new QTimer(this);
        connect(processTimer, SIGNAL(timeout()), this, SLOT(getCoordinate()));
        connect(this, SIGNAL(yRotationChanged(int)), ui->widget, SLOT(setYRotation(int)));
        connect(this, SIGNAL(xRotationChanged(int)), ui->widget, SLOT(setXRotation(int)));
        processTimer->start(20);

    }
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
        int xAngle = maxLoc.y *360 / matOriginal.rows;
        emit xRotationChanged(xAngle);


    }
}

MainWindow::~MainWindow()
{
    delete ui;
}






