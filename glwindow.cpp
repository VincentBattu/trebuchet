#include "glwindow.h"
#include <QDebug>
#include <GL/glu.h>
#include <QOpenGLTexture>

GLWindow::GLWindow(QWidget *parent) : GLWidget(60, parent, "Test")
{
    yRot = 0;
    /*loadAndBlindGrass();
    loadAndBlindWood();
    loadAndBlindFence();*/
}

void GLWindow::initializeGL(){
    glShadeModel(GL_SMOOTH);
    glEnable(GL_TEXTURE_2D);
    qglClearColor(Qt::black);
    glClearDepth(1.0f);

    // Active le Z-buffer
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
   // glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

}

void GLWindow::setYRotation(int angle){
    yRot = angle;
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

void GLWindow::loadAndBlindWood(){
    textureWood = new QOpenGLTexture(QImage("../trebuchet/bois_trebuchet3.png").mirrored());
    textureWood->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
    textureWood->setMagnificationFilter(QOpenGLTexture::Linear);
    textureWood->bind();
}
void GLWindow::loadAndBlindFence(){
    textureFence = new QOpenGLTexture(QImage("../trebuchet/fence.png").mirrored());
    textureFence->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
    textureFence->setMagnificationFilter(QOpenGLTexture::Linear);
    textureFence->bind();
}
void GLWindow::loadAndBlindGrass(){
    textureGrass = new QOpenGLTexture(QImage("../trebuchet/grass.jpg").mirrored());
    textureGrass->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
    textureGrass->setMagnificationFilter(QOpenGLTexture::Linear);
    textureGrass->bind();
}


void GLWindow::drawTerrain(){
    loadAndBlindGrass();
    //glBindTexture(GL_TEXTURE_2D, textureGrass);
    //textureGrass->bind();
   glColor3ub(255,255,255);
   int step=10;
    for (int i =-50; i <=50-step; i+=step){
        for (int j =-50; j <=50-step; j+=step){
            glBegin(GL_QUADS);
                glTexCoord2d(0,0);
                glVertex3d(i,0,j);
                glTexCoord2d(0,1);
                glVertex3d(i+step,0,j);
                glTexCoord2d(1,1);
                glVertex3d(i+step,0,j+step);
                glTexCoord2d(1,0);
                glVertex3d(i,0,j+step);
            glEnd();
        }
    }
    glPushMatrix();
        glTranslatef(-50,0,0);
        glRotatef(90,0,1,0);
        glScalef(12.5,1,1);
        drawFence();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(50,0,0);
        glRotatef(90,0,1,0);
        glScalef(12.5,1,1);
        drawFence();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0,0,50);
        glScalef(12.5,1,1);
        drawFence();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0,0,-50);
        glScalef(12.5,1,1);
        drawFence();
    glPopMatrix();

}

void GLWindow::drawFence(){
    int width = 8;
    int height = 4;
    loadAndBlindFence();
    //glBindTexture(GL_TEXTURE_2D, textureFence);
    //textureFence->bind();
    glPushMatrix();
    glEnable( GL_TEXTURE_2D );
    glDisable( GL_CULL_FACE );
    glMatrixMode( GL_MODELVIEW );
    //glLoadIdentity( );
        glBegin(GL_QUADS);
           glTexCoord2d(0,0);
            glVertex3d(-width/2,0,0);
            glTexCoord2d(0,5);
            glVertex3d(width/2,0,0);
            glTexCoord2d(1,5);
            glVertex3d(width/2,height,0);
            glTexCoord2d(1,0);
            glVertex3d(-width/2,height,0);
        glEnd();
        glDisable( GL_TEXTURE_2D );
        glEnable( GL_CULL_FACE );
    glPopMatrix();
    glPushMatrix();
    glMatrixMode( GL_MODELVIEW );
        glBegin(GL_LINES);
            glColor3f(.5,.5,.5);
            glVertex3d(width/2,height,0);
            glVertex3d(-width/2,height,0);
            glColor3f(1,1,1);
        glEnd();
    glPopMatrix();
    glPushMatrix();
    glMatrixMode( GL_MODELVIEW );
    glColor3f(.5,.5,.5);
        glTranslatef(-width/2,0,0);
        glRotatef(-90,1,0,0);
        glScalef(.5,.5,height);
        drawCylinder();
    glPopMatrix();
    glPushMatrix();
    glMatrixMode( GL_MODELVIEW );
        glTranslatef(width/2,0,0);
        glRotatef(-90,1,0,0);
        glScalef(.5,.5,height);
        drawCylinder();
        glColor3f(1,1,1);
    glPopMatrix();
}

void GLWindow::drawPlankClose(){

    glEnable( GL_TEXTURE_2D );
    glDisable( GL_CULL_FACE );
    loadAndBlindWood();
    //glBindTexture(GL_TEXTURE_2D, textureWood);
    //textureWood->bind();
    glPushMatrix();
        glMatrixMode( GL_MODELVIEW );
        glEnable(GL_TEXTURE_GEN_S);
        glEnable(GL_TEXTURE_GEN_T);
        gluQuadricTexture(gluNewQuadric(),GL_TRUE);

        glBegin(GL_QUAD_STRIP);
            glVertex3f(-0.3,0,-.3);
            glVertex3f(-0.3,0,.3);
            glVertex3f(-0.3,0.6,-.3);
            glVertex3f(-0.3,0.6,.3);
            glVertex3f(0.3,.6,-.3);
            glVertex3f(0.3,.6,.3);
            glVertex3f(0.3,0,-.3);
            glVertex3f(.3,0,.3);
            glVertex3f(-0.3,0,-.3);
            glVertex3f(-0.3,0,.3);
        glEnd();
        glBegin(GL_QUADS);
            glVertex3f(-.3,0,-.3);
            glVertex3f(.3,0,-.3);
            glVertex3f(.3,.6,-.3);
            glVertex3f(-.3,.6,-.3);
        glEnd();
        glBegin(GL_QUADS);
            glVertex3f(-.3,0,.3);
            glVertex3f(.3,0,.3);
            glVertex3f(.3,.6,.3);
            glVertex3f(-.3,.6,.3);
        glEnd();

        glDisable(GL_TEXTURE_GEN_S);
        glDisable(GL_TEXTURE_GEN_T);
    glPopMatrix();
    glDisable( GL_TEXTURE_2D );
    glEnable( GL_CULL_FACE );

}

void GLWindow::drawCylinder(){

    glEnable( GL_TEXTURE_2D );
    glDisable( GL_CULL_FACE );
    //loadAndBlindWood();
    //glBindTexture(GL_TEXTURE_2D, textureWood);
    textureWood->bind();
    glPushMatrix();
        glMatrixMode( GL_MODELVIEW );
        glEnable(GL_TEXTURE_GEN_S);
        glEnable(GL_TEXTURE_GEN_T);
        gluQuadricTexture(gluNewQuadric(),GL_TRUE);
        gluCylinder(gluNewQuadric(),.5,.5,1,15,15);
        glBegin ( GL_TRIANGLES );
            glNormal3f(0.702714,-1.06018e-008,-0.711473);
            glVertex3f(.5,0,0);
            glNormal3f(0,0,-1);
            glVertex3f(0,0,0);
            glNormal3f(0.66832,0.21715,-0.711473);
            glVertex3f(0.475528,0.154509,0);
            glNormal3f(0.66832,0.21715,-0.711473);
            glVertex3f(0.475528,0.154509,0);
            glNormal3f(0,0,-1);
            glVertex3f(0,0,0);
            glNormal3f(0.568507,0.413045,-0.711473);
            glVertex3f(0.404509,0.293893,0);
            glNormal3f(0.568507,0.413045,-0.711473);
            glVertex3f(0.404509,0.293893,0);
            glNormal3f(0,0,-1);
            glVertex3f(0,0,0);
            glNormal3f(0.413045,0.568507,-0.711473);
            glVertex3f(0.293893,0.404509,0);
            glNormal3f(0.413045,0.568507,-0.711473);
            glVertex3f(0.293893,0.404509,0);
            glNormal3f(0,0,-1);
            glVertex3f(0,0,0);
            glNormal3f(0.21715,0.66832,-0.711473);
            glVertex3f(0.154508,0.475528,0);
            glNormal3f(0.21715,0.66832,-0.711473);
            glVertex3f(0.154508,0.475528,0);
            glNormal3f(0,0,-1);
            glVertex3f(0,0,0);
            glNormal3f(-6.36106e-008,0.702713,-0.711473);
            glVertex3f(-2.18557e-008,0.5,0);
            glNormal3f(-6.36106e-008,0.702713,-0.711473);
            glVertex3f(-2.18557e-008,0.5,0);
            glNormal3f(0,0,-1);
            glVertex3f(0,0,0);
            glNormal3f(-0.21715,0.66832,-0.711473);
            glVertex3f(-0.154509,0.475528,0);
            glNormal3f(-0.21715,0.66832,-0.711473);
            glVertex3f(-0.154509,0.475528,0);
            glNormal3f(0,0,-1);
            glVertex3f(0,0,0);
            glNormal3f(-0.413045,0.568507,-0.711473);
            glVertex3f(-0.293893,0.404509,0);
            glNormal3f(-0.413045,0.568507,-0.711473);
            glVertex3f(-0.293893,0.404509,0);
            glNormal3f(0,0,-1);
            glVertex3f(0,0,0);
            glNormal3f(-0.568507,0.413045,-0.711473);
            glVertex3f(-0.404509,0.293893,0);
            glNormal3f(-0.568507,0.413045,-0.711473);
            glVertex3f(-0.404509,0.293893,0);
            glNormal3f(0,0,-1);
            glVertex3f(0,0,0);
            glNormal3f(-0.66832,0.21715,-0.711473);
            glVertex3f(-0.475528,0.154508,0);
            glNormal3f(-0.66832,0.21715,-0.711473);
            glVertex3f(-0.475528,0.154508,0);
            glNormal3f(0,0,-1);
            glVertex3f(0,0,0);
            glNormal3f(-0.702714,-6.36106e-008,-0.711473);
            glVertex3f(-0.5,-4.37114e-008,0);
            glNormal3f(-0.702714,-6.36106e-008,-0.711473);
            glVertex3f(-0.5,-4.37114e-008,0);
            glNormal3f(0,0,-1);
            glVertex3f(0,0,0);
            glNormal3f(-0.66832,-0.21715,-0.711473);
            glVertex3f(-0.475528,-0.154508,0);
            glNormal3f(-0.66832,-0.21715,-0.711473);
            glVertex3f(-0.475528,-0.154508,0);
            glNormal3f(0,0,-1);
            glVertex3f(0,0,0);
            glNormal3f(-0.568507,-0.413045,-0.711473);
            glVertex3f(-0.404508,-0.293893,0);
            glNormal3f(-0.568507,-0.413045,-0.711473);
            glVertex3f(-0.404508,-0.293893,0);
            glNormal3f(0,0,-1);
            glVertex3f(0,0,0);
            glNormal3f(-0.413045,-0.568507,-0.711473);
            glVertex3f(-0.293893,-0.404509,0);
            glNormal3f(-0.413045,-0.568507,-0.711473);
            glVertex3f(-0.293893,-0.404509,0);
            glNormal3f(0,0,-1);
            glVertex3f(0,0,0);
            glNormal3f(-0.21715,-0.66832,-0.711473);
            glVertex3f(-0.154509,-0.475528,0);
            glNormal3f(-0.21715,-0.66832,-0.711473);
            glVertex3f(-0.154509,-0.475528,0);
            glNormal3f(0,0,-1);
            glVertex3f(0,0,0);
            glNormal3f(0,-0.702714,-0.711473);
            glVertex3f(5.96244e-009,-0.5,0);
            glNormal3f(0,-0.702714,-0.711473);
            glVertex3f(5.96244e-009,-0.5,0);
            glNormal3f(0,0,-1);
            glVertex3f(0,0,0);
            glNormal3f(0.217151,-0.66832,-0.711473);
            glVertex3f(0.154509,-0.475528,0);
            glNormal3f(0.217151,-0.66832,-0.711473);
            glVertex3f(0.154509,-0.475528,0);
            glNormal3f(0,0,-1);
            glVertex3f(0,0,0);
            glNormal3f(0.413045,-0.568507,-0.711473);
            glVertex3f(0.293893,-0.404508,0);
            glNormal3f(0.413045,-0.568507,-0.711473);
            glVertex3f(0.293893,-0.404508,0);
            glNormal3f(0,0,-1);
            glVertex3f(0,0,0);
            glNormal3f(0.568507,-0.413044,-0.711473);
            glVertex3f(0.404509,-0.293892,0);
            glNormal3f(0.568507,-0.413044,-0.711473);
            glVertex3f(0.404509,-0.293892,0);
            glNormal3f(0,0,-1);
            glVertex3f(0,0,0);
            glNormal3f(0.66832,-0.21715,-0.711473);
            glVertex3f(0.475528,-0.154508,0);
            glNormal3f(0.66832,-0.21715,-0.711473);
            glVertex3f(0.475528,-0.154508,0);
            glNormal3f(0,0,-1);
            glVertex3f(0,0,0);
            glNormal3f(0.702714,-1.06018e-008,-0.711473);
            glVertex3f(.5,0,0);
            glNormal3f(0.66832,0.21715,0.711473);
            glVertex3f(0.475528,0.154509,1);
            glNormal3f(0,0,1);
            glVertex3f(0,0,1);
            glNormal3f(0.702714,-1.06018e-008,0.711473);
            glVertex3f(0.5,0,1);
            glNormal3f(0.568507,0.413045,0.711473);
            glVertex3f(0.404509,0.293893,1);
            glNormal3f(0,0,1);
            glVertex3f(0,0,1);
            glNormal3f(0.66832,0.21715,0.711473);
            glVertex3f(0.475528,0.154509,1);
            glNormal3f(0.413045,0.568507,0.711473);
            glVertex3f(0.293893,0.404509,1);
            glNormal3f(0,0,1);
            glVertex3f(0,0,1);
            glNormal3f(0.568507,0.413045,0.711473);
            glVertex3f(0.404509,0.293893,1);
            glNormal3f(0.21715,0.66832,0.711473);
            glVertex3f(0.154508,0.475528,1);
            glNormal3f(0,0,1);
            glVertex3f(0,0,1);
            glNormal3f(0.413045,0.568507,0.711473);
            glVertex3f(0.293893,0.404509,1);
            glNormal3f(-6.36106e-008,0.702713,0.711473);
            glVertex3f(-2.18557e-008,0.5,1);
            glNormal3f(0,0,1);
            glVertex3f(0,0,1);
            glNormal3f(0.21715,0.66832,0.711473);
            glVertex3f(0.154508,0.475528,1);
            glNormal3f(-0.21715,0.66832,0.711473);
            glVertex3f(-0.154509,0.475528,1);
            glNormal3f(0,0,1);
            glVertex3f(0,0,1);
            glNormal3f(-6.36106e-008,0.702713,0.711473);
            glVertex3f(-2.18557e-008,0.5,1);
            glNormal3f(-0.413045,0.568507,0.711473);
            glVertex3f(-0.293893,0.404509,1);
            glNormal3f(0,0,1);
            glVertex3f(0,0,1);
            glNormal3f(-0.21715,0.66832,0.711473);
            glVertex3f(-0.154509,0.475528,1);
            glNormal3f(-0.568507,0.413045,0.711473);
            glVertex3f(-0.404509,0.293893,1);
            glNormal3f(0,0,1);
            glVertex3f(0,0,1);
            glNormal3f(-0.413045,0.568507,0.711473);
            glVertex3f(-0.293893,0.404509,1);
            glNormal3f(-0.66832,0.21715,0.711473);
            glVertex3f(-0.475528,0.154508,1);
            glNormal3f(0,0,1);
            glVertex3f(0,0,1);
            glNormal3f(-0.568507,0.413045,0.711473);
            glVertex3f(-0.404509,0.293893,1);
            glNormal3f(-0.702714,-6.36106e-008,0.711473);
            glVertex3f(-0.5,-4.37114e-008,1);
            glNormal3f(0,0,1);
            glVertex3f(0,0,1);
            glNormal3f(-0.66832,0.21715,0.711473);
            glVertex3f(-0.475528,0.154508,1);
            glNormal3f(-0.66832,-0.21715,0.711473);
            glVertex3f(-0.475528,-0.154508,1);
            glNormal3f(0,0,1);
            glVertex3f(0,0,1);
            glNormal3f(-0.702714,-6.36106e-008,0.711473);
            glVertex3f(-0.5,-4.37114e-008,1);
            glNormal3f(-0.568507,-0.413045,0.711473);
            glVertex3f(-0.404508,-0.293893,1);
            glNormal3f(0,0,1);
            glVertex3f(0,0,1);
            glNormal3f(-0.66832,-0.21715,0.711473);
            glVertex3f(-0.475528,-0.154508,1);
            glNormal3f(-0.413045,-0.568507,0.711473);
            glVertex3f(-0.293893,-0.404509,1);
            glNormal3f(0,0,1);
            glVertex3f(0,0,1);
            glNormal3f(-0.568507,-0.413045,0.711473);
            glVertex3f(-0.404508,-0.293893,1);
            glNormal3f(-0.21715,-0.66832,0.711473);
            glVertex3f(-0.154509,-0.475528,1);
            glNormal3f(0,0,1);
            glVertex3f(0,0,1);
            glNormal3f(-0.413045,-0.568507,0.711473);
            glVertex3f(-0.293893,-0.404509,1);
            glNormal3f(0,-0.702714,0.711473);
            glVertex3f(5.96244e-009,-0.5,1);
            glNormal3f(0,0,1);
            glVertex3f(0,0,1);
            glNormal3f(-0.21715,-0.66832,0.711473);
            glVertex3f(-0.154509,-0.475528,1);
            glNormal3f(0.217151,-0.66832,0.711473);
            glVertex3f(0.154509,-0.475528,1);
            glNormal3f(0,0,1);
            glVertex3f(0,0,1);
            glNormal3f(0,-0.702714,0.711473);
            glVertex3f(5.96244e-009,-0.5,1);
            glNormal3f(0.413045,-0.568507,0.711473);
            glVertex3f(0.293893,-0.404508,1);
            glNormal3f(0,0,1);
            glVertex3f(0,0,1);
            glNormal3f(0.217151,-0.66832,0.711473);
            glVertex3f(0.154509,-0.475528,1);
            glNormal3f(0.568507,-0.413044,0.711473);
            glVertex3f(0.404509,-0.293892,1);
            glNormal3f(0,0,1);
            glVertex3f(0,0,1);
            glNormal3f(0.413045,-0.568507,0.711473);
            glVertex3f(0.293893,-0.404508,1);
            glNormal3f(0.66832,-0.21715,0.711473);
            glVertex3f(0.475528,-0.154508,1);
            glNormal3f(0,0,1);
            glVertex3f(0,0,1);
            glNormal3f(0.568507,-0.413044,0.711473);
            glVertex3f(0.404509,-0.293892,1);
            glNormal3f(0.702714,-1.06018e-008,0.711473);
            glVertex3f(0.5,0,1);
            glNormal3f(0,0,1);
            glVertex3f(0,0,1);
            glNormal3f(0.66832,-0.21715,0.711473);
            glVertex3f(0.475528,-0.154508,1);
        glEnd ();
        glDisable(GL_TEXTURE_GEN_S);
        glDisable(GL_TEXTURE_GEN_T);
    glPopMatrix();
    glDisable( GL_TEXTURE_2D );
    glEnable( GL_CULL_FACE );

}

void GLWindow::drawPlankOpen(){
    glEnable( GL_TEXTURE_2D );
    glDisable( GL_CULL_FACE );
    loadAndBlindWood();
    //glBindTexture(GL_TEXTURE_2D, textureWood);
    //textureWood->bind();
    glPushMatrix();
        glMatrixMode( GL_MODELVIEW );
        glEnable(GL_TEXTURE_GEN_S);
        glEnable(GL_TEXTURE_GEN_T);
        gluQuadricTexture(gluNewQuadric(),GL_TRUE);

        glBegin(GL_QUAD_STRIP);
            glVertex3f(.3,.6,4.5);
            glVertex3f(.3,9,.3);
            glVertex3f(.3,.6,3.9);
            glVertex3f(.3,7.6,.3);
            glVertex3f(-.3,.6,3.9);
            glVertex3f(-.3,7.6,.3);
            glVertex3f(-.3,.6,4.5);
            glVertex3f(-.3,9,.3);
            glVertex3f(.3,.6,4.5);
            glVertex3f(.3,9,.3);
        glEnd();
        glBegin(GL_QUAD_STRIP);
            glVertex3f(.3,.6,-4.5);
            glVertex3f(.3,9,-.3);
            glVertex3f(.3,.6,-3.9);
            glVertex3f(.3,7.6,-.3);
            glVertex3f(-.3,.6,-3.9);
            glVertex3f(-.3,7.6,-.3);
            glVertex3f(-.3,.6,-4.5);
            glVertex3f(-.3,9,-.3);
            glVertex3f(.3,.6,-4.5);
            glVertex3f(.3,9,-.3);
        glEnd();

        glBegin(GL_QUAD_STRIP);
            glVertex3f(2.5,0,.7);
            glVertex3f(.3,9,.7);
            glVertex3f(2.1,0,.7);
            glVertex3f(0,9,.7);
            glVertex3f(2.1,0,.3);
            glVertex3f(0,9,.3);
            glVertex3f(2.4,0,.3);
            glVertex3f(.3,9,.3);
            glVertex3f(2.5,0,.7);
            glVertex3f(0,9,.7);
        glEnd();
        glBegin(GL_QUAD_STRIP);
            glVertex3f(2.5,0,-.7);
            glVertex3f(.3,9,-.7);
            glVertex3f(2.1,0,-.7);
            glVertex3f(0,9,-.7);
            glVertex3f(2.1,0,-.3);
            glVertex3f(0,9,-.3);
            glVertex3f(2.4,0,-.3);
            glVertex3f(.3,9,-.3);
            glVertex3f(2.5,0,-.7);
            glVertex3f(0,9,-.7);
        glEnd();

        glDisable(GL_TEXTURE_GEN_S);
        glDisable(GL_TEXTURE_GEN_T);
    glPopMatrix();
    glDisable( GL_TEXTURE_2D );
    glEnable( GL_CULL_FACE );

}


void GLWindow::drawArmature(){
    glEnable( GL_TEXTURE_2D );
    glDisable( GL_CULL_FACE );

    glMatrixMode( GL_MODELVIEW );
    glPushMatrix ();
        glTranslatef(0,0,0);
        glScalef(1,1,10/.6);
        drawPlankClose();
    glPopMatrix ();
    glPushMatrix ();
        glTranslatef(0,4.2,-.35);
        glRotatef(90,1,0,0);
        glScalef(1,1,8.4/.6);
        drawPlankClose();
    glPopMatrix ();
    glPushMatrix ();
        glTranslatef(0,8.7,0);
        glScalef(1,1,1.4/.6);
        drawPlankClose();
    glPopMatrix ();
    glPushMatrix();
        drawPlankOpen();
    glPopMatrix();
    glPushMatrix ();
        glTranslatef(0.6,4,0);
        glScalef(1,1,6.6/.6);
        drawPlankClose();
    glPopMatrix ();
    glDisable( GL_TEXTURE_2D );
    glEnable( GL_CULL_FACE );
}

void GLWindow::drawTrebuchet(int rotX, int rotY){
    glEnable( GL_TEXTURE_2D );
    glDisable( GL_CULL_FACE );
    glPushMatrix();
        glMatrixMode( GL_MODELVIEW );
        glRotatef(rotY,0,1,0);
        glPushMatrix ();
            glRotatef(90,0,1,0);
            glScalef(1,1,10/.6);
            drawPlankClose();
        glPopMatrix ();

        glPushMatrix ();
            glTranslatef(1.5,0,0);
            drawArmature();
        glPopMatrix ();

        glPushMatrix ();
            glTranslatef(-1.5,0,0);
            glRotatef(-180,0,1,0);
            drawArmature();
        glPopMatrix ();

        glPushMatrix ();
            glTranslatef(-1.2,9,0);
            glRotatef(rotX,1,0,0);
            glRotatef(90,0,1,0);
            glScalef(1,1,2.4);
            drawCylinder();
            glPushMatrix ();
                glTranslatef(3.7,0,.5);
                glRotatef(90,0,1,0);
                glScalef(1,1,17/.6);
                drawPlankClose();
            glPopMatrix ();

            glPushMatrix ();
                glTranslatef(-3.9,-1.1,.5);
                glScalef(3,3,1.5);
                drawPlankClose();
            glPopMatrix ();
        glPopMatrix ();

    glPopMatrix();
    glDisable( GL_TEXTURE_2D );
    glEnable( GL_CULL_FACE );

}


void GLWindow::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0,10,-10,0,10,0,0,1,0);

    //glRotatef(yRot,0,1,0);
    //drawFence();
    //drawTerrain();
    drawTrebuchet(0,yRot);
    //drawPlankClose();
    //drawCylinder();
    //drawArmature();
}
