//
// Created by ilay on 1/9/23.
//

#include <iostream>
#include "Politician.h"
#include "Party.h"
Politician::Politician(string fname,string lname,int id,int power){
    this->fName=fname;
    this->lName=lname;
    this->id=id;
    this->power=power;
    myParty= nullptr;
    headOfParty= nullptr;
}
Politician::~Politician() {}

void Politician::updateHeadOfParty() {
    if(myParty== nullptr)
        this->headOfParty= nullptr;
    else
        this->headOfParty=myParty->getHead();
}

bool Politician::operator==(const Politician &other) const {
    if(this->id==other.id)
        return true;
    return false;
}
Politician& Politician::operator=(const Politician &other) {
    this->id=other.id;
    this->myParty=other.myParty;
    this->headOfParty=other.headOfParty;
    this->power=other.power;
    this->fName=other.fName;
    this->lName=other.lName;
    return *this;
}
void Politician::updateParty(Party* party){
    this->myParty=party;
    if(myParty!= nullptr)
        this->headOfParty=myParty->getHead();
    else
        this->headOfParty= nullptr;
}