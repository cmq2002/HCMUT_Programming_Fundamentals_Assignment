//
//  task1.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//

#ifndef task1_h
#define task1_h

#include "ArrayDataController.h"
#include "thirdBattle.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

void solveTask1 (string filename){
    Array array;
    ifstream file(filename);
    string tmp = "";
    getline(file, tmp);
    int task1 = stoi(tmp);
    
    while(task1){
        vector<string> cmd;
        getline(file,tmp);
        cmd = tokenize(tmp);
        if (cmd[0]=="PUSH"){
            Soldier soldier(stoi(cmd[1]),stoi(cmd[2]),cmd[3]);
            cout << push(array,soldier) << endl;
        }
        else if (cmd[0] == "POP"){
            cout << pop(array) << endl;
        }
        else if (cmd[0] == "TOP"){
            if (!array.size) {
                cout << "Array is empty" << endl;
            }
            else {
                cout << "ID: " << top(array).ID << "\nHP: " << top(array).HP << "\nisSpecial:" << top(array).isSpecial<<endl;
            }
        }
        task1--;
    }
}


#endif /* task1_h */
