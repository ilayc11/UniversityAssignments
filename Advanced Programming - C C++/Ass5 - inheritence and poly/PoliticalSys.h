//
// Created by ilay on 1/9/23.
//

#ifndef ASS5_FINAL_POLITICALSYS_H
#define ASS5_FINAL_POLITICALSYS_H
#include "vector"
#include "Party.h"
#include "string.h"
#include "Politician.h"
#include <exception>
using namespace std;

//exceptions i built according to the assignment
class BadID:public exception{ //bad id excp
public:
    virtual const char * what()const throw(){
        return "Bad Id";
    }
};
class BadName:public exception{
public:
    virtual const char * what()const throw(){
        return "Bad Name";
    }
};//bad name input excep
class BadInput:public exception{
public:
    virtual const char * what()const throw(){
        return "Bad Input";
    }
};//general bad input excep

//a functor for finding the biggest party
class compareParties{
public:
    bool operator()( Party const* former, Party const* latter){
        if(former->getSize()>latter->getSize())
            return true;
        if(former->getSize()==latter->getSize()){
            if(strcmp(former->getName().c_str(),latter->getName().c_str())>0)
                return true;
        }
        return false;
    }
};
class PoliticalSys {

std::vector<Party*>allParties;
std::vector<Politician*>allPoliticians;
std::vector<Party*>PartiesByComparison; //vector the will contain biggest party at index 0, will always be sorted after adding/deleting party nad adding/deleting politicians

void addPoliticianToParty(Politician*); //functions the finds the right party for a new politicans and adds it
void AssignNewParties(Party*); //assign all politicans accordingly after a new party has been added to system
Politician* getPoliticianById(int); //checks if there is already a politican with a given id
Party* checkForPartyNameInSystem(string); //checks if there is already a party with a given name
void textToPolitician(string); //reads a text and makes a new politician
void textToParty(string);//reads a text and makes a new party

public:
    //all public functions to be used in main file
    PoliticalSys(char * );
    ~PoliticalSys();
    void addPolitician();
    void addParty();
    void removePolitician();
    void removeParty();
    void elections();
    void printPoliticians();
    void printParties()const;
    void BiggestParty()const;

};


#endif //ASS5_FINAL_POLITICALSYS_H
