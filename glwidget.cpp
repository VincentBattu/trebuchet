#include "glwidget.h"
#include <GL/glu.h>
#include <QDebug>

GLWidget::GLWidget(int framesPerSecond, QWidget *parent, char *name) : QGLWidget(parent)
{
    setWindowTitle(QString::fromUtf8(name));
       if(framesPerSecond == 0)
           timer = NULL;
       else
       {
           int seconde = 1000; // 1 seconde = 1000 ms
           int timerInterval = seconde / framesPerSecond;
           timer = new QTimer(this);
           connect(timer, SIGNAL(timeout()), this, SLOT(timeOutSlot()));
           timer->start( timerInterval );
       }
}

void GLWidget::timeOutSlot(){
    updateGL();
}
