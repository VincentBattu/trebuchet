#include "glwindow.h"
#include <QDebug>
#include <GL/glu.h>

GLWindow::GLWindow(QWidget *parent) : GLWidget(60, parent, "Test")
{
    yRot = 0;
}

void GLWindow::initializeGL(){
    glShadeModel(GL_SMOOTH);
    qglClearColor(Qt::black);
    glClearDepth(1.0f);

    // Active le Z-buffer
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
   // glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

}

void GLWindow::resizeGL(int width, int height){
    int side = qMin(width, height);

    // Définit la taille de la fenêtre d'affichage
    glViewport(0, 0, width, height);

    // Définition de la caméra adapté à cette fenêtre
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70.0f, (GLfloat)width/(GLfloat)height, 0.1f, 100.0f);

    // On réinitialise la matrice d'affichage
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void GLWindow::paintGL(){
    yRot +=0.5;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        glTranslatef(-1.5f, 0.0f, -6.0f);

        glRotatef(yRot,0,1,0);
        glBegin(GL_QUADS);

            glColor3ub(255,0,0); //face rouge
            glVertex3d(1,1,1);
            glVertex3d(1,1,-1);
            glVertex3d(-1,1,-1);
            glVertex3d(-1,1,1);

            glColor3ub(0,255,0); //face verte
            glVertex3d(1,-1,1);
            glVertex3d(1,-1,-1);
            glVertex3d(1,1,-1);
            glVertex3d(1,1,1);

            glColor3ub(0,0,255); //face bleue
            glVertex3d(-1,-1,1);
            glVertex3d(-1,-1,-1);
            glVertex3d(1,-1,-1);
            glVertex3d(1,-1,1);

            glColor3ub(255,255,0); //face jaune
            glVertex3d(-1,1,1);
            glVertex3d(-1,1,-1);
            glVertex3d(-1,-1,-1);
            glVertex3d(-1,-1,1);

            glColor3ub(0,255,255); //face cyan
            glVertex3d(1,1,-1);
            glVertex3d(1,-1,-1);
            glVertex3d(-1,-1,-1);
            glVertex3d(-1,1,-1);

            glColor3ub(255,0,255); //face magenta
            glVertex3d(1,-1,1);
            glVertex3d(1,1,1);
            glVertex3d(-1,1,1);
            glVertex3d(-1,-1,1);

            glEnd();
}
