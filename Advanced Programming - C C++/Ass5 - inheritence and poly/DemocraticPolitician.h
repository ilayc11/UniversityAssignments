//
// Created by ilay on 1/9/23.
//

#ifndef ASS5_FINAL_DEMOCRATICPOLITICIAN_H
#define ASS5_FINAL_DEMOCRATICPOLITICIAN_H
#include "Politician.h"

class DemocraticPolitician : public Politician {

public:
    DemocraticPolitician(string,string,int,int);
    virtual ~DemocraticPolitician()=0;
};


#endif //ASS5_FINAL_DEMOCRATICPOLITICIAN_H
