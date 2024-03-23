//
// Created by ilay on 1/9/23.
//


#include "Party.h"
#include "Politician.h"

Party::Party(string name):_nameOfParty(name),_headOfParty(nullptr){ //init Party class, resize members vector to 0 so we wont have invalid reads later
    members.resize(0);
}
Party::~Party() { //clears all allocated memory inside members vector without deleting the pointers to politicians
    members.clear();
}
Politician* Party::getHead()const{
    return this->_headOfParty;
}

void Party::NotifyNewHead() { //Notifys members about the new head of party using observer design pattern
    std::vector<Politician*>::iterator it;
    for(it=members.begin();it!=members.end();++it){
        (*it)->updateHeadOfParty();
    }
}
void Party::print()const {//printing a general message so the derived classes will be able to use it as a format

    std::cout<<"Party: "<<this->_nameOfParty<<", chairman:";
    if(this->getHead()== nullptr)
        std::cout<<"None, ";
    else
        std::cout<<this->_headOfParty->getFirstName()<<", ";
    std::cout<<"Size:"<<members.size()<<"\n";
    std::vector<Politician*>::const_iterator it;
    for(it=members.begin();it!=members.end();++it){
        std::cout<<"\t";
        (*it)->print();
    }
}
void Party::primaries() { //primaries function
    int maxPower=0;
    Politician * head= nullptr;
    std::vector<Politician*>::iterator im;
    for (im = members.begin(); im != members.end(); ++im) {
        if((*im)->calculatePower()/2!=(*im)->getPower()) { //checks if somone is a leader
            if((*im)->getPower()>maxPower) {
                maxPower = (*im)->getPower();
                head = (*im);
            }
        }
    }
    if(head!=nullptr){
        this->_headOfParty = head;
        std::cout << head->getFirstName() << " is the chairman of " << this->_nameOfParty << std::endl;
        this->NotifyNewHead();
    }
    else
        std::cout <<"None is the chairman of "<<_nameOfParty<<std::endl;
}
bool Party::operator==(const Party &other)const  { //for using == operator later in the code, might be usable for comparing vectors iteration
    if(this->_nameOfParty==other._nameOfParty)
        return true;
    return false;
}
int Party::calculatePower() const { //summing members power using their respective way to calculate power
    int powerSum = -0;
    std::vector<Politician *>::const_iterator it;
    for (it = members.begin(); it != members.end(); ++it) {
        powerSum+=(*it)->calculatePower();
    }
    return powerSum;
}

void Party::addPolitician(Politician &other) { //adds politician to members
    this->members.push_back((Politician*)&other);
    other.updateParty(this);

}

void Party::removePolitician(Politician &other) { //removes politican from members without deleting it from memory
    std::vector<Politician *>::iterator it;
    for (it = members.begin(); it != members.end(); ++it) {
        if(*(*it)==other) {
            if(*it==_headOfParty) {
                _headOfParty = nullptr;
                NotifyNewHead();
            }
            other.updateParty(nullptr);
            members.erase(it);
            break;
        }
    }

}
