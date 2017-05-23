#ifndef PLAYER_H
#define PLAYER_H
#include <QMutex>
#include <QWaitCondition>
#include <QImage>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

class Player : public QThread
{
    Q_OBJECT

private:
    bool stop;
    QMutex mutex;
    QWaitCondition condition;
    Mat frame;
    int frameRate;
    VideoCapture capture;
    Mat RGBframe;
    QImage img;

signals:
    void processedImage(const QImage &image);

protected:
    void run();
    void msleep(int ms);

public:
    Player(QObject *parent = 0);
    ~Player();
    bool loadVideo(string filename);
    void play();
    void stop();
    bood isStopped() const;
};

#endif // PLAYER_H
