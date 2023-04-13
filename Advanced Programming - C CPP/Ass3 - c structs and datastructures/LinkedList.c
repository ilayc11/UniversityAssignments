//
// Created by ilay on 12/11/22.
//

#include "LinkedList.h"
typedef struct Node_t{
    Element e;
    struct Node_t* next;
    struct Node_t* prev;
}*Node;


struct t_LinkedList{
    Node head;
    Node tail;
    int numOfElements;
CopyFunction copyFunc;
FreeFunction freeFunc;
PrintFunction printFunc;
EqualFunction equalFunc;
};

LinkedList createLinkedList(CopyFunction copyfunc,FreeFunction freefunc,PrintFunction printfunc,EqualFunction equalfunc){
   if(copyfunc==NULL||freefunc==NULL||printfunc==NULL||equalfunc==NULL)
       return NULL;
    LinkedList ll=(LinkedList)malloc(sizeof (struct t_LinkedList));
    if(ll==NULL)
        return NULL;
    ll->copyFunc=copyfunc;
    ll->equalFunc=equalfunc;
    ll->freeFunc=freefunc;
    ll->printFunc=printfunc;
    ll->head=NULL;
    ll->tail=NULL;
    ll->numOfElements=0;
    return ll;
}
status destroyList(LinkedList list){
    if(list==NULL)
        return failure;
    if(list->numOfElements==0) {
        free(list);
        return success;
    }
    Node tmp=list->head;
    Node tmp2;
    int i;
for(i=0;i<list->numOfElements;i++) {
    tmp2 = tmp->next;
    if (list->freeFunc(tmp->e) == failure)
        return failure;
    free(tmp);
    tmp = tmp2;
}
free(list);
return failure;
}
status appendNode(LinkedList list,Element elem){
    if(list==NULL||elem==NULL)
        return failure;
    Node new=(Node)malloc(sizeof (struct Node_t));
    if(new==NULL)
        return failure;
    new->e=list->copyFunc(elem);
    new->next=NULL;
    new->prev=NULL;
    if(list->numOfElements==0){
        list->head=new;
        list->tail=new;
        list->numOfElements++;
        return success;
    }
    new->prev=list->tail;
    list->tail->next=new;
    list->tail=new;
    list->numOfElements++;
    return success;
}
status deleteNode(LinkedList list,Element elem) {
    if (list == NULL || elem == NULL)
        return failure;
    if (list->numOfElements == 0)
        return failure;
    Node tmp=list->head;
    if(list->numOfElements==1) {
        if (list->equalFunc(tmp->e, elem)==true) {
            list->freeFunc(tmp->e);
            free(tmp);
            list->head=NULL;
            list->tail=NULL;
            list->numOfElements--;
            return success;
        }
    }
    for(int i=0;i<list->numOfElements;i++){
        if(list->equalFunc(tmp->e, elem)==true) {
            if (list->equalFunc(list->tail->e, elem) == true) {
                list->freeFunc(tmp->e);
                tmp->prev->next = NULL;
                list->tail = tmp->prev;
                free(tmp);
                list->numOfElements--;
                return success;
            }
            if (list->equalFunc(list->head->e, elem) == true) {
                list->freeFunc(tmp->e);
                list->head = tmp->next;
                list->head->prev = NULL;
                free(tmp);
                list->numOfElements--;
                return success;
            }
            list->freeFunc(tmp->e);
            tmp->prev->next = tmp->next;
            free(tmp);
            list->numOfElements--;
            return success;
        }
        tmp=tmp->next;
    }

    return failure;
}
status displayList(LinkedList list){
    if(list==NULL)
        return failure;
    Node tmp=list->head;
    for(int i=0;i<list->numOfElements;i++) {
        list->printFunc(tmp->e);
        tmp = tmp->next;
    }
    return success;
}
Element getDataByIndex(LinkedList list,int index){
    if(list==NULL||index<=0||list->numOfElements==0||index>list->numOfElements)
        return NULL;
    if(index==list->numOfElements)
        return list->tail->e;
    if(index==1)
        return list->head->e;
    Node tmp=list->head;
    for(int i=1;i<index;i++)
        tmp=tmp->next;
    return tmp->e;
}
int getLengthList(LinkedList list){
    if(list==NULL)
        return -1;
    return list->numOfElements;
}

Element searchByKeyInList(LinkedList list,Element elem){
    if(list==NULL||elem==NULL)
        return NULL;
    if(list->numOfElements==0)
        return NULL;
    if(list->equalFunc(list->head->e,elem)==true)
        return list->head->e;
    if(list->equalFunc(list->tail->e,elem)==true)
        return list->tail->e;
    Node tmp=list->head;

    for(int i=0;i<list->numOfElements;i++){
        if(list->equalFunc(tmp->e,elem)==true)
            return tmp->e;
        tmp=tmp->next;
    }
    return NULL;
}