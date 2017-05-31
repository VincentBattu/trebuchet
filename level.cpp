#include "level.h"
#include <QDebug>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>

Level::Level(int z)
{
    this->z = z;
    target = new TargetDrawer();
}

void Level::choosePosition(){
    srand (time(NULL));
    pos[0] = rand() % (this->maxX - this->minX +1 ) + this->minX;
    srand (time(NULL));
    pos[1] = rand() % (this->maxX - this->minY +1 ) + this->minY;
}

void Level::drawTarget(){
    target->drawTarget(pos[0],pos[1],z);
}

void Level::setZ(int z){
    this->z = z;
}
