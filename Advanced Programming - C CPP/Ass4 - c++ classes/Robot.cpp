//
// Created by ilay on 12/28/22.
//
#include "Robot.h"
Robot::Robot(){

}
Robot::Robot(int serial,int map,int x,int y){
    serialNumber=serial;
    mapNum=map;
    xCoord=x;
    yCoord=y;
}
Robot::Robot(const Robot &other){
    serialNumber=other.getSerialNumber();
    mapNum=other.getMapNumber();
    xCoord=other.getXCoord();
    yCoord=other.getYCoord();
}
void Robot::moveRobot(char tmp){
    if(tmp=='U')
        this->yCoord++;
    if(tmp=='D')
        this->yCoord--;
    if(tmp=='L')
        this->xCoord--;
    if(tmp=='R')
        this->xCoord++;
}
Robot::~Robot(){

}
