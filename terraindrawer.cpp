#include "terraindrawer.h"
#include <GL/glu.h>
#include <QOpenGLTexture>

TerrainDrawer::TerrainDrawer()
{
    textureWood = NULL;
    textureFence = NULL;
    textureGrass = NULL;
}


void TerrainDrawer::loadAndBlindWood(){
    if(textureWood == NULL){
        textureWood = new QOpenGLTexture(QImage(":/textures/wood.png").mirrored());
        textureWood->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
        textureWood->setMagnificationFilter(QOpenGLTexture::Linear);
    }
    textureWood->bind();
}
void TerrainDrawer::loadAndBlindFence(){
    if(textureFence == NULL){
        textureFence = new QOpenGLTexture(QImage(":/textures/fence.png").mirrored());
        textureFence->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
        textureFence->setMagnificationFilter(QOpenGLTexture::Linear);
    }
    textureFence->bind();
}
void TerrainDrawer::loadAndBlindGrass(){
    if(textureGrass == NULL){
        textureGrass = new QOpenGLTexture(QImage(":/textures/grass.jpg").mirrored());
        textureGrass->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
        textureGrass->setMagnificationFilter(QOpenGLTexture::Linear);
    }
    textureGrass->bind();
}


void TerrainDrawer::drawTerrain(){
    loadAndBlindGrass();
    glColor3ub(255,255,255);
    int step=10;
    int step2=16;
    int step3=14;
    glEnable( GL_TEXTURE_2D );
    glDisable( GL_CULL_FACE );
    for (int i =-200; i <=200-step; i+=step){
        for (int j =-100; j <=100-step; j+=step){
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
    glDisable( GL_TEXTURE_2D );
    glEnable( GL_CULL_FACE );
    for (int i =-50; i <=50; i+=step2){
        glPushMatrix();
            glTranslatef(-50,0,i);
            glRotatef(-90,0,1,0);
            glScalef(2,1,1);
            drawFence();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(50,0,i);
            glRotatef(90,0,1,0);
            glScalef(2,1,1);
            drawFence();
        glPopMatrix();
    }
    for (int j =-42; j <=54; j+=step3){
        glPushMatrix();
            glTranslatef(j,0,54);
            glScalef(2,1,1);
            drawFence();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(j,0,-50);
            glScalef(2,1,1);
            drawFence();
        glPopMatrix();
    }
}

void TerrainDrawer::drawFence(){
    int width = 8;
    int height = 4;
    loadAndBlindFence();
    glPushMatrix();
        glEnable( GL_TEXTURE_2D );
        glDisable( GL_CULL_FACE );
        glColor3f(1,1,1);
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
        glBegin(GL_LINES);
            glColor3f(.5,.5,.5);
            glVertex3d(width/2,height,0);
            glVertex3d(-width/2,height,0);
            glColor3f(1,1,1);
        glEnd();
    glPopMatrix();
    glPushMatrix();
        glColor3f(.5,.5,.5);
        glTranslatef(width/2,0,0);
        glRotatef(-90,1,0,0);
        glScalef(.5,.5,height);
        drawCylinder();
        glColor3f(1,1,1);
    glPopMatrix();
}


void TerrainDrawer::drawCylinder(){

    glEnable( GL_TEXTURE_2D );
    glDisable( GL_CULL_FACE );
    loadAndBlindWood();
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
