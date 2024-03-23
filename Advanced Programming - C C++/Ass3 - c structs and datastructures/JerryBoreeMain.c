//
// Created by ilay on 12/16/22.
//
#include "Jerry.h"
#include "MultiValueHashTable.h"
#include "HashTable.h"
#include "LinkedList.h"
#define BUFFSIZE 300

int numOfPlanets=0;
int PlanetsIndex=0;

Planet ** arrPlanet; //array of planets
Jerry * lastJerAddedPtr; //points to last added jerry for adding phys chars

MultiValueHashTable PNameKeyJerryIDVal; //phys char name as key jerry as value
hashTable JerryIDKeyJerryVal; //jerry id as key jerry as value
LinkedList AllJerries; //list of all jerries in system
int hashSize;

Element copyJerryToSend(Element e){
    if(e==NULL)
        return NULL;
    return (Jerry*)e;
}
status freeJerryToSend(Element e){
    if(e==NULL)
        return failure;
    Jerry *jerjer=(Jerry*)e;
    if(freeJerry(jerjer)==failure)
        return failure;
    return success;
}
status printJerryToSend(Element e){
    if(e==NULL)
        return failure;
    if(printJerry((Jerry*)e)==failure)
        return failure;
    return success;
}
bool equalJerryToSend(Element e1,Element e2){
    if(e1==NULL||e2==NULL)
        return false;
    if(strcmp(getJerryID((Jerry*)e1),(char*)e2)==0)
        return true;
    return false;
}

Element copyKeyForHT(Element e){
    if(e==NULL)
        return NULL;
    return (char*)e;
}
status freeKeyForHT(Element e){
    if(e==NULL)
        return failure;
    char * tmp =(char*)e;
    free((char*)e);
    return success;
}
status printKeyForHT(Element e){
    if(e==NULL)
        return failure;
    printf("%s : \n",(char*)e);
    return success;
}
bool equalKeyForHT(Element e1,Element e2){
    if(e1==NULL||e2==NULL)
        return false;
    if(strcmp((char*)e1,(char*)e2)==0)
        return true;
    return false;
}

int transformIntoNumberFromMain(Element e){
    if(e==NULL)
        return -1;
    int sum=0;
    for(int i=0;i <strlen((char*)e);i++)
        sum+=(int)(((char*)e)[i]);
    return sum;
}

status ghostPrintFunc(Element e){ //fake print function
    if(e==NULL)
        return failure;
    return success;
}
status ghostFreeFunc(Element e){ //fake free function
    if(e==NULL)
        return failure;
    return success;
}

void memoryProblem(){/*functions that prints the string and exits the program*/
    printf("Memory Problem");
    exit(1);
}
void cleanMem(FILE * fp) {/*gets thrown here if there was a problem in the program memory wise*/
    fclose(fp);
    for(int i=0;i<PlanetsIndex;i++)
        freePlanet(arrPlanet[i]);
    free(arrPlanet);
    memoryProblem();
}
Planet * getPlanet(char * text){ /*returns the right plant by finding the planet with the right name*/
    if(numOfPlanets==0)
        return NULL;
    for(int i=0;i<numOfPlanets;i++){
        if(strcmp(text,getPlanetName(arrPlanet[i]))==0)
            return arrPlanet[i];
    }
    return NULL;
}

status isAPhys(char * textToConvert){ //if text line is phys char
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
    if(addPhys(lastJerAddedPtr,tmpphys)==failure)
        return failure;
    return success;
}
status isAJerry(char * textToConvert){ //if text line is jerry
    char * array[4];
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
    Jerry * jer = createJerry(array[0],ttmp,array[1], getPlanet(array[2]));
    if(jer==NULL)
        return failure;
    lastJerAddedPtr=jer;
    if(appendNode(AllJerries,jer)==failure)
        return failure;
    return success;
}

status textToJerry (char * textToConvert ) { //converts text line to jerry in system
    int counter = 0;
    char *tmptext = (char *) malloc(sizeof(char) * strlen(textToConvert) + 1);
    if (tmptext == NULL)
        return failure;
    strcpy(tmptext, textToConvert);
    char *ptr = strtok(tmptext, ",");
    while (ptr != NULL) {
        ptr = strtok(NULL, ",");
        counter++;
    }
    if (counter >= 4) {
        if (isAJerry(textToConvert) == failure)
            return failure;
    }
    else {
        if (isAPhys(textToConvert) == failure)
            return failure;
    }
    free(tmptext);
    return success;
}
status textToPlanet(char * textToConvert){/*handles the part in the file that is about the planets, adds them to the arrPlan*/
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
    arrPlanet[PlanetsIndex]=tmpPlan;
    PlanetsIndex++;
    return success;
}
//isPrime and nextPrime are both functions used to fined closest bigger prime number,for good hash table size. Copied from internet
bool isPrime(int n) {

    if (n <= 1) return false;
    if (n <= 3) return true;

    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
int nextPrime(int N)
{
    // Base case
    if (N <= 1)
    return 2;
    int prime = N;
    bool found = false;

    // Loop continuously until isPrime returns
    // true for a number greater than n
    while (!found) {
        prime++;

        if (isPrime(prime))
        found = true;
    }
    return prime;
}

int main(int argc,char * argv[]){
    if(argc==1) {
        printf("problem with arguments");
        return 0;
    }
    //------------------------------------------------First part of the main, reading from file and adding to system------------------------------------------
    sscanf(argv[1],"%d",&numOfPlanets);
    arrPlanet=(Planet**)malloc(sizeof (Planet*)*numOfPlanets);
    if(arrPlanet==NULL)
        memoryProblem();
    int planetflag=0;
    int jerryflag=0;
    FILE * fp = fopen(argv[2],"r");
    if(fp==NULL){
        free(arrPlanet);
        memoryProblem();
    }
    AllJerries= createLinkedList(copyJerryToSend,freeJerryToSend,printJerryToSend,equalJerryToSend);
    char buffer[BUFFSIZE];
    while (fgets(buffer, sizeof(buffer), fp)){

        if(jerryflag==1)
            if(textToJerry(buffer)==failure)
                cleanMem(fp);

        if(strcmp(buffer,"Jerries\n")==0&&planetflag==1)
            jerryflag=1;

        if(planetflag==1&&jerryflag==0)
            if (textToPlanet(buffer) == failure)
                cleanMem(fp);

        if(strcmp(buffer,"Planets\n")==0&&jerryflag!=1)
            planetflag=1;
    }
    fclose(fp);
    //----------------------after reading from file and adding all to AllJerries, adding now to hashTables---------------------
    hashSize= nextPrime(getLengthList(AllJerries));
    JerryIDKeyJerryVal= createHashTable(copyKeyForHT,freeKeyForHT,ghostPrintFunc,copyJerryToSend,ghostFreeFunc,printJerryToSend,equalKeyForHT,transformIntoNumberFromMain,
                                        hashSize);
    PNameKeyJerryIDVal= createMultiValueHashTable(copyKeyForHT,freeKeyForHT,printKeyForHT,copyJerryToSend,ghostFreeFunc,printJerryToSend,equalKeyForHT,transformIntoNumberFromMain,
                                                hashSize,equalKeyForHT);
    /*adds the jerries to hashTable by id*/
    for(int i=0;i< getLengthList(AllJerries);i++) {
        Jerry * jer=getDataByIndex(AllJerries, i + 1);
        char * tmpName=(char*)malloc(sizeof (char)* (strlen(getJerryID(jer))+1)); //allocating memory for jerry id so when we free a jerry first we wont have a problem freeing his name
        if(tmpName==NULL)
            memoryProblem();
        strcpy(tmpName,getJerryID(jer));
        addToHashTable(JerryIDKeyJerryVal, tmpName,jer);
    }
    /*adds the jerries to MultiValueHash by phys name*/
    for(int i=0;i< getLengthList(AllJerries);i++) {
        Jerry *jer = getDataByIndex(AllJerries, i + 1);
        for (int k = 0; k < getNumOfPhys(jer); k++) {
            char* tmpNoMemAlloc=getPhysName(getPhysByIndex(jer,k+1));
            if(lookupInMultiValueHashTable(PNameKeyJerryIDVal,tmpNoMemAlloc)==NULL) {
                char *tmp = (char *) malloc(sizeof(char) * (strlen(tmpNoMemAlloc) + 1));
                strcpy(tmp, tmpNoMemAlloc);
                addToMultiValueHashTable(PNameKeyJerryIDVal, tmp, jer);
            }
            else{
                addToMultiValueHashTable(PNameKeyJerryIDVal, tmpNoMemAlloc, jer);
            }
        }
    }

    /*END OF READING FROM FILE AND ADDING ALL ELEMENTS TO THEIR RIGHT PLACE*/

    //SECOND PART OF THE MAIN STARTS HERE
    Jerry * jer;
    Jerry * jer2;
    LinkedList listHolder;
    char ch[BUFFSIZE];
    int intHolder;
    float floatHolder;
    char tmp;
    while(true) {
        printf("Welcome Rick, what are your Jerry's needs today ? \n");
        printf("1 : Take this Jerry away from me \n");
        printf("2 : I think I remember something about my Jerry \n");
        printf("3 : Oh wait. That can't be right \n");
        printf("4 : I guess I will take back my Jerry now \n");
        printf("5 : I can't find my Jerry. Just give me a similar one \n");
        printf("6 : I lost a bet. Give me your saddest Jerry \n");
        printf("7 : Show me what you got \n");
        printf("8 : Let the Jerries play \n");
        printf("9 : I had enough. Close this place \n");
        scanf(" %s", ch);
        tmp=ch[0];
        if(strlen(ch)!=1)
            tmp='a';
            switch (tmp) {
                case '1':
                    printf("What is your Jerry's ID ? \n");
                    scanf("%s",buffer);
                    jer=lookupInHashTable(JerryIDKeyJerryVal,buffer);

                    if(jer!=NULL) {
                        printf("Rick did you forgot ? you already left him here ! \n");
                        break;
                    }
                    char * JerNameHolder=(char*)malloc(sizeof (char)*(strlen(buffer)+1));
                    if(JerNameHolder==NULL)
                        memoryProblem();
                    strcpy(JerNameHolder,buffer);
                    printf("What planet is your Jerry from ? \n");
                    scanf("%s",buffer);
                    Planet * p= getPlanet(buffer);

                    if(p==NULL) {
                        printf("%s is not a known planet ! \n", buffer);
                        free(JerNameHolder);
                        break;
                    }
                    printf("What is your Jerry's dimension ? \n");
                    scanf("%s",buffer);
                    printf("How happy is your Jerry now ? \n");
                    scanf("%d",&intHolder);
                    jer=createJerry(JerNameHolder,intHolder,buffer,p);
                    addToHashTable(JerryIDKeyJerryVal,JerNameHolder,jer);
                    appendNode(AllJerries,jer);
                    printJerry(jer);
                    break;

                case '2':
                    printf("What is your Jerry's ID ? \n");
                    scanf("%s",buffer);
                    jer=lookupInHashTable(JerryIDKeyJerryVal,buffer);
                    if(jer==NULL) {
                        printf("Rick this Jerry is not in the daycare ! \n");
                        break;
                    }
                    printf("What physical characteristic can you add to Jerry - %s ? \n",buffer);
                    scanf("%s",buffer);
                    if(checkPhysExists(jer,buffer)==true) {
                        printf("The information about his %s already available to the daycare ! \n", buffer);
                        break;
                    }

                    printf("What is the value of his %s ? \n",buffer);
                    scanf("%f",&floatHolder);
                    PhysicalChar * physHolder=createPhys(buffer,floatHolder);
                    if(physHolder==NULL)
                        memoryProblem();
                    addPhys(jer,physHolder);
                    LinkedList tmpList=lookupInMultiValueHashTable(PNameKeyJerryIDVal,buffer);
                    if(tmpList!=NULL)
                        appendNode(tmpList,jer);
                    else{
                        char *PhysNameHolder = (char *) malloc(sizeof(char) * (strlen(buffer) + 1));
                        if (PhysNameHolder == NULL)
                            memoryProblem();
                        strcpy(PhysNameHolder, buffer);
                        addToMultiValueHashTable(PNameKeyJerryIDVal,PhysNameHolder,jer);
                    }
                    printf("%s : \n",buffer);
                    displayMultiValueHashElementsByKey(PNameKeyJerryIDVal,buffer);
                    break;
                case '3':
                    printf("What is your Jerry's ID ? \n");
                    scanf("%s",buffer);
                    jer=lookupInHashTable(JerryIDKeyJerryVal,buffer);
                    if(jer==NULL) {
                        printf("Rick this Jerry is not in the daycare ! \n");
                        break;
                    }
                    printf("What physical characteristic do you want to remove from Jerry - %s ? \n",buffer);
                    scanf("%s",buffer);
                    if(checkPhysExists(jer,buffer)==false) {
                        printf("The information about his %s not available to the daycare ! \n", buffer);
                        break;
                    }
                    deletePhys(jer,buffer);
                    removeFromMultiHashTable(PNameKeyJerryIDVal,buffer, jer);
                    printJerry(jer);
                    break;
                case '4':
                    printf("What is your Jerry's ID ? \n");
                    scanf("%s",buffer);
                    jer=lookupInHashTable(JerryIDKeyJerryVal,buffer);
                    if(jer==NULL) {
                        printf("Rick this Jerry is not in the daycare ! \n");
                        break;
                    }
                    for(int i=0;i<getNumOfPhys(jer);i++)
                        removeFromMultiHashTable(PNameKeyJerryIDVal, getPhysName(getPhysByIndex(jer,i+1)),jer);
                    removeFromHashTable(JerryIDKeyJerryVal,getJerryID(jer));
                    deleteNode(AllJerries,getJerryID(jer));
                    printf("Rick thank you for using our daycare service ! Your Jerry awaits ! \n");
                    break;
                case '5':
                    printf("What do you remember about your Jerry ? \n");
                    scanf("%s",buffer);
                    listHolder=(LinkedList)lookupInMultiValueHashTable(PNameKeyJerryIDVal,buffer);
                    if(listHolder==NULL) {
                        printf("Rick we can not help you - we do not know any Jerry's %s ! \n",buffer);
                        break;
                    }
                    printf("What do you remember about the value of his %s ? \n",buffer);
                    scanf("%d",&intHolder);
                    jer=getDataByIndex(listHolder, 1);
                    int distance= abs(getHappinessLevel(jer)-intHolder);
                    for(int i=1;i<getLengthList(listHolder);i++){
                        jer2=getDataByIndex(listHolder,i+1);
                        int tmpAbs=abs(getHappinessLevel(jer2)-intHolder);
                        if(tmpAbs<distance){
                            distance=tmpAbs;
                            jer=jer2;
                        }
                    }
                    printf("Rick this is the most suitable Jerry we found : \n");
                    printJerry(jer);
                    for (int i=0;i< getNumOfPhys(jer);i++)
                        removeFromMultiHashTable(PNameKeyJerryIDVal, getPhysName(getPhysByIndex(jer,i+1)),jer);
                    removeFromHashTable(JerryIDKeyJerryVal,getJerryID(jer));
                    deleteNode(AllJerries,getJerryID(jer));

                    printf("Rick thank you for using our daycare service ! Your Jerry awaits ! \n");
                    break;

                case '6':
                    if(getLengthList(AllJerries)==0) {
                        printf("Rick we can not help you - we currently have no Jerries in the daycare ! \n");
                        break;
                    }
                    jer= getDataByIndex(AllJerries,1);
                    intHolder= getHappinessLevel(jer);
                    for(int i=1;i< getLengthList(AllJerries);i++){
                        jer2=getDataByIndex(AllJerries,i+1);
                        int intHolder2=getHappinessLevel(jer2);
                        if(intHolder2<intHolder){
                            intHolder=intHolder2;
                            jer=jer2;
                        }
                    }
                    printf("Rick this is the most suitable Jerry we found : \n");
                    printJerry(jer);
                    for (int i=0;i< getNumOfPhys(jer);i++)
                        removeFromMultiHashTable(PNameKeyJerryIDVal, getPhysName(getPhysByIndex(jer,i+1)),jer);
                    removeFromHashTable(JerryIDKeyJerryVal,getJerryID(jer));
                    deleteNode(AllJerries,getJerryID(jer));
                    printf("Rick thank you for using our daycare service ! Your Jerry awaits ! \n");
                    break;
                case '7':
                    printf("What information do you want to know ? \n");
                    printf("1 : All Jerries \n");
                    printf("2 : All Jerries by physical characteristics \n");
                    printf("3 : All known planets \n");
                    scanf(" %s", ch);
                    tmp=ch[0];
                    if(strlen(ch)!=1)
                        tmp='a';
                        switch (tmp) {
                            case '1':
                                if(getLengthList(AllJerries)==0) {
                                    printf("Rick we can not help you - we currently have no Jerries in the daycare ! \n");
                                    break;
                                }
                                displayList(AllJerries);
                                break;
                            case '2':
                                printf("What physical characteristics ? \n");
                                scanf("%s",buffer);
                                if(lookupInMultiValueHashTable(PNameKeyJerryIDVal,buffer)==NULL){
                                        printf("Rick we can not help you - we do not know any Jerry's %s ! \n",buffer);
                                        break;
                                    }
                                printf("%s : \n",buffer);
                                displayMultiValueHashElementsByKey(PNameKeyJerryIDVal,buffer);
                                break;
                            case '3':
                                for(int i=0;i<numOfPlanets;i++)
                                    printPlanet(arrPlanet[i]);
                                break;
                            default:
                                printf("Rick this option is not known to the daycare ! \n");
                                break;
                        }
                    break;
                case '8':
                    if(getLengthList(AllJerries)==0){
                        printf("Rick we can not help you - we currently have no Jerries in the daycare ! \n");
                        break;
                    }
                    printf("What activity do you want the Jerries to partake in ? \n");
                    printf("1 : Interact with fake Beth \n");
                    printf("2 : Play golf \n");
                    printf("3 : Adjust the picture settings on the TV \n");
                    scanf(" %s", ch);
                    tmp=ch[0];
                    if(strlen(ch)!=1)
                        tmp='a';
                    switch (tmp) {
                        case '1':
                            for(int i = 0;i<getLengthList(AllJerries);i++){
                                jer=getDataByIndex(AllJerries,i+1);
                                intHolder=getHappinessLevel(jer);
                                if(intHolder>=20) {
                                    if (intHolder + 15 >= 100)
                                        setHappinessLevel(jer, 100);
                                     else
                                        setHappinessLevel(jer, intHolder + 15);
                                }
                                else{
                                    if (intHolder - 5 <= 0)
                                        setHappinessLevel(jer, 0);
                                    else
                                        setHappinessLevel(jer, intHolder - 5);

                                }
                            }
                            printf("The activity is now over ! \n");
                            displayList(AllJerries);
                            break;
                        case '2':
                            for(int i = 0;i<getLengthList(AllJerries);i++){
                                jer=getDataByIndex(AllJerries,i+1);
                                intHolder=getHappinessLevel(jer);
                                if(intHolder>=50) {
                                    if (intHolder + 10 >= 100)
                                        setHappinessLevel(jer, 100);
                                    else
                                        setHappinessLevel(jer, intHolder + 10);
                                }
                                else{
                                    if (intHolder - 10 <= 0)
                                        setHappinessLevel(jer, 0);
                                    else
                                        setHappinessLevel(jer, intHolder - 10);

                                }
                            }
                            printf("The activity is now over ! \n");
                            displayList(AllJerries);
                            break;
                        case '3':
                            for(int i = 0;i<getLengthList(AllJerries);i++){
                                jer=getDataByIndex(AllJerries,i+1);
                                intHolder=getHappinessLevel(jer);
                                    if (intHolder + 20 >= 100)
                                        setHappinessLevel(jer, 100);
                                    else
                                        setHappinessLevel(jer, intHolder + 20);

                            }
                            printf("The activity is now over ! \n");
                            displayList(AllJerries);
                            break;
                        default:
                            printf("Rick this option is not known to the daycare ! \n");
                    }
                    break;
                case '9'://deallocates all data structures by order
                    for(int i=0;i<numOfPlanets;i++)
                        freePlanet(arrPlanet[i]);
                    free(arrPlanet);
                    destroyHashTable(JerryIDKeyJerryVal);
                    destroyMultiValueHashTable(PNameKeyJerryIDVal);
                    destroyList(AllJerries);
                    printf("The daycare is now clean and close ! ");
                    return 0;
                default:
                    printf("Rick this option is not known to the daycare ! \n");
                    break;
        }
    }
    return 0;
}
