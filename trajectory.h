#ifndef TRAJECTOTY_H
#define TRAJECTOTY_H

#include "projectiledrawer.h"
#include "targetdrawer.h"

/**
 * Classe gérant la trajectoire du projectile
 */
class Trajectory : public QObject
{
    Q_OBJECT

private:
    /**
     * Accélération de la pesanteur
     * @brief g
     */
    float const g = 9.81;
    /**
     * Vitesse initiale en y
     * @brief v0y
     */
    float v0y ;
    /**
     * Vitesse initiale en z
     * @brief v0z
     */
    float v0z;
    /**
     * Coordonnées initale en x
     * @brief x0
     */
    float x0;
    /**
     * Coordonnées initale en y
     * @brief y0
     */
    float y0;
    /**
     * Coordonnées initale en z
     * @brief z0
     */
    float z0;


    /**
     * Cible que doit toucher le projectile
     * @brief target
     */
    TargetDrawer *target;


    /**
     * Booléan pour savoir si les positions initiales du projectile ont déjà
     * été stockées pour le calcul de la trajectoire.
     * @brief firstTime
     */
    bool firstTime;
    /**
     * Booléan pour savoir si la méthode launchProjectile à déjà était appelée.
     * @brief firstCall
     */
    bool firstCall;
    /**
     * Angle par rapport à l'axe X par l'utilisateur avant lancé.
     * @brief rotX
     */
    int rotX;

public:
    /**
     * Projectile qui suit cette trajectoire
     * @brief projectile
     */
    ProjectileDrawer *projectile;

    /**
     * Constructeur
     * @brief Trajectory
     * @author Delphine
     */
    explicit Trajectory(float x0, float y0, float z0,ProjectileDrawer *projectile,TargetDrawer *target);

    /**
     * Calcul et applique les coordonnées trouvées au projectile
     * @brief calculTrajectory
     * @authors Vincent|Delphine
     */
    void calculTrajectory();
    /**
     * Modifie l'angle de rotation selon x pour une partie de la trajectoire
     * puis initialise x0, y0 et z0 et appel calculTrajectory().
     * @brief launchProjectile
     * @author Delphine
     */
    void launchProjectile(int *xRot);

signals:
    /**
     * Signal qu'il faut bouger le trébuchet.
     * @brief rotationChanged
     * @param angle
     */
    void rotationChanged(int angle);
    /**
     * Signal qu'il faut réinitialiser la scène
     * brief restart
     */
    void restart();
};


#endif // TRAJECTOTY_H
