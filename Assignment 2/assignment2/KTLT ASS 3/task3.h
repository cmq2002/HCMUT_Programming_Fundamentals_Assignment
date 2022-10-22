//
//  task3.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//

#ifndef task3_h
#define task3_h

#include "SLLDataController.h"
#include "thirdBattle.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

void solveTask3 (string filename){
    SLinkedList list;
    ifstream file(filename);
    string tmp = "";
    getline(file, tmp);
    int task3 = stoi(tmp);
    
    while (task3){
        vector<string> cmd;
        getline(file,tmp);
        cmd = tokenize(tmp);
        
        insertAt(list, Soldier(stoi(cmd[0]),stoi(cmd[1]),cmd[2]), 0);
        
        task3--;
    }
    
    reverse(list);
    print(list);
}

#endif /* task3_h */
