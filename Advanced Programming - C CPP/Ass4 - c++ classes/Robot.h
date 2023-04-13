//
// Created by ilay on 12/28/22.
//

#ifndef ASSIGNMENT4_ROBOT_H
#define ASSIGNMENT4_ROBOT_H
//this is Robot h file
class Robot{
    int serialNumber;
    int mapNum;
    int xCoord;
    int yCoord;
public:
    Robot();
    Robot(int serial,int map,int x,int y);
    Robot(const Robot &other);
    ~Robot();

    void moveRobot(char ); //moves a robot 1 cell by given direction
    void setCoord(int x,int y){xCoord=x; yCoord=y;}//sets  coordinates to given x,y . to be used to move to -1 -1
    int getXCoord()const {return this->xCoord;} //get x coord
    int getYCoord()const {return this->yCoord;}//get y coord
    int getMapNumber()const{return this->mapNum;}//gets connected map number
    int getSerialNumber()const{return this->serialNumber;}//gets robot serial
};
#endif //ASSIGNMENT4_ROBOT_H
