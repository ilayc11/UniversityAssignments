//
// Created by ilay on 1/9/23.
//

#include "RepublicanParty.h"
#include "RepublicanPolitician.h"
void RepublicanParty::print() const { //using base class print and adding the needed identifier
    std::cout<<"Republican ";
    Party::print();
}

RepublicanParty::RepublicanParty(string name) : Party(name) {}
