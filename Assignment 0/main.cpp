/*
    * Ho Chi Minh City University of Technology
    * Faculty of Computer Science and Engineering
    * Initial code for Assignment 1
    * Programming Fundamentals Spring 2021
    * Author: Nguyen Thanh Nhan
    * Date: 08.02.2021
*/

//The library here is concretely set, students are not allowed to include any other libraries.

#include "firstFight.h"
using namespace std;

int readFile(string filename, int& HP1, int& HP2, int& ID1, int& ID2, int& M1, int& M2, int& E1, int& E2, int& E3, int& E4) {
//This function is used to read the input file,
//DO NOT MODIFY THIS FUNTION
    ifstream myfile(filename);
    if (myfile.is_open()) {
        myfile >> HP1 >> HP2;
        myfile >> ID1 >> ID2;
        myfile >> M1 >> M2;
        myfile >> E1 >> E2 >> E3 >> E4;
        return 1;
    }
    else return 0;
}

int main(int argc, const char * argv[]) {
    string filename = "testcase.txt";
    int HP1 = -1, HP2 = -1;
    int ID1 = -1, ID2 = -1;
    int M1 = -1, M2 = -1;
    int E1 = -1, E2 = -1, E3 = -1, E4 = -1;
    bool isRead = readFile(filename, HP1, HP2, ID1, ID2, M1, M2, E1, E2, E3, E4);
    if (isRead){
        //Task 1
        cout << getReady(HP1, ID1, M1, E1) << endl;
        cout << getReady(HP2, ID2, M2, E1) << endl;
        //Task 2
        cout << firstBattle(HP1, HP2, ID1, ID2, E2)<< endl;
        cout << HP1 << " "<< HP2 << " "<< endl;
        //Task 3
        cout << secondBattle(HP1, HP2, ID1, ID2, E3)<< endl;
        cout << HP1 << " "<< HP2 << " "<< endl;
        //Task 4
        cout << finalBattle(HP1, HP2, ID1, ID2, E4)<< endl;
        cout << HP1 << " "<< HP2 << " "<< endl;
    }
    else{
        cout << "Cannot read input file";
    }
    return 0;
}
