#include "trajectory.h"
#include <QDebug>

Trajectory::Trajectory(float x0, float y0, float z0, ProjectileDrawer *projectile, TargetDrawer *target)
{
    this->x0 = x0;
    this->y0 = y0;
    this->z0 = z0;
    this->projectile = projectile;
    this->target = target;
}

void Trajectory::calculTrajectory(){
    float y;

    float xProjectile = projectile->x;
    float yProjectile = projectile->y;
    float zProjectile = projectile->z;

    float xCible = target->x;
    float yCible = target->y;
    float zCible = target->z;
    if(!(zProjectile<=zCible+.2 && zProjectile>=zCible && yProjectile<= yCible +3 && yProjectile>= yCible -3 && xProjectile<= xCible +3 && xProjectile>= xCible -3)){
        y = -(g/2) * (((zProjectile-z0)/v0z)*((zProjectile-z0)/v0z)) + v0y*(zProjectile-z0)/v0z + y0;
        zProjectile+=.2;
        projectile->setCoordinates(xProjectile,y,zProjectile);
        //projectile->drawProjectile();
    }
}

void Trajectory::launchProjectile(int xRot){
    if(xRot!=30){
        xRot+=5;
        qDebug()<<xRot;
        emit rotationChanged(xRot);
    }
    //projectile->setCoordinates(xProjectile,y,zProjectile);
}
