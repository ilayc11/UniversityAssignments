//
// Created by ilay on 11/27/22.
//

#ifndef DEFS_H /*Adding compilation Guard */
#define DEFS_H

#include "Defs.h"
#include <stdlib.h>
#include <string.h>

typedef struct Planet_t Planet;

typedef struct Origin_t Origin;

typedef struct PhysicalCharacteristics_t PhysicalChar;

typedef struct Jerry_t  Jerry;

Planet * createPlanet(float , float ,float ,char * ); /*creates and returns a pointer to a planet */
Origin * createOrigin(Planet * ,char * ); /*creates and returns origin by getting a pointer to an already created planet*/
PhysicalChar * createPhys(char *  , float ); /*creates and returns a phys char*/
Jerry * createJerry(char * ,int ,char * ,Planet * ); /*creates and returns a Jerry, the func gets an already created planet to be used in the creation of Jerry*/

bool checkPhysExists(Jerry * ,char * ); /*checks if a phys char exists in a jerry and returns boolean accordingly*/
status addPhys(Jerry * ,PhysicalChar * ); /*adds a phys char to a given jerry, returns success if ok else failure*/
status deletePhys(Jerry * ,char * );/*deletes a phys char from a jerry , returns success if ok else failure*/

status printPlanet(Planet * );/*prints planet*/
status printJerry(Jerry * );/*prints jerrys*/
status printPhys(PhysicalChar*);

status freePlanet(Planet * ); /*gets a planet pointer and frees it*/
status freeOrigin(Origin * ); /*gets an origin and frees it*/
status freePhys(PhysicalChar * ); /*gets a phys char and frees it*/
status freeJerry(Jerry * ); /*gets a jerry and free everytinhg related to it except the planet */

char*  getJerryID(Jerry* ); /*returns a jerry id*/
char * getPhysName(PhysicalChar*); /*returns a phys name*/
char * getPlanetName(Planet *); /*returns a planet name*/
int getNumOfPhys(Jerry* ); /*returns a num of phys in a jer*/
int getHappinessLevel(Jerry *); /*returns happiness lvl*/
status setHappinessLevel(Jerry *,int );/*sets happy level*/
PhysicalChar * getPhysByIndex(Jerry *,int); /*returns physical char by index*/

#endif