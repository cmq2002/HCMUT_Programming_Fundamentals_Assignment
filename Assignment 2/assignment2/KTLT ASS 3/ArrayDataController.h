//
//  ArrayDataController.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//

// Students can remove the final initial return of the functions

#ifndef ArrayDataController_h
#define ArrayDataController_h

#include "dataStructure.h"
#include <vector>
#include <string>

//Functions used to manage Array
void print(Array& array){
    if (!array.size) {
        std::cout << "Array is empty" << endl;
        return;
    }
    std::cout <<"[";
    for(int i=0;i<array.size;i++){
        std::cout << array.arr[i].ID << " ";
    }
    std::cout <<"]" << endl;
}

void initArray (Array& array, int cap){
    //Init a new array with capacity equals to cap
    //TODO
    if (cap < 0 || array.capacity) return;
    if (!cap) cap = 1;
    array.capacity = cap;
    array.arr = new Soldier[cap];
    array.size = 0;
}

void ensureCapacity(Array& array, int newCap){
    //Extend the capacity of the array
    //TODO
    newCap = array.capacity*1.5 + 1;
    array.capacity = newCap;
    Soldier *arr_temp = new Soldier[array.capacity];
    for (int i=0;i<array.size;i++)
        arr_temp[i] = array.arr[i];
    delete [] array.arr;
    array.arr = NULL;
    array.arr = arr_temp;
}

bool insertAt(Array& array, Soldier element, int pos){
    //Insert element into a pos in the array
    //Return true if insert successfully, false otherwise
    //TODO
    if ( pos < 0 || pos > array.size || array.capacity == 0 ) return false;
    else {
        if (array.size >= array.capacity) ensureCapacity(array,array.capacity);
        array.size++;
        for (int i=array.size-1; i>pos; i--){
            array.arr[i] = array.arr[i-1];
        }
        array.arr[pos] = element;
        return true;
    }
}

bool removeAt (Array& array, int idx){
    //Remove element at index idx in the array
    //Return true if remove successfully, false otherwise
    //TODO
    if (idx < 0 || idx >= array.size || array.size == 0) return false;
    else {
        for (int i=idx; i<array.size-1; i++)
            array.arr[i] = array.arr[i+1];
        array.arr[array.size-1] = Soldier();
        array.size--;
        return true;
    }
}

bool removeFirstItemWithHP (Array& array, int HP){
    //Remove the first element with HP equals to HP
    //Return true if remove successfully, false otherwise
    //TODO
    for (int i=0; i<array.size; i++)
        if (array.arr[i].HP == HP){
            removeAt(array,i);
            return true;
        }
    return false;
}

int indexOf(Array& array, Soldier soldier){
    //Find index of soldier (start from 0)
    //Return -1 if the soldier does not exist
    //TODO
    for (int i=0; i<array.size; i++)
        if (array.arr[i].HP == soldier.HP && array.arr[i].ID == soldier.ID && array.arr[i].isSpecial == soldier.isSpecial)
            return i;
    return -1;
}

int size(Array& array){
    //Return size of the array
    //TODO
    int count = 0;
    for (int i=0; i<array.size; i++){
        count++;
    }
    return count;
}

bool empty(Array& array){
    //Check whether the array is empty
    //TODO
    if (!size(array)) return true;
    else return false;
}

void clear(Array& array){
    //Delete all of the elements in array
    //TODO
    delete [] array.arr;
    array.size = 0;
    array.capacity = 0;
    array.arr = NULL;
}

string getIDAt(Array& array, int pos){
    //Get ID of the Soldier at pos
    //TODO
    for (int i=0; i<array.size; i++)
        if (pos == i)
            return array.arr[i].ID;
    return "-1";
}

int getHPAt(Array& array, int pos){
    //Get HP of the Soldier at pos
    //TODO
    for (int i=0; i<array.size; i++)
        if (pos == i)
            return array.arr[i].HP;
    return -1;
}

bool setHPAt(Array& array, int HP, int pos){
    //Set value of HP at pos
    //TODO
    //Return true if set successfully, false otherwise
    for (int i=0; i<array.size; i++)
        if (pos == i){
            array.arr[i].HP = HP;
            return true;
        }
    return false;
}

bool contains (Array& array, Soldier soldier){
    //Check if array contains soldier
    //TODO
    for (int i=0; i<array.size; i++)
        if (array.arr[i].HP == soldier.HP && array.arr[i].ID == soldier.ID && array.arr[i].isSpecial == soldier.isSpecial)
            return true;
    return false;
}

//You can write your own functions here

//End your own functions

#endif /* ArrayDataController_h */
