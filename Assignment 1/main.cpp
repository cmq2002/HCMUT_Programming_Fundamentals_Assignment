/*
    * Ho Chi Minh City University of Technology
    * Faculty of Computer Science and Engineering
    * Initial code for Assignment 1
    * Programming Fundamentals Spring 2021
    * Author: Nguyen Thanh Nhan
    * Date: 01.03.2021
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#include "mongol.h"

int readFile(const char *filename, int &NID, int &N1, int &N5, int& k, string *&ID, string *&input1, string *&input2, string *&input3, string *&input4, string *&input5, string *&input6, string *&input7Matrix, string *&input7Str)
{
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    // Because you do not need to submit this main file.
    ifstream myfile(filename);
    if (myfile.is_open())
    {
        string *tmp = new string;
        getline(myfile, *tmp);
        NID = stoi(*tmp);

        ID = new string[NID];
        for (int i = 0; i < NID; i++)
        {
            getline(myfile, ID[i]);
        }

        getline(myfile, *tmp);
        N1 = stoi(*tmp);
        input1 = new string[N1];
        for (int i = 0; i < N1; i++)
        {
            getline(myfile, input1[i]);
        }

        input2 = new string[2];
        getline(myfile, input2[0]);
        getline(myfile, input2[1]);

        input3 = new string;
        getline(myfile, *input3);

        input4 = new string[2];
        getline(myfile, input4[0]);
        getline(myfile, input4[1]);

        getline(myfile, *tmp);
        N5 = stoi(*tmp);
        input5 = new string[N5];
        for (int i = 0; i < N5; i++)
        {
            getline(myfile, input5[i]);
        }

        input6 = new string[10];
        for (int i = 0; i < 10; i++)
        {
            getline(myfile, input6[i]);
        }

        getline(myfile, *tmp);
        k = stoi(*tmp);

        input7Str = new string;
        getline(myfile, *input7Str);

        input7Matrix = new string[k];
        for (int i = 0; i < k; i++)
        {
            getline(myfile, input7Matrix[i]);
        }

        delete tmp;
        return 1;
    }
    else
        return 0;
}

int main(int argc, const char *argv[])
{
    //Breakpoint
    const char *filename = "testcase.txt";

    int NID = -1, N1 = -1, N5 = -1, k = -1;
    string *ID = nullptr;
    string *input1 = nullptr;
    string *input2 = nullptr;
    string *input3 = nullptr;
    string *input4 = nullptr;
    string *input5 = nullptr;
    string *input6 = nullptr;
    string *input7Matrix = nullptr;
    string *input7Str = nullptr;

    bool isRead = readFile(filename, NID, N1, N5, k, ID, input1, input2, input3, input4, input5, input6, input7Matrix, input7Str);

    if (!isRead)
    {
        cout << "File cannot be read!";
        return 1;
    }
    else
    {
        cout << "Answer for task 1: " << readyForBattle(ID, NID, input1, N1) << endl;
        cout << "Answer for task 2: " << decode(input2[0], input2[1]) << endl;
        cout << "Answer for task 3: " << findRoute(*input3) << endl;
        cout << "Answer for task 4: " << decodeVfunction(input4[0], input4[1]) << endl;
        cout << "Answer for task 5: " << findBetrayals(input5, N5) << endl;
        cout << "Answer for task 6: " << attack(input6) << endl;
        cout << "Answer for task 7: " << calculateNoOfWaitingDays(*input7Str, input7Matrix, k) << endl;
    }
    return 0;

}
