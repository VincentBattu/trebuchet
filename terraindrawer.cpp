#include "terraindrawer.h"
#include <GL/glu.h>
#include <QOpenGLTexture>

TerrainDrawer::TerrainDrawer()
{
    textureWood = NULL;
    textureFence = NULL;
    textureGrass = NULL;
    textureLogo = NULL;
}


void TerrainDrawer::loadAndBindWood(){
    if(textureWood == NULL){
        textureWood = new QOpenGLTexture(QImage(":/textures/wood.png").mirrored());
        textureWood->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
        textureWood->setMagnificationFilter(QOpenGLTexture::Linear);
    }
    textureWood->bind();
}
void TerrainDrawer::loadAndBindFence(){
    if(textureFence == NULL){
        textureFence = new QOpenGLTexture(QImage(":/textures/fence.png").mirrored());
        textureFence->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
        textureFence->setMagnificationFilter(QOpenGLTexture::Linear);
    }
    textureFence->bind();
}
void TerrainDrawer::loadAndBindGrass(){
    if(textureGrass == NULL){
        textureGrass = new QOpenGLTexture(QImage(":/textures/grass.jpg").mirrored());
        textureGrass->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
        textureGrass->setMagnificationFilter(QOpenGLTexture::Linear);
    }
    textureGrass->bind();
}
void TerrainDrawer::loadAndBindLogo(){
    if(textureLogo == NULL){
        textureLogo = new QOpenGLTexture(QImage(":/textures/logo").mirrored());
        textureLogo->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
        textureLogo->setMagnificationFilter(QOpenGLTexture::Linear);
    }
    textureLogo->bind();
}


void TerrainDrawer::drawTerrain(){
    loadAndBindGrass();
    glColor3ub(255,255,255);
    int step=10;
    int step2=16;
    int step3=14;
    glEnable( GL_TEXTURE_2D );
    glDisable( GL_CULL_FACE );
    for (int i =-200; i <=200-step; i+=step){
        for (int j =-100; j <=150-step; j+=step){
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
    int tag=0;
    for (int i =-110; i <=110; i+=step2){
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
        if(tag==0){
            loadAndBindLogo();
            glPushMatrix();
                glColor3f(1,1,1);
                glEnable( GL_TEXTURE_2D );
                glEnable( GL_BLEND );
                glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
                glDisable( GL_CULL_FACE );
                glColor3f(1,1,1);
                glTranslatef(-49,0,i);
                glRotatef(90,0,0,1);
                glRotatef(90,0,1,0);
                glBegin(GL_QUADS);
                    glTexCoord2d(0,0);
                    glVertex3d(-7,0,0);
                    glTexCoord2d(0,1);
                    glVertex3d(-7,0,8);
                    glTexCoord2d(1,1);
                    glVertex3d(8,0,8);
                    glTexCoord2d(1,0);
                    glVertex3d(8,0,0);
                glEnd();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(49,0,i);
                glRotatef(90,0,0,1);
                glRotatef(90,0,1,0);
                glBegin(GL_QUADS);
                    glTexCoord2d(1,0);
                    glVertex3d(-7,0,0);
                    glTexCoord2d(0,0);
                    glVertex3d(8,0,0);
                    glTexCoord2d(0,1);
                    glVertex3d(8,0,8);
                    glTexCoord2d(1,1);
                    glVertex3d(-7,0,8);
                glEnd();
            glPopMatrix();
            glDisable( GL_TEXTURE_2D );
            glDisable( GL_BLEND );
            glEnable( GL_CULL_FACE );

            tag=1;
        }else{
            tag=0;
        }
    }
    tag=0;
    for (int j =-42; j <=54; j+=step3){
        glPushMatrix();
            glTranslatef(j,0,106);
            glScalef(2,1,1);
            drawFence();
        glPopMatrix();
        if(tag==0){
            loadAndBindLogo();
            glPushMatrix();
                glColor3f(1,1,1);
                glEnable( GL_TEXTURE_2D );
                glEnable( GL_BLEND );
                glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
                glDisable( GL_CULL_FACE );
                glColor3f(1,1,1);
                glTranslatef(j,0,105);
                glRotatef(90,0,0,1);
                glRotatef(90,1,0,0);
                glRotatef(90,0,1,0);
                glBegin(GL_QUADS);
                    glTexCoord2d(0,0);
                    glVertex3d(-7,0,0);
                    glTexCoord2d(0,1);
                    glVertex3d(-7,0,8);
                    glTexCoord2d(1,1);
                    glVertex3d(5,0,8);
                    glTexCoord2d(1,0);
                    glVertex3d(5,0,0);
                glEnd();
            glPopMatrix();
            glDisable( GL_TEXTURE_2D );
            glDisable( GL_BLEND );
            glEnable( GL_CULL_FACE );
            tag=1;
        }else{
            tag=0;
        }

    }
}

void TerrainDrawer::drawFence(){
    int width = 8;
    int height = 8;
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
    loadAndBindFence();
    glPushMatrix();
        glEnable( GL_TEXTURE_2D );
        glEnable( GL_BLEND );
        glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
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
        glDisable( GL_BLEND );
        glEnable( GL_CULL_FACE );
    glPopMatrix();    
}


void TerrainDrawer::drawCylinder(){

    glEnable( GL_TEXTURE_2D );
    glDisable( GL_CULL_FACE );
    loadAndBindWood();
    glPushMatrix();
        glMatrixMode( GL_MODELVIEW );
        glEnable(GL_TEXTURE_GEN_S);
        glEnable(GL_TEXTURE_GEN_T);
        gluQuadricTexture(gluNewQuadric(),GL_TRUE);
        gluCylinder(gluNewQuadric(),.5,.5,1,15,15);
        gluDisk(gluNewQuadric(),0,.5,15,1);
        glDisable(GL_TEXTURE_GEN_S);
        glDisable(GL_TEXTURE_GEN_T);
    glPopMatrix();
    glDisable( GL_TEXTURE_2D );
    glEnable( GL_CULL_FACE );

}
