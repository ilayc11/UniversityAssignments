//
// Created by ilay on 1/9/23.
//

#ifndef ASS5_FINAL_DEMOCRATICPOLITICIANSOCIAL_H
#define ASS5_FINAL_DEMOCRATICPOLITICIANSOCIAL_H
#include "DemocraticPolitician.h"

class DemocraticPoliticianSocial:public DemocraticPolitician {
public:
    DemocraticPoliticianSocial(string fname, string lname, int id,int power);
    virtual ~DemocraticPoliticianSocial();
    virtual int calculatePower()const;
    virtual void print() const;
};


#endif //ASS5_FINAL_DEMOCRATICPOLITICIANSOCIAL_H
