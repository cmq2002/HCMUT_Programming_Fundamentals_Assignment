//
//  main.cpp
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 16/05/2021.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "task0.h"
#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"

int main(int argc, const char * argv[]) {
    
    Array array;
    SLinkedList list;
    
    string testcase0 = "testcase0.txt";
    string testcase1 = "testcase1.txt";
    string testcase2 = "testcase2.txt";
    string testcase3 = "testcase3.txt";
    string testcase4 = "testcase4.txt";
    
    cout << "TASK 0:" << endl;
    solveTask0(testcase0);
    
    cout << "TASK 1:" << endl;
    solveTask1(testcase1);
    
    cout << "TASK 2:" << endl;
    solveTask2(testcase2);
    
    cout << "TASK 3:" << endl;
    solveTask3(testcase3);
    
    cout << "TASK 4:" << endl;
    solveTask4(testcase4);
    
    return 0;
}
