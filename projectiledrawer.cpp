#include "projectiledrawer.h"
#include <GL/glu.h>
#include <QOpenGLTexture>

ProjectileDrawer::ProjectileDrawer()
{
    textureRock = NULL;
}

void ProjectileDrawer::loadAndBindRock(){
    if(textureRock == NULL){
        textureRock = new QOpenGLTexture(QImage(":/textures/rock").mirrored());
        textureRock->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
        textureRock->setMagnificationFilter(QOpenGLTexture::Linear);
    }
    textureRock->bind();
}

void ProjectileDrawer::drawProjectile(){
    glEnable( GL_TEXTURE_2D );
    glDisable( GL_CULL_FACE );
    loadAndBindRock();
    glPushMatrix();
        glColor3f(1,1,1);
        glEnable(GL_TEXTURE_GEN_S);
        glEnable(GL_TEXTURE_GEN_T);
        gluQuadricTexture(gluNewQuadric(),GL_TRUE);
        gluSphere(gluNewQuadric(),2,10,10);
        glDisable(GL_TEXTURE_GEN_S);
        glDisable(GL_TEXTURE_GEN_T);
    glPopMatrix();
    glDisable( GL_TEXTURE_2D );
    glEnable( GL_CULL_FACE );
}
