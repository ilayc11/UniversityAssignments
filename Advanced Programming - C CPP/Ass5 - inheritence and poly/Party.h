//
// Created by ilay on 1/9/23.
//

#ifndef ASS5_FINAL_PARTY_H
#define ASS5_FINAL_PARTY_H
#include "string"
#include "vector"
#include <iostream>

/* i tried to get as much functions as i can in the base class so my derived classes wont includ much,
 * so if ill have a problem ill know where to look. thats why i didnt have to use virtual, but im keeping it
 * cause its already written */

using std::string;
class Politician; // so we wont have circular includes. politician is included in cpp file.
class Party {
string _nameOfParty;
protected:
std::vector<Politician*>members;
    Politician * _headOfParty;
public:
    Party(string name);
    virtual ~Party();
    virtual string getName()const{return this->_nameOfParty;}
    virtual void addPolitician(Politician&);
    virtual void removePolitician(Politician&);
    virtual void primaries();
    virtual int calculatePower()const;
    virtual Politician* getHead()const;
    virtual void print() const =0;
    virtual void NotifyNewHead();
    virtual std::vector<Politician*> getMembers(){return this->members;};
    virtual bool operator==(const Party& other)const;
    virtual int getSize()const{if(members.size()==0)return 0; else return members.size();}

};
#endif //ASS5_FINAL_PARTY_H