#ifndef GLWINDOW_H
#define GLWINDOW_H

#include "glwidget.h"
#include <QOpenGLTexture>

class GLWindow : public GLWidget
{
    Q_OBJECT

private:
    int yRot;
    GLuint GLdisplayList[1];
    QOpenGLTexture *texture;
public:

    explicit GLWindow(QWidget *parent = 0);
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();

    void drawTerrain();
    void drawFence();

    void drawTrebuchet(int rotX, int rotY);    
    void drawPlankClose();
    void drawPlankOpen();
    void drawCylinder();
    void drawArmature();

    void loadAndBlind(char* filename);

public slots:
    void setYRotation(int angle);
};

#endif // GLWINDOW_H
