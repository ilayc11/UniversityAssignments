//
// Created by ilay on 1/9/23.
//

#ifndef ASS5_FINAL_DEMOCRATICPARTY_H
#define ASS5_FINAL_DEMOCRATICPARTY_H
#include "Party.h"

/*keeping all of the virtual functions of base class except for print which is different for each child class*/

class DemocraticParty:public Party {
public:
    DemocraticParty(string name);
    virtual void print()const;

};


#endif //ASS5_FINAL_DEMOCRATICPARTY_H
