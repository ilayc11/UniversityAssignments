//
// Created by ilay on 12/13/22.
//

#ifndef ASSIGMENT_3_KEYVALUEPAIR_H
#define ASSIGMENT_3_KEYVALUEPAIR_H

#include "Defs.h"
typedef struct t_KeyValuePair* KeyValuePair;
KeyValuePair createKeyValuePair(CopyFunction , FreeFunction , PrintFunction ,
                                CopyFunction ,FreeFunction, PrintFunction ,
                                EqualFunction ,Element ,Element); /*creates KeyValuePair using given functions, added elements are shallow copied so the user wont delete
																	the elements after adding it*/
status destroyKeyValuePair(KeyValuePair);/*destroys keyvaluepair including elements within*/
status displayValue(KeyValuePair);/*prints value using print value funcion*/
status displayKey(KeyValuePair);/*prints key using print key function*/
Element getValue(KeyValuePair);/*gets value */
Element getKey(KeyValuePair);/*gets key*/
bool isEqualKey(KeyValuePair,Element);/*checks if the element is the key using equal key function*/
#endif //ASSIGMENT_3_KEYVALUEPAIR_H
