#ifndef TREBUCHETDRAWER_H
#define TREBUCHETDRAWER_H

#include <QOpenGLTexture>
#include "projectiledrawer.h"

/**
 * Classe créant le rendu openGL du trébuchet.
 */
class TrebuchetDrawer
{

private:
    /**
     * Stocke la texture utilisée pour le bois
     * @brief textureWood
     */
    QOpenGLTexture *textureWood;

public:
    /**
     * Classe pour le rendu openGL du projectile
     * @brief projectile
     */
    ProjectileDrawer *projectile;
    /**
     * Constructeur
     * @brief TrebuchetDrawer
     * @author Delphine
     */
    explicit TrebuchetDrawer();

    /**
     * Rendu openGL du trébuchet avec le projectile, avec en paramètre
     * les rotations horizontale et verticale voulues
     * @brief drawTrebuchetProjectile
     * @param rotX
     * @param rotY
     * @author Delphine
     */
    void drawTrebuchetProjectile(int rotX, int rotY);
    /**
     * Rendu openGL des planches coupées droites utilisées
     * @brief drawPlankClose
     * @author Delphine
     */
    void drawPlankClose();
    /**
     * Rendu openGL des planches coupées de biais utilisées
     * @brief drawPlankOpen
     * @author Delphine
     */
    void drawPlankOpen();
    /**
     * Rendu openGL du cylindre utilisées
     * @brief drawCylinder
     * @author Delphine
     */
    void drawCylinder();
    /**
     * Rendu openGL de la structure en bois utilisée pour
     * l'armature
     * @brief drawArmature
     * @author Delphine
     */
    void drawArmature();

    /**
     * Charge la texture lors du premier appel et
     * fixe cette texture comme texture principale
     * @brief loadAndBindWood
     * @author Delphine
     */
    void loadAndBindWood();
};

#endif // TREBUCHETDRAWER_H
