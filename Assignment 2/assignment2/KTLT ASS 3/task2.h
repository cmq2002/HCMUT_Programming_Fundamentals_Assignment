//
//  task2.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//

#ifndef task2_h
#define task2_h

#include "SLLDataController.h"
#include "thirdBattle.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

void solveTask2 (string filename){
    SLinkedList list;
    ifstream file(filename);
    string tmp = "";
    getline(file, tmp);
    int task2 = stoi(tmp);
    
    while(task2){
        vector<string> cmd;
        getline(file,tmp);
        cmd = tokenize(tmp);
        if (cmd[0]=="EN"){
            Soldier soldier(stoi(cmd[1]),stoi(cmd[2]),cmd[3]);
            cout << enqueue(list,soldier) << endl;
        }
        else if (cmd[0] == "DE"){
            cout << dequeue(list) << endl;
        }
        else if (cmd[0] == "FRONT"){
            if (!list.size) {
                cout << "List is empty" << endl;
            }
            else {
                cout << "ID: " << front(list).ID << "\nHP: " << front(list).HP << "\nisSpecial:" << front(list).isSpecial<<endl;
            }
        }
        task2--;
    }
}


#endif /* task2_h */
