#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QtOpenGL>
#include <QGLWidget>

class myGlWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit myGlWidget(int framesPerSecond = 0, QWidget *parent = 0, char *name = 0);
    virtual void initializeGL() = 0;
    virtual void resizeGL(int w, int h) = 0;
    virtual void paintGL() = 0;
    virtual void keyPressEvent(QKeyEvent *keyEvent);

public slots:
    virtual void timeOutSlot();

private:
    QTimer *timer;
};

#endif // MYGLWIDGET_H
