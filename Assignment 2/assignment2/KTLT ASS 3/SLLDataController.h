//
//  SLLDataControler.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//

// Students can remove the final initial return of the functions

#ifndef SLLDataController_h
#define SLLDataController_h

#include "dataStructure.h"
#include <vector>
#include <string>

//Functions used to manage Singly Linked List
void print(SLinkedList& list){
    if (!list.size) {
        std::cout << "List is empty" << endl;
        return;
    }
    SoldierNode* head = list.head;
    while (head){
        std::cout << head->data.ID << "->";
        head = head->next;
    }
    std::cout << "NULL"<<endl;
}

bool insertAt (SLinkedList& list, Soldier element, int pos){
    //Insert element into a pos in the SLL
    //Return true if insert successfully, false otherwise
    //TODO
    if (pos < 0 || pos > list.size) return false;
    else{
        if (pos==0){
            SoldierNode *newNode = new SoldierNode(element,list.head);
            list.head = newNode;
        }
        else{
            SoldierNode *newNode = new SoldierNode(element,NULL);
            SoldierNode *runNode = list.head;
            for (int i=1;i<pos;i++){
                runNode = runNode->next;
            }
            newNode->next = runNode->next;
            runNode->next = newNode;
        }
        list.size++;
        return true;
    }
}

bool removeAt (SLinkedList& list, int idx){
    //Remove element at index idx in the SLL
    //Return true if remove successfully, false otherwise
    //TODO
    if (list.head == NULL || idx<0 || idx >= list.size) return false;
    else{
        if (idx>0){
            SoldierNode* prev = list.head;
            while (idx > 1 && prev->next != nullptr){
                prev = prev->next;
                idx--;
            }
            SoldierNode* p = prev->next;
            if (p) prev->next = p->next;
            delete p;
        }
        else if (idx==0){
            SoldierNode* p = list.head;
            list.head = list.head->next;
            delete p;
        }
        list.size--;
        return true;
    }
}

bool removeFirstItemWithHP (SLinkedList& list, int HP){
    //Remove the first element with HP equals to HP
    //Return true if remove successfully, false otherwise
    //TODO
    SoldierNode* pCurr = list.head;
    int pos = 0;
    while (pCurr != NULL){
        if (pCurr->data.HP == HP){
            removeAt (list,pos);
            return true;
        }
        pos++;
        pCurr = pCurr->next;
    }
    return false;
}

int indexOf(SLinkedList& list, Soldier soldier){
    //Find index of soldier (start from 0)
    //Return -1 if the soldier does not exist
    //TODO
    int pos = 0;
    SoldierNode* pCurr = list.head;
    while (pCurr != NULL){
        if (pCurr->data.ID == soldier.ID && pCurr->data.HP == soldier.HP && pCurr->data.isSpecial == soldier.isSpecial) return pos;
        pos++;
        pCurr = pCurr->next;
    }
    return -1;
}

int size(SLinkedList& list){
    //Return size of the list
    //TODO
    SoldierNode *pCurr = list.head;
    int count = 0;
    while (pCurr != NULL){
        count++;
        pCurr = pCurr->next;
    }
    return count;
}

bool empty(SLinkedList& list){
    //Check whether the list is empty
    //TODO
    if (!size(list)) return true;
    else return false;
}

void clear(SLinkedList& list){
    //Delete all of the elements in list
    //TODO
    SoldierNode *pCurr = list.head;
    while (pCurr != NULL){
        pCurr = pCurr->next;
        delete list.head;
        list.head = pCurr;
    }
    list.size = 0;
    list.head = NULL;
}

string getIDAt(SLinkedList& list, int pos){
    //Get ID of the Soldier at pos
    //TODO
    SoldierNode* head = list.head;
    SoldierNode* pCurr = head;
    int count = 0;
    while (pCurr != NULL){
        if (count == pos) return pCurr->data.ID;
        count++;
        pCurr = pCurr->next;
    }
    return "-1";
}

int getHPAt(SLinkedList& list, int pos){
    //Get HP of the Soldier at pos
    //TODO
    SoldierNode* head = list.head;
    SoldierNode* pCurr = head;
    int count = 0;
    while (pCurr != NULL){
        if (count == pos) return pCurr->data.HP;
        count++;
        pCurr = pCurr->next;
    }
    return -1;
}

bool setHPAt(SLinkedList& list, int HP, int pos){
    //Set value of HP at pos
    //TODO
    //Return true if set successfully, false otherwise
    SoldierNode* pCurr = list.head;
    int count = 0;
    while (pCurr != NULL){
        if (count == pos){
            pCurr->data.HP = HP;
            return true;
        }
        count++;
        pCurr = pCurr->next;
    }
    return false;
}

bool contains (SLinkedList& list, Soldier soldier){
    //Check if array contains soldier
    //TODO
    SoldierNode* head = list.head;
    SoldierNode* pCurr = head;
    int count = 0;
    while (pCurr != NULL){
        if (pCurr->data.HP == soldier.HP && pCurr->data.ID == soldier.ID && pCurr->data.isSpecial == soldier.isSpecial) return true;
        count++;
        pCurr = pCurr->next;
    }
    return false;
}

//You can write your own functions here

//End your own functions

#endif /* SLLDataControler_h */
