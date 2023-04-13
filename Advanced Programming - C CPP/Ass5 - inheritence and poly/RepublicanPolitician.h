//
// Created by ilay on 1/9/23.
//

#ifndef ASS5_FINAL_REPUBLICANPOLITICIAN_H
#define ASS5_FINAL_REPUBLICANPOLITICIAN_H
#include "Politician.h"

class RepublicanPolitician :public Politician {
public:
    RepublicanPolitician(string,string,int,int);
    virtual ~RepublicanPolitician()=0;
};


#endif //ASS5_FINAL_REPUBLICANPOLITICIAN_H
