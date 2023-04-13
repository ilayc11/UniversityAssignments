//
// Created by ilay on 1/9/23.
//

#ifndef ASS5_FINAL_DEMOCRATICPOLITICIANLEADER_H
#define ASS5_FINAL_DEMOCRATICPOLITICIANLEADER_H
#include "DemocraticPolitician.h"

class DemocraticPoliticianLeader:public DemocraticPolitician {
public:
    DemocraticPoliticianLeader(string fname, string lname, int id,int power);
    virtual ~DemocraticPoliticianLeader();
    virtual int calculatePower()const; //calculates the power
    virtual void print() const;
};


#endif //ASS5_FINAL_DEMOCRATICPOLITICIANLEADER_H
