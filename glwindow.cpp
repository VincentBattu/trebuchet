#include "glwindow.h"
#include <QDebug>
#include <GL/glu.h>
#include <QOpenGLTexture>
#include <unistd.h>

GLWindow::GLWindow(QWidget *parent) : GLWidget(60, parent, "Test")
{
    yRot = 0;
    terrain = new TerrainDrawer();
    trebuchet = new TrebuchetDrawer();
    level = new Level(0);
}

void GLWindow::initializeGL(){
    glShadeModel(GL_SMOOTH);
    glEnable(GL_TEXTURE_2D);

    ropeSimulation->getMass(ropeSimulation->nbOfMasses - 1)->vel.setZ(10.0f);

    qglClearColor(QColor(119,181,254));
    glClearDepth(1.0f);

    // Active le Z-buffer
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
   // glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

}

void GLWindow::setYRotation(int angle){
    yRot = angle;

}

void GLWindow::setXRotation(int angle){
     xRot = angle;

}

void GLWindow::resizeGL(int width, int height){
    int side = qMin(width, height);

    // Définit la taille de la fenêtre d'affichage
    glViewport(0, 0, width, height);

    // Définition de la caméra adapté à cette fenêtre
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70.0f, (GLfloat)width/(GLfloat)height, 0.1f, 150.0f);

    // On réinitialise la matrice d'affichage
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void GLWindow::paintGL(){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0, 0, 4, 0, 0, 0, 0, 1, 0);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


   // gluLookAt(0,10,-10,0,4,0,0,1,0);

    //terrain->drawTerrain();
   // trebuchet->drawTrebuchet(xRot ,yRot);
    //level->drawTarget();

    float dt = 0.5;
    float maxPossible_dt = 0.002f;

    int nbOfIterations = (int)(dt/maxPossible_dt) +1;
    if (nbOfIterations !=0)
        dt =dt /nbOfIterations;
    for (int a =0; a<nbOfIterations; a++)
        ropeSimulation->operate(dt);


        glColor3ub(255, 255, 0);												// Set Color To Yellow
            for (int a = 0; a < ropeSimulation->nbOfMasses - 1; ++a)
            {
                Mass* mass1 = ropeSimulation->getMass(a);
                QVector3D* pos1 = &mass1->pos;

                Mass* mass2 = ropeSimulation->getMass(a + 1);
                QVector3D* pos2 = &mass2->pos;

                glLineWidth(4);
                glBegin(GL_LINES);
                    glVertex3f(pos1->x(), pos1->y(), pos1->z());
                    glVertex3f(pos2->x(), pos2->y(), pos2->z());
                glEnd();
            }


}

void GLWindow::setLevel(int lvl){
     level->setLevel(lvl);
    level->choosePosition();
}
