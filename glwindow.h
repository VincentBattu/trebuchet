#ifndef GLWINDOW_H
#define GLWINDOW_H

#include "glwidget.h"
#include "terraindrawer.h"
#include "trebuchetdrawer.h"
#include "level.h"
#include "projectiledrawer.h"
#include "trajectory.h"


/**
 * Classe gérant l'appel pour l'affichage des différents
 * éléments de la scène.
 */
class GLWindow : public GLWidget
{
    Q_OBJECT

private:
    int yRot;
    int xRot;

    TerrainDrawer *terrain;
    TrebuchetDrawer *trebuchet;
    Level *level;
    ProjectileDrawer *projectile;
public:
    Trajectory *trajectoire;
    explicit GLWindow(QWidget *parent = 0);
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void setLevel(int level);

public slots:
    void setYRotation(int angle);
    void setXRotation(int angle);
    void calculTrajectoire();

};

#endif // GLWINDOW_H
