#ifndef TERRAINDRAWER_H
#define TERRAINDRAWER_H

#include <QOpenGLTexture>

class TerrainDrawer
{

private:
    QOpenGLTexture *textureWood;
    QOpenGLTexture *textureFence;
    QOpenGLTexture *textureGrass;
    QOpenGLTexture *textureLogo;
public:

    explicit TerrainDrawer();

    void drawTerrain();
    void drawFence();
    void drawCylinder();

    void loadAndBlindWood();
    void loadAndBlindFence();
    void loadAndBlindGrass();
    void loadAndBlindLogo();
};

#endif // TERRAIN_H
