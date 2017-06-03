#ifndef TREBUCHETDRAWER_H
#define TREBUCHETDRAWER_H

#include <QOpenGLTexture>

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
     * Constructeur
     * @brief TrebuchetDrawer
     */
    explicit TrebuchetDrawer();

    /**
     * Rendu openGL du trébuchet avec en paramètre
     * les rotations horizontale et verticale voulues
     * @brief drawTrebuchet
     * @param rotX
     * @param rotY
     */
    void drawTrebuchet(int rotX, int rotY);
    /**
     * Rendu openGL des planches coupées droites utilisées
     * @brief drawPlankClose
     */
    void drawPlankClose();
    /**
     * Rendu openGL des planches coupées de biais utilisées
     * @brief drawPlankOpen
     */
    void drawPlankOpen();
    /**
     * Rendu openGL du cylindre utilisées
     * @brief drawCylinder
     */
    void drawCylinder();
    /**
     * Rendu openGL de la structure en bois utilisée pour
     * l'armature
     * @brief drawArmature
     */
    void drawArmature();

    /**
     * Charge la texture lors du premier appel et
     * fixe cette texture comme texture principale
     * @brief loadAndBindWood
     */
    void loadAndBindWood();
};

#endif // TREBUCHETDRAWER_H
