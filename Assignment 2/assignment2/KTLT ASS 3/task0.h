//
//  task0.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//

#ifndef task0_h
#define task0_h

#include "SLLDataController.h"
#include "ArrayDataController.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

void solveTask0 (string filename){
    Array array;
    SLinkedList list;
    ifstream file(filename);
    string tmp = "";
    getline(file, tmp);
    int task0 = stoi(tmp);
    
    while(task0){
        vector<string> cmd;
        getline(file,tmp);
        cmd = tokenize(tmp);
        if (cmd[0] == "A"){
            if (cmd[1]=="PRINT"){
                print(array);
            }
            else if (cmd[1]=="INIT"){
                initArray(array, stoi(cmd[2]));
            }
            else if (cmd[1]=="INSERTAT"){
                Soldier soldier(stoi(cmd[3]),stoi(cmd[4]),cmd[5]);
                cout << insertAt(array, soldier, stoi(cmd[2])) << endl;
            }
            else if (cmd[1]=="REMOVEAT"){
                cout << removeAt(array, stoi(cmd[2])) << endl;
            }
            else if (cmd[1]=="REMOVEHP"){
                cout << removeFirstItemWithHP(array, stoi(cmd[2])) << endl;
            }
            else if (cmd[1]=="INDEX"){
                Soldier soldier(stoi(cmd[2]),stoi(cmd[3]),cmd[4]);
                cout << indexOf(array,soldier) << endl;
            }
            else if (cmd[1]=="SIZE"){
                cout << size(array) << endl;
            }
            else if (cmd[1]=="EMPTY"){
                cout << empty(array) << endl;
            }
            else if (cmd[1]=="GETHP"){
                cout << getHPAt(array, stoi(cmd[2])) << endl;
            }
            else if (cmd[1]=="SETHP"){
                cout << setHPAt(array, stoi(cmd[3]), stoi(cmd[2])) << endl;
            }
            else if (cmd[1]=="GETID"){
                cout << getIDAt(array, stoi(cmd[2])) << endl;
            }
            else if (cmd[1]=="CLEAR"){
                clear(array);
            }
            else if (cmd[1]=="CONTAINS"){
                Soldier soldier(stoi(cmd[2]),stoi(cmd[3]),cmd[4]);
                cout << contains(array,soldier) << endl;
            }
        }
        else if (cmd[0]=="L"){
            if (cmd[1]=="PRINT"){
                print(list);
            }
            else if (cmd[1]=="INSERTAT"){
                Soldier soldier(stoi(cmd[3]),stoi(cmd[4]),cmd[5]);
                cout << insertAt(list, soldier, stoi(cmd[2])) << endl;
            }
            else if (cmd[1]=="REMOVEAT"){
                cout << removeAt(list, stoi(cmd[2])) << endl;
            }
            else if (cmd[1]=="REMOVEHP"){
                cout << removeFirstItemWithHP(list, stoi(cmd[2])) << endl;
            }
            else if (cmd[1]=="INDEX"){
                Soldier soldier(stoi(cmd[2]),stoi(cmd[3]),cmd[4]);
                cout << indexOf(list,soldier) << endl;
            }
            else if (cmd[1]=="SIZE"){
                cout << size(list) << endl;
            }
            else if (cmd[1]=="EMPTY"){
                cout << empty(list) << endl;
            }
            else if (cmd[1]=="GETHP"){
                cout << getHPAt(list, stoi(cmd[2])) << endl;
            }
            else if (cmd[1]=="SETHP"){
                cout << setHPAt(list, stoi(cmd[3]), stoi(cmd[2])) << endl;
            }
            else if (cmd[1]=="GETID"){
                cout << getIDAt(list, stoi(cmd[2])) << endl;
            }
            else if (cmd[1]=="CLEAR"){
                clear(list);
            }
            else if (cmd[1]=="CONTAINS"){
                Soldier soldier(stoi(cmd[2]),stoi(cmd[3]),cmd[4]);
                cout << contains(list,soldier) << endl;
            }
        }
        else{
            cout << "INVALID INPUT" << endl;
        }
        task0--;
    }
}

#endif /* task0_h */
