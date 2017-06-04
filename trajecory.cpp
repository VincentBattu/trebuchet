#include "trajectory.h"

Trajectory::Trajectory(int x0, int y0, int z0, ProjectileDrawer *projectile, TargetDrawer *target)
{
    this->x0 = x0;
    this->y0 = y0;
    this->z0 = z0;
    this->projectile = projectile;
    this->target = target;
    z=z0;
}

void Trajectory::calculTrajectory(){
    int y;

    int zMax = target->z;
    if(z<=zMax){
        y = -(g/2) * (((z-z0)/v0z)^2) + v0y*(z-z0)/v0z + y0;
        projectile->setCoordinates(x0,y,z);
        //projectile->drawProjectile();
        z++;
    }
}

/*void Trajectory::drawTrajectory(){
    int y;

    int zMax = target->z;
    if(z<=zMax){
        y = -(g/2) * (((z-z0)/v0z)^2) + v0y*(z-z0)/v0z + y0;
        projectile->setCoordinates(x0,y,z);
        //projectile->drawProjectile();
        z++;
    }
}*/
