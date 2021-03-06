#ifndef MYWINDOW_H
#define MYWINDOW_H

#include "myglwidget.h"

class myWindow : public myGlWidget
{
    Q_OBJECT
public:
    explicit myWindow(QWidget *parent = 0);
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void draw();

private:
    float f_x;

    int xRot;
    int yRot;
    int zRot;
};

#endif // MYWINDOW_H
