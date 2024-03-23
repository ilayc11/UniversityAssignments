//
// Created by ilay on 1/9/23.
//

#ifndef ASS5_FINAL_POLITICIAN_H
#define ASS5_FINAL_POLITICIAN_H
#include "string"
using std::string;
class Party; //circular includes, party is included in cpp file
class Politician {
protected:
string fName;
string lName;
int id;
Party * myParty;
Politician * headOfParty;
int power;
//i wanted most politician functions to trickle down to its children.
public:
    Politician(string,string,int,int);
    virtual ~Politician();
    virtual int calculatePower()const=0;
    virtual void print()const =0;
    virtual void updateHeadOfParty(); //updates new head of party using observer pattern
    virtual string getFirstName()const{return this->fName;}
    virtual int getPower()const{return this->power;}
    virtual void updateParty(Party*);
    virtual Party* getParty()const{return this->myParty;}
    virtual bool operator==(const Politician& other)const;
    Politician& operator=(const Politician& other);
    virtual int getId()const{return this->id;}
};


#endif //ASS5_FINAL_POLITICIAN_H
