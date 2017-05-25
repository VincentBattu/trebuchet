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


    // Définition du rectangle template
    templateRect = new Rect((frameWidth-templateWidth)/2, 2*(frameHeight-templateHeight)/3, templateWidth,templateHeight);

    //On connecte le timer à l'affichage de la caméra
    displayCamTimer = new QTimer(this);
    connect(displayCamTimer, SIGNAL(timeout()), this, SLOT(displayCam()));
    displayCamTimer->start(20);


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
    templateImage = Mat(matOriginal, *templateRect).clone();
    rectangle(matOriginal, *templateRect, Scalar(0,0,255),2,8,0);

    cvtColor(matOriginal, matOriginal, CV_BGR2RGB);
    QImage originalImage = QImage((uchar*)matOriginal.data, matOriginal.cols, matOriginal.rows, matOriginal.step, QImage::Format_RGB888);
    ui->camera->setPixmap(QPixmap::fromImage(originalImage));
}

/**
 * Quand on clique sur le bouton pour sauvarger l'image de la main, le simple affichage s'arrête.
 * @brief MainWindow::on_save_clicked
 */
void MainWindow::on_save_clicked()
{
    if (displayCamTimer->isActive()){
        displayCamTimer->stop();
        ui->save->setVisible(false);
        processTimer = new QTimer(this);
        connect(processTimer, SIGNAL(timeout()), this, SLOT(getCoordinate()));
        connect(this, SIGNAL(yRotationchanged(int)), ui->widget, SLOT(setYRotation(int)));
        processTimer->start(20);

    }
}

void MainWindow::getCoordinate(){
    if(cap.read(matOriginal)){
        flip(matOriginal, matOriginal,1);
        matchTemplate(matOriginal, templateImage, resultImage, TM_CCORR_NORMED);
        Point minLoc;
        Point maxLoc;
        minMaxLoc(resultImage, &minVal, &maxVal, &minLoc, &maxLoc, Mat());
        resultRect = Rect(maxLoc.x, maxLoc.y, templateWidth, templateHeight);

        Mat normResultImage;
        normalize(resultImage, normResultImage, 1, 0, NORM_MINMAX);
        cvtColor(normResultImage,normResultImage, CV_GRAY2RGB);
        rectangle(normResultImage, Rect(maxLoc.x, maxLoc.y,3,3),Scalar(0,0,1),2,8,0);
        rectangle(matOriginal, resultRect, Scalar(0,255,0),2,8,0);
        cvtColor(matOriginal, matOriginal, CV_BGR2RGB);
        QImage image = QImage((uchar*)matOriginal.data, matOriginal.cols, matOriginal.rows, matOriginal.step, QImage::Format_RGB888);
        ui->camera->setPixmap(QPixmap::fromImage(image));
        //TODO A refaire
        int yAngle = maxLoc.x * 180 / matOriginal.cols;
        emit yRotationchanged(yAngle);


    }
}

MainWindow::~MainWindow()
{
    delete ui;
}






