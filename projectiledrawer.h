#ifndef PROJECTILEDRAWER_H
#define PROJECTILEDRAWER_H

#include <QOpenGLTexture>

/**
 * Classe créant le rendu openGL du terrain.
 */
class ProjectileDrawer
{

private:

    /**
     * Stocke la texture de pierre utilisée
     * @brief textureRock
     */
    QOpenGLTexture *textureRock;
public:
    /**
     * Coordonnées du projectile
     * @brief x,y,z
     */
    float x,y,z;
    /**
     * Constructeur
     * @brief ProjectileDrawer
     */
    explicit ProjectileDrawer();

    /**
     * Rendu openGL du projectile
     * @brief drawProjectile
     */
    void drawProjectile(int xRot,int yRot);
    /**
     * Rendu openGL du projectile
     * @brief drawProjectile
     */
    void drawProjectile();
    /**
     * Fixe les coordonnées du projectile
     * @brief setCoordinates
     */
    void setCoordinates(float x, float y, float z);

    /**
     * Charge la texture lors du premier appel et
     * fixe cette texture comme texture principale
     * @brief loadAndBindRock
     */
    void loadAndBindRock();
};

#endif // PROJECTILEDRAWER_H
