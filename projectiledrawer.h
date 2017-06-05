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
     * @author Delphine
     */
    explicit ProjectileDrawer();

    /**
     * Rendu openGL du projectile
     * @brief drawProjectile
     * @author Delphine
     */
    void drawProjectile();
    /**
     * Fixe les coordonnées du projectile
     * @brief setCoordinates
     * @author Delphine
     */
    void setCoordinates(float x, float y, float z);

    /**
     * Charge la texture lors du premier appel et
     * fixe cette texture comme texture principale
     * @brief loadAndBindRock
     * @author Delphine
     */
    void loadAndBindRock();
};

#endif // PROJECTILEDRAWER_H
