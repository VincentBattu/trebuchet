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
     * @author Vincent
     */
    explicit TerrainDrawer();

    /**
     * Rendu openGL du sol et positionne les barrières et
     * le logo TSE
     * @brief drawTerrain
     * @author Vincent
     */
    void drawTerrain();
    /**
     * Rendu openGL d'une barrière
     * @brief drawFence
     * @author Vincent
     */
    void drawFence();
    /**
     * Rendu openGL du cylindre utilisé pour les poteaux
     * @brief drawCylinder
     * @author Vincent
     */
    void drawCylinder();

    /**
     * Charge la texture lors du premier appel et
     * fixe cette texture comme texture principale
     * @brief loadAndBindWood
     * @author Vincent
     */
    void loadAndBindWood();
    void loadAndBindFence();
    void loadAndBindGrass();
    void loadAndBindLogo();
};

#endif // TERRAIN_H
