#include "level.h"
#include <QDebug>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>

Level::Level(int lvl)
{
    this->lvl = lvl;
    target = new TargetDrawer();
    choosePosition();
}

void Level::choosePosition(){
    if(lvl == 0){
        srand (time(NULL));
        pos[2] = rand() % (this->z[1] - this->z[0] +1 ) + this->z[0];
    }else if (lvl == 1){
        srand (time(NULL));
        pos[2] = rand() % (this->z[3] - this->z[2] +1 ) + this->z[2];
    }else{
        srand (time(NULL));
        pos[2] = rand() % (this->z[5] - this->z[4] +1 ) + this->z[4];
    }
    /*srand (time(NULL));
    pos[0] = rand() % (this->maxX - this->minX +1 ) + this->minX;*/
    pos[0] = 0;
    srand (time(NULL));
    pos[1] = rand() % (this->maxX - this->minY +1 ) + this->minY;
}

void Level::drawTarget(){
    target->drawTarget(pos[0],pos[1],pos[2]);
}

