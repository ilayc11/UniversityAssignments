//
// Created by ilay on 11/27/22.
//

#include "Jerry.h"



Planet * createPlanet(float xT, float yT,float zT,char * nameT){ /*creates a planet by using given variables*/
    if(nameT==NULL)
       return NULL;
    Planet * newP = (Planet *)malloc(sizeof (Planet));
    if(newP==NULL)
        return NULL;
    newP->x=xT;
    newP->y=yT;
    newP->z=zT;
    newP->pName=(char*)malloc(sizeof(strlen(nameT)+1));
    if(newP->pName==NULL) {
        free(newP);
        return NULL;
    }
    strcpy(newP->pName,nameT);
    return newP;
}

void freePlanet(Planet * planT){
    free(planT->pName); /*frees string first then planet itself*/
    free(planT);
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

void freeOrigin(Origin * orgT){


    free(orgT->oName); /*frees name first then origin*/
    free(orgT);
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

void freePhys(PhysicalChar * physT){
    free(physT->physName);
    free(physT);
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
void freeJerry(Jerry * jer) {
    freeOrigin(jer->origin);
    if (jer->phyNum != 0) {
    for (int i = 0; i < jer->phyNum; i++) {
        freePhys(jer->physArray[i]);
    }
}
    free(jer->physArray);
    free(jer->id);
    free(jer);
}
boolean checkPhysExists(Jerry * jer ,char * phys){ /*checks if a phys char exists in a jerry, true if is else false*/
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
void printPlanet(Planet * plan){/*prints planet*/
    printf("Planet : %s (%.2f,%.2f,%.2f) \n",plan->pName,plan->x,plan->y,plan->z);
}

void printJerry(Jerry * jer){/*prints jerry*/
    printf("Jerry , ID - %s : \n",jer->id);
    printf("Happiness level : %d \n",jer->happy);
    printf("Origin : %s \n",jer->origin->oName);
    printPlanet(jer->origin->planet);
    if(jer->phyNum!=0) {
        printf("Jerry's physical Characteristics available : \n\t");
        for (int i = 0; i < jer->phyNum; i++) {
            printf("%s : %.2f",jer->physArray[i]->physName,jer->physArray[i]->value);
            if(i<=jer->phyNum-2){
                printf(" , ");
            }
        }
        printf("\n");
    }

}