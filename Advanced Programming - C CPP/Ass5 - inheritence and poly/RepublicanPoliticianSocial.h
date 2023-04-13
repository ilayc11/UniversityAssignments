//
// Created by ilay on 1/9/23.
//

#ifndef ASS5_FINAL_REPUBLICANPOLITICIANSOCIAL_H
#define ASS5_FINAL_REPUBLICANPOLITICIANSOCIAL_H
#include "RepublicanPolitician.h"

class RepublicanPoliticianSocial :public RepublicanPolitician {
public:
    RepublicanPoliticianSocial(string fname, string lname, int id,
            int power);
    virtual ~RepublicanPoliticianSocial();
    virtual int calculatePower()const;
    virtual void print() const;
};


#endif //ASS5_FINAL_REPUBLICANPOLITICIANSOCIAL_H
