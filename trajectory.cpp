#include "trajectory.h"
#include <QDebug>*
#include <cmath>

#define PI 3.14159265

Trajectory::Trajectory(float x0, float y0, float z0, ProjectileDrawer *projectile, TargetDrawer *target)
{
    this->x0 = x0;
    this->y0 = y0;
    this->z0 = z0;
    this->projectile = projectile;
    this->target = target;
    firstTime = true;
    firstCall = true;
}

void Trajectory::calculTrajectory(){
    float y;

    float xProjectile = projectile->x;
    float yProjectile = projectile->y;
    float zProjectile = projectile->z;

    float xCible = target->x;
    float yCible = target->y;
    float zCible = target->z;
    // Si on est dans la cible
    float rayonCible = 50;
    if(zProjectile<=zCible+.2 && zProjectile>=zCible && yProjectile<= yCible +rayonCible && yProjectile>= yCible -rayonCible && xProjectile<= xCible +rayonCible && xProjectile>= xCible -rayonCible){
        int score = 0;

        qDebug()<<"x"<< abs(xProjectile-xCible)<<endl;
        qDebug()<<"y"<< abs(yProjectile-yCible)<<endl;

        float interval = rayonCible/10;
        /*
        if (abs(yProjectile-yCible)<=interval && abs(xProjectile-xCible<=interval)){
            score = 10;
        } else if (abs(yProjectile-yCible-2*interval)<=0.3 && abs(yProjectile-yCible-2*interval)<=0.3){
            score = 9;
        }else if (abs(yProjectile-yCible-3*interval)<=0.3 && abs(yProjectile-yCible-3*interval)<=0.9){
            score = 8;
        }else if (abs(yProjectile-yCible-4*interval)<=0.3 && abs(yProjectile-yCible-4*interval)<=0.3){
            score = 7;
        }else if (abs(yProjectile-yCible-5*interval)<=0.3 && abs(yProjectile-yCible-5*interval)<=0.3){
            score = 6;
        }else if (abs(yProjectile-yCible-6*interval)<=0.3 && abs(yProjectile-yCible-6*interval)<=0.3){
            score = 5;
        }else if (abs(yProjectile-yCible-7*interval)<=0.3 && abs(yProjectile-yCible-7*interval)<=0.3){
            score =4;
        }else if (abs(yProjectile-yCible-8*interval)<=0.3 && abs(yProjectile-yCible-8*interval)<=0.3){
            score = 3;
        }else if (abs(yProjectile-yCible-9*interval)<=0.3 && abs(yProjectile-yCible-9*interval)<=0.3){
            score = 2;
        }else if (abs(yProjectile-yCible-10*interval)<=0.3 && abs(yProjectile-yCible-10*interval)<=0.3){
            score = 1;
        }
        qDebug()<<"score"<< score<<endl;*/


        if ((pow(yProjectile-yCible,2)+pow(xProjectile-xCible,2))<=pow(interval,2)){
            score=10;
        } else if ((pow(yProjectile-yCible,2)+pow(xProjectile-xCible,2))<=pow(2*interval,2)){
            score=9;
        } else if ((pow(yProjectile-yCible,2)+pow(xProjectile-xCible,2))<=pow(3*interval,2)){
            score=8;
        } else if ((pow(yProjectile-yCible,2)+pow(xProjectile-xCible,2))<=pow(4*interval,2)){
            score=7;
        } else if ((pow(yProjectile-yCible,2)+pow(xProjectile-xCible,2))<=pow(5*interval,2)){
            score=6;
        } else if ((pow(yProjectile-yCible,2)+pow(xProjectile-xCible,2))<=pow(6*interval,2)){
            score=5;
        } else if ((pow(yProjectile-yCible,2)+pow(xProjectile-xCible,2))<=pow(7*interval,2)){
            score=4;
        } else if ((pow(yProjectile-yCible,2)+pow(xProjectile-xCible,2))<=pow(8*interval,2)){
            score=3;
        } else if ((pow(yProjectile-yCible,2)+pow(xProjectile-xCible,2))<=pow(9*interval,2)){
            score=2;
        } else if ((pow(yProjectile-yCible,2)+pow(xProjectile-xCible,2))<=pow(10*interval,2)){
            score=1;
        }
        qDebug()<<"score"<< score<<endl;
        emit restart();
        firstCall=true;
        firstTime=true;


    }
    // Si on est sur le sol
    else if(yProjectile <=0.6) {
        emit restart();
        firstCall=true;
        firstTime=true;
    }
    // Si on est dans les barrières
    else if(false){

    } else {
        y = -(g/2) * pow(((zProjectile-z0)/v0z),2.0) + v0y*(zProjectile-z0)/v0z + y0;
        zProjectile+=.2;
        projectile->setCoordinates(xProjectile,y,zProjectile);
    }


}

void Trajectory::launchProjectile(int *xRot){
    if(firstCall){
        rotX=*xRot;
        firstCall=false;
    }
    if(*xRot!=40){
        *xRot+=1;
    } else {
        v0y = (rotX*14.5/(-40))+5.5;
        v0z = (rotX*(23-14.2)/(-40))+14.2;
        x0 = projectile->x;
        y0= 12 * sin((double) *xRot * PI/180)+9;
        z0 =  (-12 * cos((double)*xRot * PI/180) +12);
        if (firstTime){
            projectile->setCoordinates(x0,y0,z0);
            firstTime = false;
        }
        calculTrajectory();
    }

}
