//
// Created by ilay on 1/9/23.
//

#include <iostream>
#include "DemocraticPoliticianSocial.h"
DemocraticPoliticianSocial::DemocraticPoliticianSocial(string fname, string lname, int id,int power):
        DemocraticPolitician(fname,lname,id,power){

}
DemocraticPoliticianSocial::~DemocraticPoliticianSocial()  {}

int DemocraticPoliticianSocial::calculatePower()const { //social have power * 2
    return (this->getPower())*2;
}
void DemocraticPoliticianSocial::print() const {
    std::cout<<"Democratic Person:"<<this->fName<<" "<<this->lName
             <<", Id:"<<this->id<<", Power:"<<this->power<<", Type:S, Chairman:"
             <<" ";
    if(this->headOfParty== nullptr||this->myParty== nullptr)
        std::cout<<"None \n";
    else
        std::cout<<this->headOfParty->getFirstName()<<"\n";
}
