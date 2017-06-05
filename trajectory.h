#ifndef TRAJECTOTY_H
#define TRAJECTOTY_H

#include "projectiledrawer.h"
#include "targetdrawer.h"

/**
 * Classe gérant la trajectoire du projectile
 */
class Trajectory
{

private:
    /**
     * Accélération de la pesanteur
     * @brief g
     */
    int const g = 9.81;
    /**
     * Vitesse initiale en y
     * @brief v0y
     */
    float v0y = 10;
    /**
     * Vitesse initiale en z
     * @brief v0z
     */
    float v0z = 30;
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
     * Projectile qui suit cette trajectoire
     * @brief projectile
     */
    ProjectileDrawer *projectile;
    /**
     * Cible que doit toucher le projectile
     * @brief target
     */
    TargetDrawer *target;

public:

    /**
     * Constructeur
     * @brief Trajectory
     */
    explicit Trajectory(float x0, float y0, float z0,ProjectileDrawer *projectile,TargetDrawer *target);

    /**
     * Calcul et applique les coordonnées trouvées au projectile
     * @brief drawTrajectory
     */
    //void drawTrajectory();
    void calculTrajectory();
};


#endif // TRAJECTOTY_H
