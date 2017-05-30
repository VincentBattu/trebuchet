#ifndef TERRAINDRAWER_H
#define TERRAINDRAWER_H

#include <QOpenGLTexture>

class TerrainDrawer
{

private:
    QOpenGLTexture *textureWood;
    QOpenGLTexture *textureFence;
    QOpenGLTexture *textureGrass;
public:

    explicit TerrainDrawer();

    void drawTerrain();
    void drawFence();
    void drawCylinder();

    void loadAndBlindWood();
    void loadAndBlindFence();
    void loadAndBlindGrass();
};

#endif // TERRAIN_H
