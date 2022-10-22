//
//  thirdBattle.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//
// Students can remove the final initial return of the functions

#ifndef thirdBattle_h
#define thirdBattle_h

#include "SLLDataController.h"
#include "ArrayDataController.h"
#include <vector>
#include <string>

//////////////////////////////////////////////////////
/// TASK 1
//////////////////////////////////////////////////////

bool push(Array& array, Soldier soldier){
    //Return true if push successfully, false otherwise
    //TODO
    if (array.capacity==0) initArray (array,15);
    else if (array.size >= array.capacity) ensureCapacity(array,array.capacity);
    return insertAt(array,soldier,array.size);
}

bool pop(Array& array){
    //Return true if pop successfully, false otherwise
    //TODO
    return removeAt(array,array.size-1);
}

Soldier top(Array& array){
    //TODO
    if ( empty(array)== false ) return array.arr[array.size-1];
    else return Soldier();//return this if cannot get top
}

//////////////////////////////////////////////////////
/// TASK 2
//////////////////////////////////////////////////////

bool enqueue(SLinkedList& list, Soldier soldier){
    //Return true if enqueue successfully, false otherwise
    //TODO
    return insertAt(list,soldier,list.size);
}

bool dequeue(SLinkedList& list){
    //Return true if dequeue successfully, false otherwise
    //TODO
    return removeAt(list,0);
}

Soldier front(SLinkedList& list){
    //TODO
    if (list.head != NULL) return list.head->data;
    else return Soldier();//Return this if cannot get front
}

//////////////////////////////////////////////////////
/// TASK 3
//////////////////////////////////////////////////////

void reverse(SLinkedList& list){
    //TODO
    SoldierNode *prev = NULL;
    SoldierNode *pCurr = list.head;
    SoldierNode *pNext = NULL;
    while (pCurr != NULL){
        pNext = pCurr->next;
        pCurr->next = prev;
        prev = pCurr;
        pCurr = pNext;
    }
    list.head = prev;
}

//////////////////////////////////////////////////////
/// TASK 4
//////////////////////////////////////////////////////

SLinkedList merge(SLinkedList& list1, SLinkedList& list2){
    //TODO
    SLinkedList result;
    while (list1.size != 0 && list2.size != 0){
        if (list1.head->data.HP == list2.head->data.HP){
            if (list1.head->data.isSpecial == list2.head->data.isSpecial){
                if (list1.head->data.ID < list2.head->data.ID){
                    insertAt(result,list1.head->data,result.size);
                    removeAt(list1,0);
                }
                else{
                    insertAt(result,list2.head->data,result.size);
                    removeAt(list2,0);
                }
            }
            else {
                if (list1.head->data.isSpecial==false){
                    insertAt(result,list1.head->data,result.size);
                    removeAt(list1,0);
                }
                else{
                    insertAt(result,list2.head->data,result.size);
                    removeAt(list2,0);
                }
            }
        }
        else {
            if (list1.head->data.HP < list2.head->data.HP){
                insertAt(result,list1.head->data,result.size);
                removeAt(list1,0);
            }
            else{
                insertAt(result,list2.head->data,result.size);
                removeAt(list2,0);
            }
        }
    }
    while (list1.size != 0){
        insertAt(result,list1.head->data,result.size);
        removeAt(list1,0);
    }
    while (list2.size != 0){
        insertAt(result,list2.head->data,result.size);
        removeAt(list2,0);
    }
    return result;
}

//You can write your own functions here

//End your own functions

#endif /* thirdBattle_h */
