//
// Created by ilay on 1/9/23.
//

#include "RepublicanPoliticianSocial.h"
#include <iostream>

RepublicanPoliticianSocial::RepublicanPoliticianSocial(string fname, string lname, int id,int power):
        RepublicanPolitician(fname,lname,id,power){

}
RepublicanPoliticianSocial::~RepublicanPoliticianSocial()  {}

int RepublicanPoliticianSocial::calculatePower()const { //socials have power*2
    return this->getPower()*2;
}
void RepublicanPoliticianSocial::print() const {
    std::cout<<"Republican Person:"<<this->fName<<" "<<this->lName
             <<", Id:"<<this->id<<", Power:"<<this->power<<", Type:S, Chairman:"
             <<" ";
    if(this->headOfParty== nullptr||this->myParty== nullptr)
        std::cout<<"None \n";
    else
        std::cout<<this->headOfParty->getFirstName()<<"\n";
}