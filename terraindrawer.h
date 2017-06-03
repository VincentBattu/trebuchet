#ifndef TERRAINDRAWER_H
#define TERRAINDRAWER_H

#include <QOpenGLTexture>

/**
 * Classe créant le rendu openGL du terrain.
 */
class TerrainDrawer
{

private:
    /**
     * Stocke la texture utilisée pour le bois
     * @brief textureWood
     */
    QOpenGLTexture *textureWood;
    /**
     * Stocke la texture utilisée pour les barrières
     * @brief textureFence
     */
    QOpenGLTexture *textureFence;
    /**
     * Stocke la texture utilisée pour le sol
     * @brief textureGrass
     */
    QOpenGLTexture *textureGrass;
    /**
     * Stocke la texture utilisée pour le logo TSE
     * @brief textureLogo
     */
    QOpenGLTexture *textureLogo;
public:

    /**
     * Constructeur
     * @brief TerrainDrawer
     */
    explicit TerrainDrawer();

    /**
     * Rendu openGL du sol et positionne les barrières et
     * le logo TSE
     * @brief drawTerrain
     */
    void drawTerrain();
    /**
     * Rendu openGL d'une barrière
     * @brief drawFence
     */
    void drawFence();
    /**
     * Rendu openGL du cylindre utilisé pour les poteaux
     * @brief drawCylinder
     */
    void drawCylinder();

    /**
     * Charge la texture lors du premier appel et
     * fixe cette texture comme texture principale
     * @brief loadAndBindWood
     */
    void loadAndBindWood();
    void loadAndBindFence();
    void loadAndBindGrass();
    void loadAndBindLogo();
};

#endif // TERRAIN_H
