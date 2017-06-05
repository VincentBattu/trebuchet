#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QTimer>
#include <QTime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int nbRunsRemainded[3] = {5,4,3};

private:
    Ui::MainWindow *ui;

    cv::VideoCapture cap;
    cv::Mat matOriginal;
    cv::Mat templateImage;

    cv::Mat resultImage;
    int resultCols;
    int resultRows;
    cv::Rect resultRect;

    bool firsTime;
    int yPreviousFrame;
    int distance;
    int nbTimer=0;
    /**
     * @brief processTimer QTimer pour le processus de matching
     */
    QTimer *processTimer;
    /**
     * @brief changeCoordTimer QTimer pour changer les coordonnées
     * du projectile
     */
    QTimer *changeCoordTimer;


    // Rectangle pour mémoriser la main
    int templateWidth = 64;
    int templateHeight = 64;
    cv::Rect templateRect;

    // coordonnées récupérées par la caméra
    double minVal;
    double maxVal;

    cv::Point minLoc;
    cv::Point maxLoc;

    QTimer* displayCamTimer;

    QTime *totalTime;

    QTime *gameTime;


private slots:
    void displayCam();
    void getCoordinate();
    void updateTotalTime();
    void updateGameTime();
    void changeLevel(int);

signals:
    void yRotationChanged(int angle);
    void xRotationChanged(int angle);
};

#endif // MAINWINDOW_H
