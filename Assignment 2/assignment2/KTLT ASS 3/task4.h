//
//  task4.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//

#ifndef task4_h
#define task4_h
#include "SLLDataController.h"
#include "thirdBattle.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

void solveTask4 (string filename){
    SLinkedList list1, list2;
    ifstream file(filename);
    string tmp = "";
    getline(file, tmp);
    int task4 = stoi(tmp);
    while (task4){
        vector<string> cmd;
        getline(file,tmp);
        cmd = tokenize(tmp);
        
        insertAt(list1, Soldier(stoi(cmd[0]),stoi(cmd[1]),cmd[2]), list1.size);
        
        task4--;
    }
    
    getline(file, tmp);
    task4 = stoi(tmp);
    while (task4){
        vector<string> cmd;
        getline(file,tmp);
        cmd = tokenize(tmp);
        
        insertAt(list2, Soldier(stoi(cmd[0]),stoi(cmd[1]),cmd[2]), list2.size);
        
        task4--;
    }
    
    SLinkedList res = merge(list1, list2);
    print(res);
}

#endif /* task4_h */
