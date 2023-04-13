//
// Created by ilay on 12/28/22.
//
#include <iostream>
#include <cstring>
#include "Robot.h"
#include "Map.h"
using namespace std;


int RobotInSystem=0; //num of robots in system
Robot ** robArray; //array of robots
; //array to be used when we want to change array of robots size
int SerialCounter=0; //serial counter instead of static in robot
Map * mapPointer; //mappointer to be used when we have point to user given map
Robot * robotPointer; //to be used in pointing to specific robot

bool checkValidCoor(Map &map,int tmpx,int tmpy){ //checks if a given coordinate is valid to move to
    if(map.isValidCoor(tmpx, tmpy))
        return true;
    return false;
}
void addRobot(int map ,int x,int y){


    if(RobotInSystem==0){
        SerialCounter++;
        RobotInSystem++;
        robArray=new Robot*[1];
        robArray[0]=new Robot(SerialCounter,map,x,y);
        cout<<"New Robot: "<<SerialCounter<<" MAP: "<<map<< " GPS: "<<x<<","<<y<<endl;
        return;
    }
    Robot ** tmpRobotArray=new Robot*[RobotInSystem+1];
    for(int i=0;i<RobotInSystem;i++)
        tmpRobotArray[i]=robArray[i];
    SerialCounter++;
    tmpRobotArray[RobotInSystem]=new Robot(SerialCounter,map,x,y);
    delete[]robArray;
    robArray=tmpRobotArray;
    RobotInSystem++;
    cout<<"New Robot: "<<SerialCounter<<" MAP: "<<map<< " GPS: "<<x<<","<<y<<endl;
}
void deleteRobot(int serial){
    robotPointer = nullptr;
    int i;
    for( i=0;i<RobotInSystem;i++){
        if(serial==robArray[i]->getSerialNumber()) {
            robotPointer = robArray[i];
            break;
        }
    }
    if(RobotInSystem>1) {
        Robot ** tmpRobotArray = new Robot *[RobotInSystem - 1];
        if (i + 1 != RobotInSystem) {
            for (int k = i; k < RobotInSystem-1; k++)
                robArray[k] = robArray[k + 1];
        }
        for (int k = 0; k < RobotInSystem - 1; k++)
            tmpRobotArray[k] = robArray[k];
        delete[]robArray;
        robArray = tmpRobotArray;
        delete robotPointer;
        RobotInSystem--;
    }
    else{
        delete robArray[0];
        delete[]robArray;
        RobotInSystem--;
    }
}

int main() {

    char inputuser[300]; //to be used in user input
    char tmpinput;//to be used in user input
    int tmpMapNum,tmpXcoor,tmpYcoor; //to be use in user input inside cases
    int tmp1[7][7]=
            {
            {1,0,0,0,0,0,0},
            {1,0,1,0,0,1,0},
            {1,0,1,1,0,1,0},
            {0,0,0,1,1,1,0},
            {0,1,0,1,1,1,0},
            {1,1,0,0,0,0,1},
            {1,0,0,1,1,0,1},
            }; //init array 1 for map 1
    int tmp2[7][7]=
            {
                    {1,0,1,0,0,0,0},
                    {1,1,0,1,1,1,0},
                    {0,0,0,0,0,1,1},
                    {0,1,1,1,0,1,1},
                    {1,1,0,0,0,1,1},
                    {1,1,0,1,1,1,1},
                    {1,1,0,0,0,1,1},
            }; //init array 2 for map 2
    Map one(tmp1);
    Map two(tmp2);

    while(true) {
        cout << "Robot Control Menu " << endl;
        cout << "1. Add Robot " << endl;
        cout << "2. Delete Robot " << endl;
        cout << "3. Move Robot " << endl;
        cout << "4. Operator + " << endl;
        cout << "5. Operator += " << endl;
        cout << "6. Operator = " << endl;
        cout << "7. Operator == " << endl;
        cout << "8. Operator << " << endl;
        cout << "9. Quit " << endl;
        cout << "Input your option: " << endl;

        cin>>inputuser;
        if(strlen(inputuser) > 1)
            strcpy(inputuser, "a");
        switch(inputuser[0]){
            case '1':
                cout<<"Enter MAP number: "<<endl;
                cin>>tmpMapNum;
                if(tmpMapNum!=1&&tmpMapNum!=2){
                    cout << "Invalid MAP number " << endl;
                    break;
                }
                if(tmpMapNum==1)
                    mapPointer=&one;
                else
                    mapPointer=&two;
                cout<<"Enter Coordinates (X,Y): "<<endl;
                cin>>tmpXcoor>>tmpYcoor;
                if(!checkValidCoor(*mapPointer, tmpXcoor, tmpYcoor)) {
                    cout << "Invalid location " << endl;
                    break;
                }
                addRobot(tmpMapNum,tmpXcoor,tmpYcoor);
                    break;

            case '2':
                robotPointer= nullptr;
                cout<<"Enter Robot number: "<<endl;
                int tmpNum;
                cin>>tmpNum;
                for(int i=0;i<RobotInSystem;i++)
                    if(robArray[i]->getSerialNumber()==tmpNum)
                        robotPointer=robArray[i];
                if(robotPointer== nullptr)
                    break;
                cout<<"Robot deleted: "<<robotPointer->getSerialNumber()<<" MAP: "<<robotPointer->getMapNumber()
                    <<" GPS: "<<robotPointer->getXCoord()<<","<<robotPointer->getYCoord()<<" "<<endl;
                deleteRobot(tmpNum);
                break;

            case '3': {
                robotPointer= nullptr;
                cout << "Enter Robot number: " << endl;
                cin >> tmpNum;
                for (int i = 0; i < RobotInSystem; i++) {
                    if (tmpNum == robArray[i]->getSerialNumber()) {
                        robotPointer = robArray[i];
                        break;
                    }

                }
                if(robotPointer== nullptr)
                    break;
                cout << "Enter direction: " << endl;
                cin >> tmpinput;
                if(robotPointer->getXCoord()==-1||robotPointer->getYCoord()==-1)
                    break;
                Robot *robotAfterMove=new Robot(*robotPointer);
                robotAfterMove->moveRobot(tmpinput);
                if (robotAfterMove->getXCoord() > 6 || robotAfterMove->getXCoord() < 0 ||
                    robotAfterMove->getYCoord() > 6 || robotAfterMove->getYCoord() < 0) {
                    robotPointer->setCoord(-1, -1);
                    delete robotAfterMove;
                }
                else {
                    if (robotPointer->getMapNumber() == 1) {
                        if (one.isValidCoor(robotAfterMove->getXCoord(), robotAfterMove->getYCoord()))
                            robotPointer->moveRobot(tmpinput);
                        else {
                            cout << "Invalid location " << endl;
                            delete robotAfterMove;
                            break;
                        }
                    } else {
                        if (two.isValidCoor(robotAfterMove->getXCoord(), robotAfterMove->getYCoord()))
                            robotPointer->moveRobot(tmpinput);
                        else {
                            cout << "Invalid location " << endl;
                            delete robotAfterMove;
                            break;
                        }
                    }
                    cout << "Robot: " << robotPointer->getSerialNumber() << " MAP: " << robotPointer->getMapNumber() <<
                         " GPS: " << robotPointer->getXCoord() << "," << robotPointer->getYCoord() << endl;
                }

                break;
            }
            case '4': {

                Map a;
                   a = one + two;
                cout<<a<<endl;
                for (int k = 0; k < RobotInSystem; k++)
                    if(robArray[k]->getXCoord()!=-1&&robArray[k]->getYCoord()!=-1)
                    if ( a.isValidCoor(robArray[k]->getXCoord(), robArray[k]->getYCoord()))
                        cout << "Robot: " << robArray[k]->getSerialNumber()<<" GPS: " << robArray[k]->getXCoord() << "," << robArray[k]->getYCoord() << endl;
                break;
            }
            case '5':
                cout << "Override MAP number: " << endl;;
                cin >> tmpNum;
                if (tmpNum != 1 && tmpNum != 2) {
                    cout << "Invalid MAP number " << endl;
                    break;
                }
                if (tmpNum == 1) {
                    one += two;
                    mapPointer = &one;
                } else {
                    two += one;
                    mapPointer = &two;

                }
                for (int k = 0; k < RobotInSystem; k++)
                    if (robArray[k]->getMapNumber() == tmpNum)
                        if(robArray[k]->getXCoord()!=-1&&robArray[k]->getYCoord()!=-1)
                        if (mapPointer->isValidCoor(robArray[k]->getXCoord(), robArray[k]->getYCoord()))
                            deleteRobot(robArray[k]->getSerialNumber());
                break;

            case '6':
                cout << "Override MAP number: " << endl;
                cin >> tmpNum;
                if (tmpNum != 1 && tmpNum != 2) {
                    cout << "Invalid MAP number " << endl;
                    break;
                }
                if (tmpNum == 1) {
                    one = two;
                    mapPointer = &one;
                } else {
                    two = one;
                    mapPointer = &two;

                }
                for (int k = 0; k < RobotInSystem; k++)
                    if (robArray[k]->getMapNumber() == tmpNum)
                        if(robArray[k]->getXCoord()!=-1&&robArray[k]->getYCoord()!=-1)
                        if (!mapPointer->isValidCoor(robArray[k]->getXCoord(), robArray[k]->getYCoord()))
                            deleteRobot(robArray[k]->getSerialNumber());
                break;

            case '7':
                if(one==two)
                    cout<<"TRUE "<<endl;
                else
                cout<<"FALSE "<<endl;
                break;

            case '8':
                cout << "Please enter MAP number: " << endl;
                cin >> tmpNum;
                if (tmpNum != 1 && tmpNum != 2) {
                    cout << "Invalid MAP number " << endl;
                    break;
                }
                if (tmpNum == 1)
                    mapPointer = &one;
                else
                    mapPointer = &two;
                cout << *mapPointer << endl;
                for (int k = 0; k < RobotInSystem; k++)
                    if(robArray[k]->getXCoord()!=-1&&robArray[k]->getYCoord()!=-1)
                    if (robArray[k]->getMapNumber() == tmpNum)
                        cout << "Robot: " << robArray[k]->getSerialNumber() << " MAP: " << robArray[k]->getMapNumber()
                             <<" GPS: " << robArray[k]->getXCoord() << "," << robArray[k]->getYCoord() << endl;
                        break;


            case '9':

                for(int i=0;i<RobotInSystem;i++) {
                    delete robArray[i];
                }
                if(RobotInSystem!=0)
                    delete[]robArray;
                return 0;

            default:
            cout<<"Invalid input "<<endl;


        }
    }
}


