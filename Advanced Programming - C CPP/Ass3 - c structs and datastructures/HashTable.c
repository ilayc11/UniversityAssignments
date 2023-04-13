//
// Created by ilay on 12/13/22.
//
#include "HashTable.h"
#include "LinkedList.h"
#include "KeyValuePair.h"

//

struct hashTable_s{
    LinkedList * table;
    int hashSize;
    CopyFunction copyKey;
    FreeFunction freeKey;
    PrintFunction printKey;
    CopyFunction copyValue;
    FreeFunction freeValue ;
    PrintFunction printValue;
    EqualFunction equalKey;
    TransformIntoNumberFunction transformIntoNumber;
};
Element copyKVP(Element e){ /*copy function to send into list*/
    if(e==NULL)
        return NULL;
    return (KeyValuePair)e;
}
status freeKVP(Element e) {/*free function to send into list*/
    if (e == NULL)
        return failure;
    if (destroyKeyValuePair((KeyValuePair) e) == failure)
        return failure;
    return success;
}
status displayKVP(Element e){ /*print function to send into list*/
    if (e==NULL)
        return failure;
    if(displayKey((KeyValuePair) e)==failure)
        return failure;
    if(displayValue((KeyValuePair) e)==failure)
        return failure;
    return success;
}
bool equalKVP(Element e1,Element e2){ /*equal function to send into list*/
    if(e1==NULL||e2==NULL)
        return false;
    if(isEqualKey((KeyValuePair)e1,e2)==true)
        return true;
    return false;
}

hashTable createHashTable(CopyFunction copyKey, FreeFunction freeKey, PrintFunction printKey,
                          CopyFunction copyValue,FreeFunction freeValue, PrintFunction printValue,
                          EqualFunction equalKey, TransformIntoNumberFunction transformIntoNumber, int hashNumber){
    if(copyKey==NULL||freeKey==NULL||printKey==NULL||
       copyValue==NULL||freeValue==NULL||printValue==NULL||equalKey==NULL||transformIntoNumber==NULL||hashNumber<=0)
        return NULL;
    hashTable hashT=(hashTable) malloc(sizeof (struct hashTable_s)); /*creates a array of linked lists*/
    if(hashT==NULL)
        return NULL;
    hashT->table=(LinkedList*)malloc((sizeof (LinkedList))*hashNumber);
    if(hashT->table==NULL) {
        free(hashT);
        return NULL;
    }
    int i;
    for(i=0;i<hashNumber;i++){
        hashT->table[i]= createLinkedList(copyKVP,freeKVP,displayKVP,equalKVP);
        if(hashT->table[i]==NULL)
            break;
    }
    if(i!=hashNumber){
        for(int j=0;j<i;j++)
            destroyList(hashT->table[i]);
        free(hashT->table);
        free(hashT);
        return NULL;
    }
    hashT->copyKey=copyKey;
    hashT->freeKey=freeKey;
    hashT->printKey=printKey;
    hashT->copyValue=copyValue;
    hashT->freeValue=freeValue;
    hashT->printValue=printValue;
    hashT->equalKey=equalKey;
    hashT->hashSize=hashNumber;
    hashT->transformIntoNumber=transformIntoNumber;
    return hashT;
}
int hashFunc(hashTable hasht,Element key){
    int t=hasht->transformIntoNumber(key);
    if(t<0)
        return -1;
    t=t%hasht->hashSize;
    return t;
}
status destroyHashTable(hashTable hashT){
    if(hashT==NULL)
        return failure;
    for(int i=0;i<hashT->hashSize;i++)
        if(destroyList(hashT->table[i])==failure)
            return failure;
    free(hashT->table);
    free(hashT);
    return success;
}
status addToHashTable(hashTable hashT, Element key,Element value){
    if(hashT==NULL||key==NULL||value==NULL)
        return failure;
    if(lookupInHashTable(hashT,key)!=NULL)
        return failure;
    int t= hashFunc(hashT,key);
    if(t==-1)
        return failure;
    KeyValuePair tmp= createKeyValuePair(hashT->copyKey,hashT->freeKey,hashT->printKey,hashT->copyValue
            ,hashT->freeValue,hashT->printValue,hashT->equalKey,key,value);
    if(tmp==NULL)
        return failure;
    appendNode(hashT->table[t],tmp);
    return success;
}

Element lookupInHashTable(hashTable hashT, Element key){
    if(hashT==NULL||key==NULL)
        return NULL;
    int t = hashFunc(hashT,key);
    if(t==-1)
        return NULL;
    KeyValuePair tmp=searchByKeyInList(hashT->table[t],key);
    if(tmp!=NULL)
        return getValue(tmp);
    return NULL;
}

status removeFromHashTable(hashTable hashT, Element key){
    if(hashT==NULL||key==NULL)
        return failure;
    int t= hashFunc(hashT,key);
    if(t==-1)
        return failure;
    if(deleteNode(hashT->table[t],key)==failure)
        return failure;
    return success;
}
status displayHashElements(hashTable hashT){
    if(hashT==NULL)
        return failure;
    for(int i=0;i<hashT->hashSize;i++)
        if(displayList(hashT->table[i])==failure)
            return failure;
    return success;
}