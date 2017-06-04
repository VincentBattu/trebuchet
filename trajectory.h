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
    int v0y = 1;
    /**
     * Vitesse initiale en z
     * @brief v0z
     */
    int v0z = 1;
    /**
     * Coordonnées initale en x
     * @brief x0
     */
    int x0;
    /**
     * Coordonnées initale en y
     * @brief y0
     */
    int y0;
    /**
     * Coordonnées initale en z
     * @brief z0
     */
    int z0;
    int z;

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
    explicit Trajectory(int x0, int y0, int z0,ProjectileDrawer *projectile,TargetDrawer *target);

    /**
     * Calcul et applique les coordonnées trouvées au projectile
     * @brief drawTrajectory
     */
    void drawTrajectory();
public slots:
    void calculTrajectory();
};


#endif // TRAJECTOTY_H
