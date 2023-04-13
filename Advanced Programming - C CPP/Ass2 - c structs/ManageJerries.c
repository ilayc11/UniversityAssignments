//
// Created by ilay on 11/27/22.
//

#include "Jerry.h"
#define BUFFSIZE 300 /*to be used in cases of an uknown string length*/

int numOfJerries=0,numOfPlanets=0; /*num of planets and jerries overall given by the user*/
int JerriesIndex=0,PlanetsIndex=0; /*num of planets and jerries that are currently in the arrays*/
Jerry ** arrJer; /*local array to store all the jerries*/
Planet** arrPlan; /*local array to store all planets*/

void memoryProblem(){/*functions that prints the string and exits the program*/
    printf("Memory Problem");
    exit(1);
}
void cleanMem(FILE * fp) {/*gets thrown here if there was a problem in the program memory wise*/
    fclose(fp);
    for(int i=0;i<PlanetsIndex;i++)
        freePlanet(arrPlan[i]);
    free(arrPlan);
    for(int i=0;i<JerriesIndex;i++)
        freeJerry(arrJer[i]);
    free(arrJer);
    memoryProblem();
}

void cleanMem1(){ /*gets thrown here if the user wants to exit the program by input*/
    if(numOfJerries==0&&numOfPlanets==0){
        printf("AW JEEZ RICK, ALL THE JERRIES GOT FREE ! \n");
        exit(0);
    }
    for(int i=0;i<numOfPlanets;i++)
        freePlanet(arrPlan[i]);
    free(arrPlan);
    for(int i=0;i<numOfJerries;i++)
        freeJerry(arrJer[i]);
    free(arrJer);
    printf("AW JEEZ RICK, ALL THE JERRIES GOT FREE ! \n");
    exit(0);
}
void cleanMem2() {/*gets thrown here if there was a problem in the program memory wise*/
    for(int i=0;i<PlanetsIndex;i++)
        freePlanet(arrPlan[i]);
    free(arrPlan);
    for(int i=0;i<JerriesIndex;i++)
        freeJerry(arrJer[i]);
    free(arrJer);
    memoryProblem();
}

Planet * getPlanet(char * text,Planet ** arrPlan){ /*returns the right plant by finding the planet with the right name*/
    if(numOfPlanets==0)
        return NULL;
    for(int i=0;i<numOfPlanets;i++){
        if(strcmp(text,arrPlan[i]->pName)==0)
            return arrPlan[i];
    }
    return NULL;
}
Jerry * getJerry(char * idcpy,Jerry ** arrJer) { /*returns the right jerry by finding the jerry with the right id*/
    if(numOfJerries==0)
        return NULL;
    for (int i = 0; i < numOfJerries; ++i) {
        if (strcmp(arrJer[i]->id, idcpy) == 0) {
            return arrJer[i];
        }
    }
    return NULL;
}

status isAJerry(char * textToConvert,Jerry ** arrJer,Planet ** arrPlan){ /*gets thrown here if the line of text in the file is a line for a jerry, creates a jerry with the given vars*/
    char* array[4];
    char * ptr = strtok(textToConvert,",");
    array[0]=ptr;
    int counter=1;
    while(ptr!=NULL){
        ptr=strtok(NULL ,",");
        array[counter]=ptr;
        counter++;
    }
    int ttmp;
    array[3]=strtok(array[3] ,"\n");
    sscanf(array[3],"%d",&ttmp);
    Jerry * jer0 = createJerry(array[0],ttmp,array[1], getPlanet(array[2],arrPlan));
    if(jer0==NULL)
        return failure;
    arrJer[JerriesIndex]=jer0;
    JerriesIndex++;
    return success;
}
status isAPhys(char * textToConvert,Jerry ** arrJer){/*gets thrown here if the line of text in the file is a line for a phys char , creates a phys char with the given vars to be given to a specific jerry*/

    char* array[2];
    char * ptr =strtok(textToConvert,":");
    array[0]=ptr;
    int counter=1;
    while(ptr!=NULL){
        ptr=strtok(NULL ,",");
        array[counter]=ptr;
        counter++;
    }
    float tmp;
    sscanf(array[1],"%f",&tmp);
    array[0]=strtok(array[0] ,"\t");
    PhysicalChar * tmpphys=createPhys(array[0],tmp);
    if(tmpphys==NULL)
        return failure;
    if(addPhys(arrJer[JerriesIndex-1],tmpphys)==failure)
        return failure;
    return success;
}

status textToPlanet(char * textToConvert,Planet ** arrPlan){/*handles the part in the file that is about the planets, adds them to the arrPlan*/
    char* array[4];
    char * ptr = strtok(textToConvert,",");
    array[0]=ptr;
    int counter=1;
    while(ptr!=NULL){
        ptr=strtok(NULL,",");
        array[counter]=ptr;
        counter++;
    }

    float tx,ty,tz;
    sscanf(array[1],"%f",&tx);
    sscanf(array[2],"%f",&ty);
    sscanf(array[3],"%f",&tz);
    Planet * tmpPlan=createPlanet(tx,ty,tz,array[0]);
    if(tmpPlan==NULL){
        return failure;
    }
    arrPlan[PlanetsIndex]=tmpPlan;
    PlanetsIndex++;
    return success;
}
status textToJerry(char * textToConvert,Jerry ** arrJer,Planet ** arrPlan){ /*handles the part in the file that is about the jerries, adds them to the arrjer*/
    int counter=0;
    char * tmptext= (char*)malloc(sizeof (char)* strlen(textToConvert)+1);
    if(tmptext==NULL){
        return failure;
    }
    strcpy(tmptext,textToConvert);
    char * ptr = strtok(tmptext,",");
    while(ptr!=NULL){
        ptr=strtok(NULL,",");
        counter++;
    }
    if(counter>=4){
        if(isAJerry(textToConvert,arrJer,arrPlan)==failure) /*we are now adding a new jerry*/
            return failure;
    }
    else{
        if( isAPhys(textToConvert,arrJer)==failure) /*we are now adding a new phys char*/
            return failure;
    }
    free(tmptext);
    return success;
}

void printAllJ(Jerry ** arrJer){ /*prints all jerries*/
    for(int i=0;i<numOfJerries;i++)
        printJerry(arrJer[i]);
}
void printAllP(Planet ** arrPlan){ /*prints all planets*/
    for(int i=0;i<numOfPlanets;i++)
        printPlanet(arrPlan[i]);
}

boolean checkJerExists(char * idcpy,Jerry ** arrJer){ /*checks if theres a jerry with that id*/
    for(int i=0;i<numOfJerries;i++)
        if(strcmp(arrJer[i]->id,idcpy)==0)
            return true;
    return false;
}

void findJerryByPlanet(char * planet,Jerry** arrJer,Jerry ** jerjer){/*finds a jerry by the right planet, returns an array with jerries from the specific plnet, we init the array with null and it stays null if didnt find any jerries*/
    int counter=0;
    for(int i=0;i<numOfJerries;i++)
        jerjer[i]=NULL;
    for(int i=0;i<numOfJerries;i++) {
        if (strcmp(arrJer[i]->origin->planet->pName, planet) == 0){
            jerjer[counter]=arrJer[i];
            counter++;
        }
    }
}
void findJerryByPhys(char *name,Jerry ** arrjer,Jerry** jerjer) {/*finds a jerry by the right planet, returns an array with jerries from the specific plnet, we init the array with null and it stays null if didnt find any jerries*/
    int counter = 0;
    for (int i = 0; i < numOfJerries; i++)
        jerjer[i] = NULL;
    for (int i = 0; i < numOfJerries; i++) {
        if (checkPhysExists(arrjer[i], name) == true) {
            jerjer[counter] = arrjer[i];
            counter++;
        }
    }
}

char * convertUPPERcase(char * lower){/*converts a string to all uppercase*/
    for (int i = 0; lower[i] != '\0'; i++) {
        if (lower[i] >= 'a' && lower[i] <= 'z') {
            lower[i] = lower[i] - 32;
        }
    }
    return lower;
}

int main(int argc,char * argv[]){
    sscanf(argv[1],"%d",&numOfPlanets);
    sscanf(argv[2],"%d",&numOfJerries);

    /*allocates memory to the planets array and jerries array by given numbers accordingly*/
    arrJer=(Jerry**)(malloc(sizeof (Jerry*)*numOfJerries));
    if(arrJer==NULL){
        memoryProblem();
    }
    arrPlan=(Planet**)(malloc(sizeof (Planet*)*numOfPlanets));
    if(arrPlan==NULL){
        free(arrJer);
        memoryProblem();
    }

    int planetflag=0;
    int jerryflag=0;

    /* starts reading from the file and converts each line into a planet, a jerry, or a phys char for that jerry*/
    FILE * fp = fopen(argv[3],"r");

    if(fp==NULL){
        free(arrJer);
        free(arrPlan);
        memoryProblem();
    }
    char buffer[BUFFSIZE]; /*buffer to be used for reading lines from the text*/
    while (fgets(buffer, sizeof(buffer), fp)){

        if(jerryflag==1){
            if(textToJerry(buffer,arrJer,arrPlan)==failure)
                cleanMem(fp);
        }


        if(strcmp(buffer,"Jerries\n")==0&&planetflag==1)
            jerryflag=1;

        if(planetflag==1&&jerryflag==0) {
            if (textToPlanet(buffer, arrPlan) == failure)
                cleanMem(fp);
        }
        if(strcmp(buffer,"Planets\n")==0&&jerryflag!=1)
            planetflag=1;


    }
    fclose(fp);
    /*-----------------end of file reading part----------------*/

    /*starting the switch case part for user input*/

    /*extra vars to be used inside the switch case*/
    char ch='1';
    char tmp;
    int inputCounter;
    Jerry * jer;
    Jerry ** jerjer;



    while( ch != '0' ) {
        printf("AW JEEZ RICK, what do you want to do now ? \n");
        printf("1 : Print all Jerries \n");
        printf("2 : Print all Planets \n");
        printf("3 : Add physical characteristic to Jerry \n");
        printf("4 : Remove physical characteristic from Jerry \n");
        printf("5 : Print Jerries by a planet \n");
        printf("6 : Print Jerries by a physical characteristic \n");
        printf("7 : Go home \n");
        scanf(" %c",&ch);
        inputCounter=0;
        tmp=ch;
        while(ch!='\n'){ /*checks if the user input is only one char*/
            ch=getchar();
            inputCounter++;}
        if(inputCounter!=1)
            tmp='a'; /*so it will go to default case*/
        switch( tmp ) {

            case '1':  /* prints all jerries */
                printAllJ(arrJer);
                break;

            case '2':  /* prints all planets */
                printAllP(arrPlan);
                break;

            case '3': /* adds phys char to a jerry */
                printf("What is your Jerry's ID ? \n");
                scanf("%s",buffer);
                jer = getJerry(buffer,arrJer);/*gets the jerry with the right id*/
                if (jer == NULL) {
                    printf("OH NO! I CAN'T FIND HIM RICK ! \n");
                    break;
                }
                printf("What physical characteristic can you add to Jerry - %s ? \n", buffer);
                scanf("%s", buffer);
                if (checkPhysExists(jer, buffer)==true) { /*checks if that phys char already exists*/
                    convertUPPERcase(buffer);
                    printf("RICK I ALREADY KNOW HIS %s ! \n", buffer);
                }
                else {
                    printf("What is the value of his %s ? \n", buffer);
                    float value;
                    scanf("%f", &value);
                    if(addPhys(jer, createPhys(buffer,value))==failure) /*tries adding the phys char to the jerry*/
                        cleanMem2();
                    printJerry(jer);
                }
                break;

            case '4':  /* removes phys char from a jerry */
                printf("What is your Jerry's ID ? \n");
                scanf("%s", buffer);
                jer=getJerry(buffer,arrJer);
                if (jer == NULL) {
                    printf("OH NO! I CAN'T FIND HIM RICK ! \n");
                    break;
                }
                printf("What physical characteristic do you want to remove from Jerry - %s ? \n", buffer);
                scanf("%s", buffer);
                if (checkPhysExists(jer, buffer)==false) { /*checks if that phys char already exists*/
                    convertUPPERcase(buffer);
                    printf("RICK I DON'T KNOW HIS %s ! \n", buffer);
                    break;
                }
                else {
                    if(deletePhys(jer, buffer)==failure)/*tries deleting the phys char from jerry*/
                        cleanMem2();
                    printJerry(jer);
                }
                break;

            case '5':  /* print Jerries by planet */
                printf("What planet is your Jerry from ? \n");
                scanf("%s", buffer);
                jerjer=(Jerry**) malloc(sizeof (Jerry*)*numOfJerries); /*allocates memory for a new jerry array to be used*/
                if(jerjer==NULL)
                    cleanMem2();
                findJerryByPlanet(buffer,arrJer,jerjer);
                if (jerjer[0] == NULL) {
                    convertUPPERcase(buffer);
                    free(jerjer);
                    printf("RICK I NEVER HEARD ABOUT %s ! \n",buffer);
                    break;
                }
                else{
                    int counter=0;
                    while(jerjer[counter]!=NULL){
                        printJerry(jerjer[counter]);
                        counter++;
                    }

                }
                free(jerjer);
                break;

            case '6': /* print Jerries by a phys char */
                printf("What do you know about your Jerry ? \n");
                scanf("%s",buffer);
                jerjer=(Jerry**) malloc(sizeof (Jerry*)*numOfJerries); /*allocates memory for a new jerry array to be used*/
                if(jerjer==NULL)
                    cleanMem2();
                findJerryByPhys(buffer,arrJer,jerjer);
                if(jerjer[0]==NULL){
                    convertUPPERcase(buffer);
                    free(jerjer);
                    printf("OH NO! I DON'T KNOW ANY JERRY'S %s ! \n",buffer);
                    break;
                }
                else{
                    int counter=0;
                    while(jerjer[counter]!=NULL) {
                        printJerry(jerjer[counter]);
                        counter++;
                    }
                }
                free(jerjer);
                break;
            case '7': /* go home function */
                cleanMem1();
                break;

            default:
                printf("RICK WE DON'T HAVE TIME FOR YOUR GAMES \n");
                break;
        }
    }
    return 0;
}
