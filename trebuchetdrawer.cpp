#include "trebuchetdrawer.h"
#include <GL/glu.h>
#include <QOpenGLTexture>

TrebuchetDrawer::TrebuchetDrawer()
{
    textureWood = NULL;
    projectile = new ProjectileDrawer();
}


void TrebuchetDrawer::loadAndBindWood(){
    if(textureWood == NULL){
        textureWood = new QOpenGLTexture(QImage(":/textures/wood.png").mirrored());
        textureWood->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
        textureWood->setMagnificationFilter(QOpenGLTexture::Linear);
    }
    textureWood->bind();
}

void TrebuchetDrawer::drawPlankClose(){

    glEnable( GL_TEXTURE_2D );
    glDisable( GL_CULL_FACE );
    loadAndBindWood();
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

void TrebuchetDrawer::drawPlankOpen(){
    glEnable( GL_TEXTURE_2D );
    glDisable( GL_CULL_FACE );
    loadAndBindWood();
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
void TrebuchetDrawer::drawCylinder(){

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

void TrebuchetDrawer::drawArmature(){
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

void TrebuchetDrawer::drawTrebuchetProjectile(int rotX, int rotY){
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
            glPushMatrix ();
                glMatrixMode( GL_MODELVIEW );
                glTranslatef(0,0,0);
                glRotatef(-90,0,1,0);
                //glTranslatef(12,.2,.5);
                //glScalef(.4,.4,.4);
                projectile->drawProjectile(rotX,rotY);
            glPopMatrix ();
        glPopMatrix ();

    glPopMatrix();
    glDisable( GL_TEXTURE_2D );
    glEnable( GL_CULL_FACE );
}

void TrebuchetDrawer::drawTrebuchet(int rotX, int rotY){
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
