//
// Created by ilay on 1/9/23.
//

#include "RepublicanPoliticianLeader.h"
#include <iostream>
RepublicanPoliticianLeader::RepublicanPoliticianLeader(string fname, string lname, int id,
                                                       int power):
        RepublicanPolitician(fname,lname,id,power){

}
RepublicanPoliticianLeader::~RepublicanPoliticianLeader()  {}

int RepublicanPoliticianLeader::calculatePower()const {
    return this->getPower();
}
void RepublicanPoliticianLeader::print() const {
    std::cout<<"Republican Person:"<<this->fName<<" "<<this->lName
             <<", Id:"<<this->id<<", Power:"<<this->power<<", Type:L, Chairman:"
             <<" ";
    if(this->headOfParty== nullptr||this->myParty== nullptr)
        std::cout<<"None \n";
    else
        std::cout<<this->headOfParty->getFirstName()<<"\n";

}