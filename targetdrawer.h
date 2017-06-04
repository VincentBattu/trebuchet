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
     * Coordonnées z de la cible
     * @brief z
     */
    int z;

    /**
     * Constructeur
     * @brief TargetDrawer
     */
    explicit TargetDrawer();

    /**
     * Rendu openGL de la cible aux coordonnées données
     * @brief drawTarget
     * @param x
     * @param y
     * @param z
     */
    void drawTarget(int x, int y, int z);
    /**
     * Rendu openGL du cylindre utilisé
     * @brief drawCylinder
     */
    void drawCylinder();

    /**
     * Charge la texture lors du premier appel et
     * fixe cette texture comme texture principale
     * @brief loadAndBindTarget
     */
    void loadAndBindTarget();
};

#endif // TARGETDRAWER_H
