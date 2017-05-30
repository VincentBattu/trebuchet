#ifndef TREBUCHETDRAWER_H
#define TREBUCHETDRAWER_H

#include <QOpenGLTexture>

class TrebuchetDrawer
{

private:
    QOpenGLTexture *textureWood;
public:

    explicit TrebuchetDrawer();

    void drawTrebuchet(int rotX, int rotY);
    void drawPlankClose();
    void drawPlankOpen();
    void drawCylinder();
    void drawArmature();

    void loadAndBlindWood();
};

#endif // TREBUCHETDRAWER_H
