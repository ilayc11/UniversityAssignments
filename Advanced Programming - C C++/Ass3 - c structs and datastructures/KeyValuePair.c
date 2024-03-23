//
// Created by ilay on 12/13/22.
//
#include "KeyValuePair.h"

struct t_KeyValuePair{
    Element * key;
    Element * value;

    /*for keys*/
    CopyFunction copyKey;
    FreeFunction freeKey;
    PrintFunction printKey;
    CopyFunction copyValue;
    FreeFunction freeValue ;
    PrintFunction printValue;
    EqualFunction equalKey;
};
typedef struct t_KeyValuePair* KeyValuePair;

KeyValuePair createKeyValuePair(CopyFunction copyKey, FreeFunction freeKey, PrintFunction printKey,
                                CopyFunction copyValue,FreeFunction freeValue, PrintFunction printValue,
                                EqualFunction equalKey,Element key,Element value){
    if(key==NULL||value==NULL||copyKey==NULL||freeKey==NULL||printKey==NULL||
    copyValue==NULL||freeValue==NULL||printValue==NULL||equalKey==NULL)
        return NULL;
    KeyValuePair new=(KeyValuePair)malloc(sizeof (struct t_KeyValuePair));
    new->copyKey=copyKey;
    new->freeKey=freeKey;
    new->printKey=printKey;
    new->equalKey=equalKey;
    new->copyValue=copyValue;
    new->freeValue=freeValue;
    new->printValue=printValue;
    new->key=key;
    new->value=value;
    return new;
}
status destroyKeyValuePair(KeyValuePair elem){
    if(elem==NULL||elem->key==NULL||elem->value==NULL)
        return failure;
    if(elem->key!=NULL)
        elem->freeKey(elem->key);
    if(elem->value!=NULL)
        elem->freeValue(elem->value);
    free(elem);
    return success;
}

status displayValue(KeyValuePair elem){
    if(elem==NULL)
        return failure;
    elem->printValue(elem->value);
    return success;
}
status displayKey(KeyValuePair elem){
    if(elem==NULL)
        return failure;
    elem->printKey(elem->key);
    return success;
}

Element getValue(KeyValuePair elem){
    if(elem==NULL)
        return NULL;
    return elem->value;
}
Element getKey(KeyValuePair elem){
    if(elem==NULL)
        return NULL;
    return elem->key;
}
bool isEqualKey(KeyValuePair kvp,Element elem){
    if(kvp==NULL||elem==NULL)
        return false;
    if(kvp->equalKey(kvp->key,elem)==true)
        return true;
    return false;
}
