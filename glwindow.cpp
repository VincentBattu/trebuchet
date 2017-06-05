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
    float x,y,z;
    x=trebuchet->projectile->x;
    y=trebuchet->projectile->y;
    z=trebuchet->projectile->z;
    trajectoire = new Trajectory(x,y,z,trebuchet->projectile,level->target);

    isLaunched = false;
}

void GLWindow::initializeGL(){
    glShadeModel(GL_SMOOTH);
    glEnable(GL_TEXTURE_2D);

    qglClearColor(QColor(119,181,254));
    glClearDepth(1.0f);

    // Active le Z-buffer
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

}

void GLWindow::setYRotation(int angle){
    yRot = angle;
}

void GLWindow::setXRotation(int angle){
    if(angle<-40){
        angle = -40;
    }
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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    if(!isLaunched){
        gluLookAt(0,10,-15,0,10,20,0,1,0);
        terrain->drawTerrain();
        trebuchet->drawTrebuchetProjectile(xRot,yRot);
        level->drawTarget();
    }else{
        gluLookAt(30,20,40,0,8,30,0,1,0);
        terrain->drawTerrain();
        trebuchet->drawTrebuchetProjectile(xRot,yRot);
        level->drawTarget();

    }

}

void GLWindow::setLevel(int lvl){
    level->setLevel(lvl);
    level->choosePosition();
}

void GLWindow::launchProjectile(){
    trajectoire->launchProjectile(&xRot);
}
