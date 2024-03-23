//
// Created by ilay on 11/27/22.
//

#include "Jerry.h"

struct Planet_t {
    float x, y, z;
    char *pName;
};
struct Origin_t {
    Planet *planet;
    char *oName;
};
 struct PhysicalCharacteristics_t {
    char *physName;
    float value;
};
 struct Jerry_t{
    char * id;
    int happy;
    Origin * origin;
    PhysicalChar ** physArray;
    int phyNum;
};

Planet * createPlanet(float xT, float yT,float zT,char * nameT){ /*creates a planet by using given variables*/
    if(nameT==NULL)
       return NULL;
    Planet * newP = (Planet *)malloc(sizeof (Planet));
    if(newP==NULL)
        return NULL;
    newP->x=xT;
    newP->y=yT;
    newP->z=zT;
    newP->pName=(char*)malloc(sizeof(char)*(strlen(nameT)+1));
    if(newP->pName==NULL) {
        free(newP);
        return NULL;
    }
    strcpy(newP->pName,nameT);
    return newP;
}
status freePlanet(Planet * planT){
    if(planT==NULL)
        return failure;
    free(planT->pName); /*frees string first then planet itself*/
    free(planT);
    planT=NULL;
    return success;
}

Origin * createOrigin(Planet * nameP,char * nameT) {/*creates an origin by using given variables*/
    if (nameP == NULL || nameT == NULL)
        return NULL;
    Origin *newOrg = (Origin *) malloc(sizeof(Origin));
    if (newOrg == NULL)
        return NULL;

    newOrg->planet = nameP;

    newOrg->oName = (char *) malloc(sizeof(strlen(nameT) + 1));
    if (newOrg->oName == NULL) {
        free(newOrg);
        return NULL;
    }
    strcpy(newOrg->oName,nameT);
    return newOrg;
}
status freeOrigin(Origin * orgT){

    if(orgT==NULL)
     return failure;
    free(orgT->oName); /*frees name first then origin*/
    free(orgT);
    orgT=NULL;
    return success;
}

PhysicalChar * createPhys(char * nameT ,float valueT){ /*creates a phys char by using given variables*/
    if(nameT==NULL)
        return NULL;

    PhysicalChar * newPhys=(PhysicalChar*)malloc(sizeof(PhysicalChar));
    if(newPhys==NULL)
        return NULL;

    newPhys->value=valueT;

    newPhys->physName=(char*) malloc(sizeof (char)*(strlen(nameT)+1));
    if(newPhys->physName==NULL) {
        free(newPhys);
        return NULL;
    }
    strcpy(newPhys->physName,nameT);
    return newPhys;
}
status freePhys(PhysicalChar * physT){
    if(physT==NULL)
        return failure;
    free(physT->physName);
    free(physT);
    physT=NULL;
    return success;
}

Jerry * createJerry(char * idT,int happyT,char * nameO,Planet *  plant){ /*creates a jerry by using given variables, planet is given as a pointer to an already existing one*/

    if(idT==NULL||nameO==NULL||plant==NULL)
        return NULL;

    Jerry * newJer= ( Jerry *)malloc(sizeof (Jerry));
    if(newJer==NULL)
        return NULL;

    newJer->id=(char*) malloc(sizeof (char)*(strlen(idT)+1));

    if(newJer->id==NULL) {
        free(newJer);
        return NULL;
    }

    strcpy(newJer->id,idT);
    newJer->happy=happyT;
    newJer->origin= createOrigin(plant,nameO);

    if(newJer->origin==NULL) {
        free(newJer->id);
        free(newJer);
        return NULL;
    }
    newJer->phyNum=0;
    newJer->physArray=NULL;
    return newJer;
}
status freeJerry(Jerry * jer) {
    if(jer==NULL)
        return failure;
    if(freeOrigin(jer->origin)==failure)
        return failure;
    if (jer->phyNum != 0) {
    for (int i = 0; i < jer->phyNum; i++) {
        if(freePhys(jer->physArray[i])==failure)
            return failure;
    }
}
    free(jer->physArray);
    free(jer->id);
    free(jer);
    jer=NULL;
    return success;
}
status printPhys(PhysicalChar*phys){
    if(phys==NULL)
        return failure;
    printf("%s : %.2f ",phys->physName,phys->value);
    return success;
}
bool checkPhysExists(Jerry * jer ,char * phys){ /*checks if a phys char exists in a jerry, true if is else false*/
    if(jer->phyNum==0) {
        return false;
    }
    for(int i=0;i<jer->phyNum;i++) {
        if (strcmp(jer->physArray[i]->physName, phys) == 0) {
            return true;
        }
    }
    return false;
}
status addPhys(Jerry * jer ,PhysicalChar * phys ){ /*adds a phys char to a jerry, success if ok failure otherwise*/
    if(checkPhysExists(jer, phys->physName)==true){
        return failure;
    }
    else{
        jer->phyNum++;
        void * check= realloc(jer->physArray,sizeof(PhysicalChar*)*(jer->phyNum));
        if(check==NULL){
            jer->phyNum--;
            return failure;
        }

        jer->physArray=(PhysicalChar **)check;
        jer->physArray[jer->phyNum-1]=phys;
        return success;
    }
}
status deletePhys(Jerry * jer ,char * name ){/*deletes a phys char from a jerry, success if ok failure otherwise*/
    if(jer->phyNum==0) {
        return failure;
    }
    if(checkPhysExists(jer,name)==false)
        return failure;
    if(jer->phyNum==1) {
        freePhys(jer->physArray[0]);
        jer->phyNum=0;
        return success;
    }
    PhysicalChar *ptr=NULL;
    int j=0;
    for(int i=0;i<jer->phyNum;i++) {

        if (strcmp(jer->physArray[i]->physName, name) == 0) {
            ptr=jer->physArray[i];
            break;
        }
        j++;
    }
    if(ptr==NULL)
        return failure;

    if(j==jer->phyNum-1)
        freePhys(jer->physArray[j]);
    else {
        freePhys(jer->physArray[j]);
        for(int i=j;i<jer->phyNum-1;i++)
            jer->physArray[i]=jer->physArray[i+1];
    }
    void *check = realloc(jer->physArray, sizeof(PhysicalChar *) * ((jer->phyNum) - 1));
            if(check==NULL)
                return failure;
            jer->physArray = (PhysicalChar**) check;
            jer->phyNum--;
            return success;
}

status printPlanet(Planet * plan){/*prints planet*/
    if(plan==NULL)
        return failure;
    printf("Planet : %s (%.2f,%.2f,%.2f) \n",plan->pName,plan->x,plan->y,plan->z);
return success;
}
status printJerry(Jerry * jer){/*prints jerry*/
    if(jer==NULL)
        return failure;
    printf("Jerry , ID - %s : \n",jer->id);
    printf("Happiness level : %d \n",jer->happy);
    printf("Origin : %s \n",jer->origin->oName);
    printPlanet(jer->origin->planet);
    if(jer->phyNum!=0) {
        printf("Jerry's physical Characteristics available : \n\t");
        for (int i = 0; i < jer->phyNum; i++) {
            printPhys(jer->physArray[i]);
            if(i<=jer->phyNum-2){
                printf(", ");
            }
        }
        printf("\n");
    }
return success;
}

char*getJerryID(Jerry* jer){
    return jer->id;
}
char * getPhysName(PhysicalChar* phys){
    return phys->physName;
}

char * getPlanetName(Planet * p){ /*returns planet name*/
    return p->pName;
}
PhysicalChar * getPhysByIndex(Jerry *jer,int a) { /*returns physical char by index*/
if(jer==NULL||a<=0||a>jer->phyNum)
    return NULL;
return jer->physArray[a-1];
}
int getNumOfPhys(Jerry* jer){ /*returns number of phys elements*/
    return jer->phyNum;
}
int getHappinessLevel(Jerry * jer){ /*returns happiness lvl*/
 return jer->happy;
}
status setHappinessLevel(Jerry *jer,int a){
    if(jer==NULL)
        return failure;
    jer->happy=a;
    return success;
}
