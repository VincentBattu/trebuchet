#ifndef GLWINDOW_H
#define GLWINDOW_H

#include "glwidget.h"
#include "terraindrawer.h"
#include "trebuchetdrawer.h"
#include "targetdrawer.h"

class GLWindow : public GLWidget
{
    Q_OBJECT

private:
    int yRot;
    TerrainDrawer *terrain;
    TrebuchetDrawer *trebuchet;
    TargetDrawer *target;
public:

    explicit GLWindow(QWidget *parent = 0);
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();

public slots:
    void setYRotation(int angle);
};

#endif // GLWINDOW_H
