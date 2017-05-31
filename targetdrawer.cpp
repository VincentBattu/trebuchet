#include "targetdrawer.h"
#include <GL/glu.h>
#include <QOpenGLTexture>

TargetDrawer::TargetDrawer()
{
    textureTarget = NULL;
}

void TargetDrawer::drawTarget(int x, int y, int z){
    glPushMatrix();
        glTranslatef(x,y,z);
        glPushMatrix();
            glScalef(4,4,.2);
            drawCylinder();
        glPopMatrix();
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
        glEnable(GL_CLAMP_TO_BORDER);
        glEnable(GL_CLAMP_TO_EDGE);
        glDisable(GL_REPEAT);
        gluDisk(gluNewQuadric(),0,.5,5,1);
        glPushMatrix();
            glTranslatef(0,0,1);
            gluDisk(gluNewQuadric(),0,.5,10,10);
        glPopMatrix();
        glDisable(GL_TEXTURE_GEN_S);
        glDisable(GL_TEXTURE_GEN_T);
        glDisable(GL_CLAMP_TO_BORDER);
        glDisable(GL_CLAMP_TO_EDGE);
        glEnable(GL_REPEAT);
    glPopMatrix();
    glDisable( GL_TEXTURE_2D );
    glEnable( GL_CULL_FACE );

}

void TargetDrawer::loadAndBlindTarget(){
    if(textureTarget == NULL){
        textureTarget = new QOpenGLTexture(QImage(":/textures/cible.png").mirrored());
        textureTarget->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
        textureTarget->setMagnificationFilter(QOpenGLTexture::Linear);
    }
    textureTarget->bind();
}
