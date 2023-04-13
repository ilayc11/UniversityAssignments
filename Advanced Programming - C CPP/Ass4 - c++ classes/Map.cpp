//
// Created by ilay on 12/28/22.
//
#include "Map.h"
Map::Map(){
    for(int i=0;i<7;i++)
        for(int j=0;j<7;j++)
            arrayOfMap[i][j]=0;
}
Map::Map(int map[7][7]){
    for(int i=0;i<7;i++)
        for(int j=0;j<7;j++)
            arrayOfMap[i][j]=map[i][j];
}
Map::~Map(){

}
Map Map::operator+(const Map &other) const{
    Map ab;
    for(int i=0;i<7;i++)
        for(int j=0;j<7;j++) {
            if (arrayOfMap[i][j] == 0 and other.arrayOfMap[i][j] == 0)
                ab.arrayOfMap[i][j] = 0;
            else
                ab.arrayOfMap[i][j]=1;
        }
    return ab;
}
Map& Map::operator=(const Map &other){
    for(int i=0;i<7;i++)
        for(int j=0;j<7;j++)
            arrayOfMap[i][j]=other.arrayOfMap[i][j];
    return *this;
}
Map& Map::operator+=(const Map &other){
    for(int i=0;i<7;i++)
        for(int j=0;j<7;j++)
            if(other.arrayOfMap[i][j]==1)
            arrayOfMap[i][j]=other.arrayOfMap[i][j];
    return *this;
}

bool Map::operator==(const Map &other)const{
    for(int i=0;i<7;i++)
        for(int j=0;j<7;j++)
            if(other.arrayOfMap[i][j]!=arrayOfMap[i][j])
                return false;
    return true;
}
bool Map::isValidCoor(int xCoord , int yCoord) const{
    if(this->arrayOfMap[yCoord][xCoord]==1)
        return false;
    return true;
}

ostream& operator<<(ostream& out,const Map& source) {
    for (int i = 6; i >= 0; i--) {
        cout << "[";
        for (int k = 0; k < 7; k++) {
            cout << source.arrayOfMap[i][k];
            if(k<6)
                cout<<" ";
        }
        cout << "]"<<endl;

    }
    return out ;
}