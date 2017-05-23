#include "mywindow.h"
#include <GL/glu.h>

myWindow::myWindow(QWidget *parent) : myGlWidget(60, parent, "Premier pas avec Qt et OpenGl")
{

}

void myWindow::initializeGL(){
   // glClearColor(Qt::black);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    static GLfloat lightPosition[4] = {0, 0, 10, 1.0};
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}

void myWindow::resizeGL(int width, int height)
{
    int side = qMin(width, height);
    glViewport((width - side)/2, (height-side)/2, side, side);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
   // gluPerspective(70, (double)640/480,1,1000);
    glMatrixMode(GL_MODELVIEW);
}


void myWindow::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    draw();
}

void myWindow::draw(){
    gluLookAt(3,4,2,0,0,0,0,0,1);
    glBegin(GL_QUADS);
        glColor3ub(255,0,0);
        glVertex3d(1,1,1);
        glVertex3d(1,1,-1);
        glVertex3d(-1,1,-1);
        glVertex3d(-1,1,1);

        glColor3ub(0,255,0);
        glVertex3d(1,-1,1);
        glVertex3d(1,-1,-1);
        glVertex3d(1,1,-1);
        glVertex3d(1,1,1);

        glColor3ub(0,0,255);
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
