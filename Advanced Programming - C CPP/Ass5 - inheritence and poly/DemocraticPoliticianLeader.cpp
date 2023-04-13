//
// Created by ilay on 1/9/23.
//

#include <iostream>
#include "DemocraticPoliticianLeader.h"

DemocraticPoliticianLeader::DemocraticPoliticianLeader(string fname, string lname, int id,int power):
        DemocraticPolitician(fname,lname,id,power){

}
DemocraticPoliticianLeader::~DemocraticPoliticianLeader()  {}

int DemocraticPoliticianLeader::calculatePower()const { //calculates power
    return this->getPower();
}
void DemocraticPoliticianLeader::print() const {
    std::cout<<"Democratic Person:"<<this->fName<<" "<<this->lName
    <<", Id:"<<this->id<<", Power:"<<this->power<<", Type:L, Chairman:"
    <<" ";
    if(this->headOfParty== nullptr||this->myParty== nullptr)
        std::cout<<"None \n";
    else
        std::cout<<this->headOfParty->getFirstName()<<"\n";

}
