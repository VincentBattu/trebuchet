#include "myglwidget.h"

myGlWidget::myGlWidget(int framesPerSecond, QWidget *parent, char *name) : QGLWidget(parent)
{
    setWindowTitle(QString::fromUtf8(name));
    if(framesPerSecond == 0){
        timer = NULL;
    } else {
        int second = 1000;
        int timerInterval = second / framesPerSecond;
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(timeOutSlot()));
        timer->start(timerInterval);

    }
}

void myGlWidget::keyPressEvent(QKeyEvent *keyEvent){
    switch(keyEvent->key()){
        case Qt::Key_Escape:
             close();
             break;
    }
}

void myGlWidget::timeOutSlot(){

}

