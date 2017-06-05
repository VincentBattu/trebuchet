#ifndef TARGETDRAWER_H
#define TARGETDRAWER_H

#include <QOpenGLTexture>

/**
 * Classe créant le rendu openGL de la cible.
 */
class TargetDrawer
{

private:
    /**
     * Stocke la texture utilisée pour la cible
     * @brief textureTarget
     */
    QOpenGLTexture *textureTarget;
public:
    /**
     * Coordonnée x de la cible
     * @brief x
     */
    float x;
    /**
     * Coordonnée y de la cible
     * @brief y
     */
    float y;
    /**
     * Coordonnée z de la cible
     * @brief z
     */
    float z;

    /**
     * Constructeur
     * @brief TargetDrawer
     * @author Delphine
     */
    explicit TargetDrawer();

    /**
     * Rendu openGL de la cible aux coordonnées données
     * @brief drawTarget
     * @param x
     * @param y
     * @param z
     * @author Delphine
     */
    void drawTarget(int x, int y, float z);
    /**
     * Rendu openGL du cylindre utilisé
     * @brief drawCylinder
     * @author Delphine
     */
    void drawCylinder();

    /**
     * Charge la texture lors du premier appel et
     * fixe cette texture comme texture principale
     * @brief loadAndBindTarget
     * @author Delphine
     */
    void loadAndBindTarget();
};

#endif // TARGETDRAWER_H
