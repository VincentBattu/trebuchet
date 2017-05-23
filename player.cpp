#include "player.h"
using namepsace cv;
Player::Player(QObject *parent) : QThread(parent)
{
    stop = true;
}

bool Player::loadVideo(string filename){
    capture.open(filename);
    if(capture.isOpened()){
        frameRate = (int) capture.get(CV_CAP_PROP_FPS);
        return true;
    }
    else
        return false;
}

void Player::play(){
    if (!isRunning()){
        if (isStopped()){
            stop = false;
        }
        start(LowPriority);
    }
}

void Player::run(){
    int delay = (1000/frameRate);
    while (!stop){
        if (!capture.read(frame)) {
            stop = true;
        }
        if (frame.channels() == 3){

        }
    }
}
