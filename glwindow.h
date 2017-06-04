#ifndef GLWINDOW_H
#define GLWINDOW_H

#include "glwidget.h"
#include "terraindrawer.h"
#include "trebuchetdrawer.h"
#include "level.h"
#include "projectiledrawer.h"
#include "simulation.h"
#include <QVector3D>

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
    Simulation* ropeSimulation = new Simulation(
                                                        80,						// 80 Particles (Masses)
                                                        0.05f,					// Each Particle Has A Weight Of 50 Grams
                                                        10000.0f,				// springConstant In The Rope
                                                        0.05f,					// Normal Length Of Springs In The Rope
                                                        0.2f,					// Spring Inner Friction Constant
                                                        QVector3D(0, -9.81f, 0), // Gravitational Acceleration
                                                        0.02f,					// Air Friction Constant
                                                        100.0f,					// Ground Repel Constant
                                                        0.2f,					// Ground Slide Friction Constant
                                                        2.0f,					// Ground Absoption Constant
                                                        -1.5f);
public:

    explicit GLWindow(QWidget *parent = 0);
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void setLevel(int level);

public slots:
    void setYRotation(int angle);
    void setXRotation(int angle);

};

#endif // GLWINDOW_H
