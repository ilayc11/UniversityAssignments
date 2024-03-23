//
// Created by ilay on 12/28/22.
//

#ifndef ASSIGNMENT4_MAP_H
#define ASSIGNMENT4_MAP_H
#include <iostream>
using std::cout;
using std::ostream;
using std::endl;

//this is Map h file

class Map{
   int arrayOfMap[7][7];
public:
    Map(); //default constructor init Map with 0 in all cells
    Map(int map[7][7]); //init a Map using a pre-existing 2d array
    ~Map();


    Map operator+(const Map &other) const;
    Map &operator=(const Map &other);
    Map& operator+=(const Map &other);
    bool operator==(const Map &other)const;
    bool isValidCoor(int , int)const;//to check if a given coordinates are valid to place a robot in
    friend ostream& operator<<(ostream& out,const Map& source);
    
};


#endif //ASSIGNMENT4_MAP_H
