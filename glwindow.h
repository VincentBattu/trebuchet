#ifndef GLWINDOW_H
#define GLWINDOW_H

#include "glwidget.h"
#include "terraindrawer.h"
#include "trebuchetdrawer.h"
#include "level.h"
#include "projectiledrawer.h"

/**
 * Classe gérant l'appel pour l'affichage des différents
 * éléments de la scène.
 */
class GLWindow : public GLWidget
{
    Q_OBJECT

private:
    int yRot;
    TerrainDrawer *terrain;
    TrebuchetDrawer *trebuchet;
    Level *level;
    ProjectileDrawer *projectile;
public:

    explicit GLWindow(QWidget *parent = 0);
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();

public slots:
    void setYRotation(int angle);
};

#endif // GLWINDOW_H
