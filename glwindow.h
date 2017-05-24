#ifndef GLWINDOW_H
#define GLWINDOW_H

#include "glwidget.h"

class GLWindow : public GLWidget
{
    Q_OBJECT

private:
    GLfloat yRot;
public:
    explicit GLWindow(QWidget *parent = 0);
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
};

#endif // GLWINDOW_H
