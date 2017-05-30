#include "targetdrawer.h"
#include <GL/glu.h>
#include <QOpenGLTexture>

TargetDrawer::TargetDrawer()
{
    textureWood = NULL;
    textureTarget = NULL;
}

void TargetDrawer::drawTarget(){
    glPushMatrix();
        glScalef(4,4,.2);
        drawCylinder();
    glPopMatrix();

}

void TargetDrawer::drawCylinder(){

    glEnable( GL_TEXTURE_2D );
    glDisable( GL_CULL_FACE );
    glPushMatrix();
        glMatrixMode( GL_MODELVIEW );
        glColor3f(0,0,0);
        gluCylinder(gluNewQuadric(),.5,.5,1,15,15);
        loadAndBlindTarget();
        glColor3f(1,1,1);
        glEnable(GL_TEXTURE_GEN_S);
        glEnable(GL_TEXTURE_GEN_T);
        gluQuadricTexture(gluNewQuadric(),GL_TRUE);
        /*glEnable(GL_CLAMP_TO_BORDER);
        glEnable(GL_CLAMP_TO_EDGE);
        glDisable(GL_REPEAT);*/
        gluDisk(gluNewQuadric(),0,.5,15,1);
        glPushMatrix();
            glTranslatef(0,0,1);
            gluDisk(gluNewQuadric(),0,.5,15,1);
        glPopMatrix();
        glDisable(GL_TEXTURE_GEN_S);
        glDisable(GL_TEXTURE_GEN_T);
        /*glDisable(GL_CLAMP_TO_BORDER);
        glDisable(GL_CLAMP_TO_EDGE);
        glEnable(GL_REPEAT);*/
    glPopMatrix();
    glDisable( GL_TEXTURE_2D );
    glEnable( GL_CULL_FACE );

}


void TargetDrawer::loadAndBlindWood(){
    if(textureWood == NULL){
        textureWood = new QOpenGLTexture(QImage(":/textures/wood.png").mirrored());
        textureWood->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
        textureWood->setMagnificationFilter(QOpenGLTexture::Linear);
    }
    textureWood->bind();
}

void TargetDrawer::loadAndBlindTarget(){
    if(textureTarget == NULL){
        textureTarget = new QOpenGLTexture(QImage(":/textures/cible.png").mirrored());
        textureTarget->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
        textureTarget->setMagnificationFilter(QOpenGLTexture::Linear);
    }
    textureTarget->bind();
}
