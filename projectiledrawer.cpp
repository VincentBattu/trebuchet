#include "projectiledrawer.h"
#include <GL/glu.h>
#include <QOpenGLTexture>

ProjectileDrawer::ProjectileDrawer()
{
    textureRock = NULL;
    /*x=0;
    y=-.2;
    z=1.9;*/
    x=0;
    y=0;
    z=-12;
}

void ProjectileDrawer::loadAndBindRock(){
    if(textureRock == NULL){
        textureRock = new QOpenGLTexture(QImage(":/textures/rock").mirrored());
        textureRock->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
        textureRock->setMagnificationFilter(QOpenGLTexture::Linear);
    }
    textureRock->bind();
}

void ProjectileDrawer::drawProjectile(int xRot, int yRot){
    glEnable( GL_TEXTURE_2D );
    glDisable( GL_CULL_FACE );
    loadAndBindRock();
    /*glTranslatef(0,0,0);
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glPushMatrix();*/
        glTranslatef(x,y,z);
        glRotatef(xRot,1,0,0);
        glRotatef(yRot,0,1,0);
        glScalef(.4,.4,.4);
        glColor3f(1,1,1);
        glEnable(GL_TEXTURE_GEN_S);
        glEnable(GL_TEXTURE_GEN_T);
        gluQuadricTexture(gluNewQuadric(),GL_TRUE);
        glDisable(GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        gluSphere(gluNewQuadric(),2,100,100);
        glDisable(GL_TEXTURE_GEN_S);
        glDisable(GL_TEXTURE_GEN_T);
        glEnable(GL_REPEAT);
    glPopMatrix();
    glDisable( GL_TEXTURE_2D );
    glEnable( GL_CULL_FACE );
    //glGetFloatv(GL_MODELVIEW_MATRIX, parray)
}
void ProjectileDrawer::drawProjectile(){
    glEnable( GL_TEXTURE_2D );
    glDisable( GL_CULL_FACE );
    loadAndBindRock();
    glPushMatrix();
        glTranslatef(x,y,z);
        glScalef(.4,.4,.4);
        glColor3f(1,1,1);
        glEnable(GL_TEXTURE_GEN_S);
        glEnable(GL_TEXTURE_GEN_T);
        gluQuadricTexture(gluNewQuadric(),GL_TRUE);
        glDisable(GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        gluSphere(gluNewQuadric(),2,100,100);
        glDisable(GL_TEXTURE_GEN_S);
        glDisable(GL_TEXTURE_GEN_T);
        glEnable(GL_REPEAT);
    glPopMatrix();
    glDisable( GL_TEXTURE_2D );
    glEnable( GL_CULL_FACE );
    //glGetFloatv(GL_MODELVIEW_MATRIX, parray)
}

void ProjectileDrawer::setCoordinates(float x, float y, float z){
    this->x = x;
    this->y = y;
    this->z = z;
}
