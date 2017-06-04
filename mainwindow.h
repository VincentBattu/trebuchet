#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    cv::VideoCapture cap;
    cv::Mat matOriginal;
    cv::Mat templateImage;

    cv::Mat resultImage;
    int resultCols;
    int resultRows;
    cv::Rect resultRect;
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
    cv::Rect *templateRect;

    // coordonnées récupérées par la caméra
    double minVal;
    double maxVal;

    cv::Point minLoc;
    cv::Point maxLoc;

    QTimer* displayCamTimer;


private slots:
    void displayCam();
    void getCoordinate();
    void on_save_clicked();

signals:
    void yRotationChanged(int angle);
    void xRotationChanged(int angle);
};

#endif // MAINWINDOW_H
