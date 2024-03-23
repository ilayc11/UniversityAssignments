//
// Created by ilay on 1/9/23.
//
#include <fstream>
#include <sstream>
#include <algorithm>
#include "PoliticalSys.h"
#include "DemocraticParty.h"
#include "RepublicanParty.h"
#include "DemocraticPoliticianSocial.h"
#include "DemocraticPoliticianLeader.h"
#include "RepublicanPoliticianSocial.h"
#include "RepublicanPoliticianLeader.h"


/* across all functions in this file we will use a technique of replacing output stream with a new stream
 * so we will be able to determine which class we are facing.
 * for example:
 * std::stringstream ss1;
    ss1.str(std::string()); //initialising the ss1 string
    auto old_buf = std::cout.rdbuf(ss1.rdbuf()); //replaces the stream
    newParty->print(); //prints so we can capture it with ss1
    std::cout.rdbuf(old_buf); //returns the output stream back to normal
 * */

void PoliticalSys::textToPolitician(string text) { //gets a text and makes a new politican accordingly
    string fname, lname;
    string RoD, LoS;
    int id, power;
    int position = 0;
    int tokenNum = 0;
    for (int i = 0; i <=text.length(); i++) {
        switch (tokenNum) {
            case 5:
                if (text[i] == '\r') {
                    LoS = text.substr(position, i - position);
                    tokenNum++;
                }
                break;
            case 4:
                if (text[i] == ' ') {
                    RoD = text.substr(position, i - position);
                    position = i+1;
                    tokenNum++;
                }
                break;
            case 3:
                if (text[i] == ' ') {
                    power = std::stoi(text.substr(position, i - position));
                    position = i+1;
                    tokenNum++;
                }
                break;
            case 2:
                if (text[i] == ' ') {
                    id = std::stoi(text.substr(position, i - position));
                    position = i+1;
                    tokenNum++;
                }
                break;
            case 1:
                if (text[i] == ' ') {
                    lname = text.substr(position, i - position);
                    position = i+1;
                    tokenNum++;
                }
                break;
            case 0:
                if (text[i] == ' ') {
                    fname = text.substr(position, i - position);
                    position = i+1;
                    tokenNum++;
                }
                break;

        }
    }
    Politician *toadd;
    if (RoD[0] == 'D') {
        if (LoS[0] == 'L')
            toadd = new DemocraticPoliticianLeader(fname, lname, id, power);
        else
            toadd = new DemocraticPoliticianSocial(fname, lname, id, power);
        allPoliticians.push_back(toadd);
    }
    else{
        if (LoS[0] == 'L')
            toadd = new RepublicanPoliticianLeader(fname, lname, id, power);
        else
            toadd = new RepublicanPoliticianSocial(fname, lname, id, power);
        this->allPoliticians.push_back(toadd);
    }
}
void PoliticalSys::textToParty(string text){
    string name, RoD;
    int position = 0;
    int tokenNum = 0;
    for (int i = 0; i <=text.length(); i++) {
        switch (tokenNum) {
            case 1:
                if (text[i] == '\r'||i==text.length()) {
                    RoD = text.substr(position, i - position);
                    tokenNum++;
                }
                break;
            case 0:
                if (text[i] == ' ') {
                    name = text.substr(position, i - position);
                    position = i+1;
                    tokenNum++;
                }
                break;

        }
    }
    Party* toAdd;
    if(RoD=="D") {
        toAdd=new DemocraticParty(name);
        allParties.push_back(toAdd);
        PartiesByComparison.push_back(toAdd);
        AssignNewParties(toAdd);
    }
    else{
        toAdd=new RepublicanParty(name);
        allParties.push_back(toAdd);
        PartiesByComparison.push_back(toAdd);
        AssignNewParties(toAdd);
    }
    sort(PartiesByComparison.begin(),PartiesByComparison.end(),compareParties());
}

PoliticalSys::PoliticalSys(char * argv) { //reads a text file and converts it to politicians and parties
    string text;

    Politician* toAdd;
    Party* partyToAdd;
    char politiciansFlag = 'n',partyFlag='n';
    std::ifstream myFile(argv);
    while (std::getline(myFile, text)) {
        if(partyFlag=='y')
            textToParty(text);
        if(text=="Parties:\r") {
            partyFlag = 'y';
            politiciansFlag='n';
        }
        if (politiciansFlag == 'y')
            textToPolitician(text);
        if (text == "Politicians:\r")
            politiciansFlag = 'y';
    }

}

void PoliticalSys::addPolitician() {
    string fNameBuffer, lNameBuffer, RorD, LorS;
    int id, power;
    Politician *added;
    while (true) {
        try {
            std::cout << "---Create Politician---\n"
                      << "First name:\n";
            std::cin >> fNameBuffer;
            std::cout << "Last name:\n";
            std::cin >> lNameBuffer;
            std::cout << "ID:\n";
            std::cin >> id;
            std::cout << "Power:\n";
            std::cin >> power;
            std::cout << "Republican or Democratic person\n";
            std::cin >> RorD;
            std::cout << "Leader or Social\n";
            std::cin >> LorS;
            if(getPoliticianById(id) != nullptr ||id<=0)
                throw BadID();
            if (power <0||RorD.length() > 1 || RorD.length() <= 0||LorS.length() > 1 || LorS.length() <= 0 ||
                                                             (RorD[0] != 'D' && RorD[0] != 'R') ||
                                                             (LorS[0] != 'L' && LorS[0] != 'S'))
                throw BadInput();
        }
        catch (BadID&e){
            cout<<"Please enter valid details\n";
            continue;
        }
        catch (BadInput&e){
            cout<<"Please enter valid details\n";
            continue;
        }
            break;
    }

        if (RorD == "D") {
            if (LorS == "S")
                added = new DemocraticPoliticianSocial(fNameBuffer, lNameBuffer, id, power);
            else
                added = new DemocraticPoliticianLeader(fNameBuffer, lNameBuffer, id, power);
        }
        else {
            if (LorS == "S")
                added = new RepublicanPoliticianSocial(fNameBuffer, lNameBuffer, id, power);
            else
                added = new RepublicanPoliticianLeader(fNameBuffer, lNameBuffer, id, power);
        }
        this->allPoliticians.push_back(added);
        added->updateParty(nullptr);
        if (!allParties.empty())
            addPoliticianToParty(added);
        std::sort(PartiesByComparison.begin(), PartiesByComparison.end(), compareParties());

}
void PoliticalSys::addParty() {
    string name, RorD;
    Party *toAdd;
    while (true) {

        std::cout << "---Create Party---\n"
                  << "Name:\n";
        std::cin >> name;
        std::cout << "Republican or Democratic party\n";
        std::cin >> RorD;
        try {
            if (checkForPartyNameInSystem(name)!= nullptr)
                throw BadName();
            if(RorD.length() > 1 || RorD.length() <= 0||(RorD[0] != 'D' &&RorD[0] != 'R'))
                throw BadInput();
        }
        catch (BadInput&e){
            std::cout << "Please enter valid details\n";
            continue;
        }
        catch (BadName&e){
            std::cout << "Please enter valid details\n";
            continue;
        }
        break;
    }
    try{
    if (RorD == "D")
        toAdd = new DemocraticParty(name);
    else
        toAdd = new RepublicanParty(name);
    }
    catch(exception &e){
        throw "bad alloc";
    }
    this->allParties.push_back(toAdd);
    this->PartiesByComparison.push_back(toAdd);
    AssignNewParties(toAdd);
    std::sort(PartiesByComparison.begin(), PartiesByComparison.end(), compareParties());
}

void PoliticalSys::AssignNewParties(Party *newParty) {
    std::stringstream ss1, ss2;
    std::vector<Politician *>::iterator it;
    ss1.str(std::string());
    auto old_buf = std::cout.rdbuf(ss1.rdbuf());
    newParty->print();
    std::cout.rdbuf(old_buf);
    for (it = allPoliticians.begin(); it != allPoliticians.end(); ++it) {
        ss2.str(std::string());
        old_buf = std::cout.rdbuf(ss2.rdbuf());
        (*it)->print();
      std::cout.rdbuf(old_buf);
        if (ss1.str().substr(0, 8) == ss2.str().substr(0, 8)) {
            if ((*it)->getParty() == nullptr) {
                newParty->addPolitician(*(*it));
                (*it)->updateParty(newParty);
            }
            else{if ((*it)->getParty()->getSize() > newParty->getSize()) {
                (*it)->getParty()->removePolitician(*(*it));
                (*it)->updateParty(newParty);
                newParty->addPolitician(*(*it));
            }
        }
        }
    }
}

void PoliticalSys::removePolitician() {
    if (allPoliticians.empty())
        return;
    int id;
    Politician *toRemove;
    Party * removeFrom;
    while (true) {

        std::cout << "---Remove Politician---\n"
                  << "Enter the ID:\n";
        std::cin >> id;
        try {
            toRemove = getPoliticianById(id);
            if (toRemove == nullptr || id <= 0)
                throw BadID();
        }
        catch (BadID&e){
                std::cout << "Please enter valid details\n";
                continue;
        }
        break;
    }
    removeFrom=toRemove->getParty();
    if(removeFrom!= nullptr)
           removeFrom->removePolitician(*toRemove);
    std::vector<Politician *>::iterator it;
    for(it=allPoliticians.begin();it!=allPoliticians.end();++it)
        if((*it)==toRemove) {
            delete *it;
            allPoliticians.erase(it);
            break;
        }

    std::sort(PartiesByComparison.begin(),PartiesByComparison.end(),compareParties());

}
Politician *PoliticalSys::getPoliticianById(int id) {
    Politician *toRemove = nullptr;
    std::vector<Politician *>::iterator it;
    for (it = allPoliticians.begin(); it != allPoliticians.end(); ++it) {
        if ((*it)->getId() == id) {
            toRemove = (*it);
        }
    }
    return toRemove;
}

void PoliticalSys::removeParty() { //TODO REMOVE PARTY FROM PARTIES LISTS
    if (allParties.empty())
        return;
    std::stringstream ss1, ss2;

    string name;
    Party *toRemove;
    std::vector<Politician *> members;


    while (true) {
        std::cout << "---Remove Party---\n"
                  << "Enter party name:\n";
        std::cin >> name;
        try {
            toRemove = checkForPartyNameInSystem(name);
            if (toRemove == nullptr)
                throw BadName();
        }
        catch (BadName &e) {
            std::cout << "Please enter valid details\n";
            continue;
        }

        std::vector<Party *>::iterator im;
        for (im = allParties.begin(); im != allParties.end(); ++im){
            if(toRemove==(*im)){
                allParties.erase(im);
                break;
            }
        }
        for (im = PartiesByComparison.begin(); im != PartiesByComparison.end(); ++im){
            if(toRemove==(*im)){
                PartiesByComparison.erase(im);
                break;
            }
        }

        ss1.str(std::string());
        auto old_buf = std::cout.rdbuf(ss1.rdbuf());
        toRemove->print();
        std::cout.rdbuf(old_buf);

        members = toRemove->getMembers();
        std::vector<Politician *>::iterator it;
        for (it = members.begin(); it != members.end(); ++it) {
            (*it)->updateParty(nullptr);

            for (im = allParties.begin(); im != allParties.end(); ++im) {

                ss2.str(std::string());
                old_buf = std::cout.rdbuf(ss2.rdbuf());
                (*im)->print();
                std::cout.rdbuf(old_buf);

                if (ss1.str().substr(0, 8) == ss2.str().substr(0, 8)) {
                    if ((*it)->getParty() == nullptr) {
                        (*im)->addPolitician(**it);
                        (*it)->updateParty(*im);
                    }
                    else{
                        if((*it)->getParty()->getSize()>(*im)->getSize()){
                            (*it)->getParty()->removePolitician(**it);
                            (*im)->addPolitician(**it);
                            (*it)->updateParty(*im);
                        }
                    }
                }
            }
        }
        break;
    }
    delete toRemove;
    sort(PartiesByComparison.begin(),PartiesByComparison.end(),compareParties());
}

Party *PoliticalSys::checkForPartyNameInSystem(string partyname) {

    std::vector<Party *>::iterator it;
    for (it = allParties.begin(); it != allParties.end(); ++it) {
        if ((*it)->getName() == partyname)
            return (*it);
    }
    return nullptr;
}




void PoliticalSys::elections() {
    if(allPoliticians.empty()||allParties.empty())
        return;
    Party *party;
    int biggestpower = 0;
    std::cout << "----Primaries----\n";
    std::vector<Party *>::iterator it;
    for (it = allParties.begin(); it != allParties.end(); ++it) {
        (*it)->primaries();
    }
    std::cout << "----Elections----\n";
    for (it = allParties.begin(); it != allParties.end(); ++it) {
        std::cout << "Party: " << (*it)->getName() << ",Power:" << (*it)->calculatePower() << "\n";
        if (biggestpower < (*it)->calculatePower()) {
            biggestpower = (*it)->calculatePower();
            party = (*it);
        }
    }
    std::cout << "----Elections Results----\n";
    std::cout << party->getName() << " party won the elections and " ;
    if(party->getHead()!= nullptr)
        std::cout<< party->getHead()->getFirstName()<< " is the prime minister \n";
    else
        std::cout<<"None is the prime minister \n";
}

void PoliticalSys::printPoliticians()  {
    if(allPoliticians.empty())
        return;
    cout<<"----Politicians----\n";
    std::vector<Politician *>::iterator it;
    for (it = allPoliticians.begin(); it != allPoliticians.end(); ++it) {
        (*it)->print();
    }
}

void PoliticalSys::printParties() const {
    if(allParties.empty())
        return;
    cout<<"----Parties----\n";
    std::vector<Party *>::const_iterator it;
    for (it = allParties.begin(); it != allParties.end(); ++it) {
        (*it)->print();
    }
}

PoliticalSys::~PoliticalSys() {
    std::vector<Party *>::iterator it;
    std::vector<Politician *>::iterator im;
    for (it = allParties.begin(); it != allParties.end(); ++it)
        delete *it;
    for (im = allPoliticians.begin(); im != allPoliticians.end(); ++im)
        delete *im;
    allParties.clear();
    allPoliticians.clear();

}

void PoliticalSys::BiggestParty() const {
    if(allParties.empty())
        return;
    std::cout << "----Biggest Party----\n";
        std::cout << "[" << (*PartiesByComparison.begin())->getName() << "," << (*PartiesByComparison.begin())->getSize() << "]\n";
}

void PoliticalSys::addPoliticianToParty(Politician * toAdd) {
    if(allParties.empty())
        return;
    Party *partyToAdd= nullptr;
    std::stringstream ss1,ss2;
    ss1.str(std::string());
    auto old_buf = std::cout.rdbuf(ss1.rdbuf());
    toAdd->print();
    std::cout.rdbuf(old_buf);
    std::vector<Party *>::iterator it;
    for (it = allParties.begin(); it != allParties.end(); ++it) {
        ss2.str(std::string());
        old_buf = std::cout.rdbuf(ss2.rdbuf());
        (*it)->print();
        std::cout.rdbuf(old_buf);
        if(ss2.str().substr(0,8)==ss1.str().substr(0,8)) {
            if(toAdd->getParty()== nullptr){
                (*it)->addPolitician(*toAdd);
                toAdd->updateParty(*it);
            }
            else {
                if ((*it)->getSize() < toAdd->getParty()->getSize()) {
                    toAdd->getParty()->removePolitician(*toAdd);
                    (*it)->addPolitician(*toAdd);
                    toAdd->updateParty((*it));
                }
            }
        }
    }
}


