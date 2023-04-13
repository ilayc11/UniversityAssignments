//
// Created by ilay on 12/15/22.
//

#ifndef ASSIGMENT_3_MULTIVALUEHASHTABLE_H
#define ASSIGMENT_3_MULTIVALUEHASHTABLE_H
#include "Defs.h"

typedef struct MVHT_s* MultiValueHashTable;
MultiValueHashTable createMultiValueHashTable (CopyFunction copyKey, FreeFunction freeKey, PrintFunction printKey,
                                               CopyFunction copyValue,FreeFunction freeValue, PrintFunction printValue,
                                               EqualFunction equalKey, TransformIntoNumberFunction transformIntoNumber, int ,EqualFunction equalValue);/*creates MultiValueHash using given functions and by using hashtable functionality 
											    added elements are shallow copied so the user wont delete
																	the elements after adding it*/
status destroyMultiValueHashTable(MultiValueHashTable);/*destroys hash includimg elements*/
status addToMultiValueHashTable(MultiValueHashTable,Element key,Element value);
Element lookupInMultiValueHashTable(MultiValueHashTable , Element key);
status removeFromMultiHashTable(MultiValueHashTable , Element key,Element value);
status displayMultiValueHashElementsByKey(MultiValueHashTable ,Element key);
#endif //ASSIGMENT_3_MULTIVALUEHASHTABLE_H
