#include "targetdrawer.h"
#include <GL/glu.h>
#include <QOpenGLTexture>

TargetDrawer::TargetDrawer()
{
    textureTarget = NULL;
    x=0;
    y=0;
    z=0;
}

void TargetDrawer::drawTarget(int x, int y, float z){
    this->x = x;
    this->y = y;
    this->z = z;
    glPushMatrix();
        glTranslatef(x,y,z);
        glScalef(6,6,.2);
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
        glColor3f(1,1,1);
        loadAndBindTarget();
        glEnable( GL_TEXTURE_2D );
        glEnable( GL_BLEND );
        glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
        glDisable( GL_CULL_FACE );
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
            glTexCoord2d(0,0);
            glVertex3d(-.5,.5,0);
            glTexCoord2d(0,1);
            glVertex3d(-.5,-.5,0);
            glTexCoord2d(1,1);
            glVertex3d(.5,-.5,0);
            glTexCoord2d(1,0);
            glVertex3d(.5,.5,0);
        glEnd();
        glPushMatrix();
            glTranslatef(0,0,1);
            glEnable( GL_TEXTURE_2D );
            glEnable( GL_BLEND );
            glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
            glDisable( GL_CULL_FACE );
            glColor3f(1,1,1);
            glBegin(GL_QUADS);
                glTexCoord2d(0,0);
                glVertex3d(-.5,.5,0);
                glTexCoord2d(0,1);
                glVertex3d(-.5,-.5,0);
                glTexCoord2d(1,1);
                glVertex3d(.5,-.5,0);
                glTexCoord2d(1,0);
                glVertex3d(.5,.5,0);
            glEnd();
            glDisable( GL_TEXTURE_2D );
            glDisable( GL_BLEND );
            glEnable( GL_CULL_FACE );
        glPopMatrix();
    glPopMatrix();
    glDisable( GL_TEXTURE_2D );
    glEnable( GL_CULL_FACE );

}

void TargetDrawer::loadAndBindTarget(){
    if(textureTarget == NULL){
        textureTarget = new QOpenGLTexture(QImage(":/textures/cible.png").mirrored());
        textureTarget->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
        textureTarget->setMagnificationFilter(QOpenGLTexture::Linear);
    }
    textureTarget->bind();
}
