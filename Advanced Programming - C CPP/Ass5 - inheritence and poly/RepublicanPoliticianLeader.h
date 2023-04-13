//
// Created by ilay on 1/9/23.
//

#ifndef ASS5_FINAL_REPUBLICANPOLITICIANLEADER_H
#define ASS5_FINAL_REPUBLICANPOLITICIANLEADER_H
#include "RepublicanPolitician.h"

class RepublicanPoliticianLeader:public RepublicanPolitician {
public:
    RepublicanPoliticianLeader(string fname, string lname, int id,
             int power);
    virtual ~RepublicanPoliticianLeader();
    virtual int calculatePower()const;

    virtual void print() const;
};


#endif //ASS5_FINAL_REPUBLICANPOLITICIANLEADER_H
