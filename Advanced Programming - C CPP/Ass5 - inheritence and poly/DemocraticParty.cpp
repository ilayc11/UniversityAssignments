//
// Created by ilay on 1/9/23.
//

#include "DemocraticParty.h"
#include "DemocraticPolitician.h"
void DemocraticParty::print() const { //using base class print and adding the needed identifier
    std::cout<<"Democrat ";
    Party::print();
}

DemocraticParty::DemocraticParty(string name) : Party(name) {}






