//
// Created by ilay on 12/11/22.
//

#ifndef ASSIGMENT_3_LINKEDLIST_H
#define ASSIGMENT_3_LINKEDLIST_H
#include "Defs.h"

typedef struct t_LinkedList* LinkedList;



LinkedList createLinkedList(CopyFunction ,FreeFunction ,PrintFunction ,EqualFunction );
/*creates list using functions received, added elements are shallow copied so the user wont delete the elements after adding it*/
status destroyList(LinkedList); /*destroys list including the elements within*/
status appendNode(LinkedList,Element); /*appends a new element into the list, doesnt allocate additional memory for given element*/
status deleteNode(LinkedList,Element); /*deletes a node in the list including the element within*/
status displayList(LinkedList list);/*displays elements in the list using given print function*/
Element getDataByIndex(LinkedList,int);/*gets data by index, first place is index 1*/
int getLengthList(LinkedList);/*gets length of list*/
Element searchByKeyInList(LinkedList,Element);/*searches for element in the list using Equal function*/
#endif //ASSIGMENT_3_LINKEDLIST_H
