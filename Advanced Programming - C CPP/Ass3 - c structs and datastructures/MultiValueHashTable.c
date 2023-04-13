//
// Created by ilay on 12/15/22.
//
#include "HashTable.h"
#include "MultiValueHashTable.h"
#include "LinkedList.h"
#include "HashTable.h"

struct MVHT_s{
    hashTable table;
    CopyFunction copyValue;
    FreeFunction freeValue;
    PrintFunction printValue;
    PrintFunction printKey;
    EqualFunction equalValue;
};
Element copyKMVP(Element e){
    if(e==NULL)
        return NULL;
    return (LinkedList)e;
}
status freeKMVP(Element e){
    if (e == NULL)
        return failure;
    if(destroyList((LinkedList)e)==failure)
        return failure;
    return success;
}
status printKMVP(Element e){
    if (e==NULL)
        return failure;
    if(displayList((LinkedList)e)==failure)
        return failure;
    return success;
}


MultiValueHashTable createMultiValueHashTable (CopyFunction copyKey, FreeFunction freeKey, PrintFunction printKey,
                                               CopyFunction copyValue,FreeFunction freeValue, PrintFunction printValue,
                                               EqualFunction equalKey, TransformIntoNumberFunction transformIntoNumber, int hashNumber,EqualFunction equalValue) {
    if (copyKey == NULL || freeKey == NULL || printKey == NULL ||
        copyValue == NULL || freeValue == NULL || printValue == NULL || equalKey == NULL ||
        transformIntoNumber == NULL || hashNumber <= 0)
        return NULL;
    MultiValueHashTable new = (MultiValueHashTable) malloc(sizeof(struct MVHT_s));
    if (new == NULL)
        return NULL;
    new->copyValue=copyValue;
    new->freeValue=freeValue;
    new->printValue=printValue;
    new->printKey=printKey;
    new->equalValue=equalValue;
    new->table = createHashTable(copyKey, freeKey, printKey, copyKMVP,freeKMVP ,printKMVP ,equalKey,transformIntoNumber, hashNumber);
    if (new->table == NULL) {
        free(new);
        return NULL;
    }
    return new;
}
status destroyMultiValueHashTable(MultiValueHashTable hashT){
    if(hashT==NULL)
        return failure;
    if(destroyHashTable(hashT->table)==failure)
        return failure;
    free(hashT);
    return success;
}
status addToMultiValueHashTable(MultiValueHashTable hashT,Element key,Element value){
    if(hashT==NULL||key==NULL||value==NULL)
        return failure;
    Element e=lookupInMultiValueHashTable(hashT,key);
    if(e==NULL) {
        LinkedList new= createLinkedList(hashT->copyValue, hashT->freeValue, hashT->printValue, hashT->equalValue);
        if(new==NULL)
            return failure;
        if(appendNode(new,value)==failure)
            return failure;
        if(addToHashTable(hashT->table, key, new)==failure)
            return failure;
        return success;
    }
    if(appendNode((LinkedList) e,value)==failure)
        return failure;
    return success;

}
Element lookupInMultiValueHashTable(MultiValueHashTable hashT, Element key){
    if(hashT==NULL||key==NULL)
        return NULL;
    Element e=lookupInHashTable(hashT->table,key);
    if(e==NULL)
        return NULL;
    return e;
}

status removeFromMultiHashTable(MultiValueHashTable hashT, Element key,Element value) {
    if (hashT == NULL || key == NULL || value == NULL)
        return failure;
    Element e = lookupInMultiValueHashTable(hashT, key);
    if (e == NULL)
        return failure;
    if(deleteNode((LinkedList)e,value)==failure)
        return failure;
    if(getLengthList((LinkedList)e)==0)
        if(removeFromHashTable(hashT->table,key)==failure)
            return failure;
    return success;
}

status displayMultiValueHashElementsByKey(MultiValueHashTable hashT,Element key){
    if(hashT==NULL)
        return failure;
    Element e=lookupInMultiValueHashTable(hashT,key);
    if(e==NULL)
        return failure;
    if(displayList((LinkedList)e)==failure)
        return failure;
    return success;
}

