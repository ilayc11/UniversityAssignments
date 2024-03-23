//
// Created by ilay on 11/27/22.
//

#ifndef DEFS_H /*Adding compilation Guard */
#define DEFS_H
#include "Defs.h"
#include <stdlib.h>
#include <string.h>

typedef struct Planet_t {
    float x,y,z;
    char * pName;
}Planet;

typedef struct Origin_t{
    Planet * planet;
    char * oName;
}Origin;

typedef struct PhysicalCharacteristics_t{
    char * physName;
    float value;
}PhysicalChar;

typedef struct Jerry_t{
    char * id;
    int happy;
    Origin * origin;
    PhysicalChar ** physArray;
    int phyNum;
}Jerry;

Planet * createPlanet(float , float ,float ,char * ); /*creates and returns a pointer to a planet */
Origin * createOrigin(Planet * ,char * ); /*creates and returns origin by getting a pointer to an already created planet*/
PhysicalChar * createPhys(char *  , float ); /*creates and returns a phys char*/
Jerry * createJerry(char * ,int ,char * ,Planet * ); /*creates and returns a Jerry, the func gets an already created planet to be used in the creation of Jerry*/

boolean checkPhysExists(Jerry * ,char * ); /*checks if a phys char exists in a jerry and returns boolean accordingly*/
status addPhys(Jerry * ,PhysicalChar * ); /*adds a phys char to a given jerry, returns success if ok else failure*/
status deletePhys(Jerry * ,char * );/*deletes a phys char from a jerry , returns success if ok else failure*/

void printPlanet(Planet * );/*prints planet*/
void printJerry(Jerry * );/*prints jerrys*/

void freePlanet(Planet * ); /*gets a planet pointer and frees it*/
void freeOrigin(Origin * ); /*gets an origin and frees it*/
void freePhys(PhysicalChar * ); /*gets a phys char and frees it*/
void freeJerry(Jerry * ); /*gets a jerry and free everytinhg related to it except the planet */
#endif