#ifndef TARGETDRAWER_H
#define TARGETDRAWER_H

#include <QOpenGLTexture>

class TargetDrawer
{

private:
    QOpenGLTexture *textureWood;
    QOpenGLTexture *textureTarget;
public:

    explicit TargetDrawer();

    void drawTarget();
    void drawCylinder();

    void loadAndBlindWood();
    void loadAndBlindTarget();
};

#endif // TARGETDRAWER_H
