//
// Created by Nhan Nguyen on 01/03/2021.
//
#ifndef MONGOL_H
#define MONGOL_H

// The library here is concretely set, students are not allowed to include any other libraries.

string readyForBattle(const string ID[], const int NID, const string input1[], const int N1);
int decode(const string A, const string B);
string findRoute(const string input3);
string decodeVfunction(const string A, const string B);
string findBetrayals(const string input5[], const int N5);
int attack(const string input6[]);
int calculateNoOfWaitingDays(const string input7Str, const string input7Matrix[], const int k);

////////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER HERE
////////////////////////////////////////////////////////////////////////////
const int MAX_ARRAY_SIZE=999999;
const int MIN = -2147483648;
int recognize (const string ID[], const int NID){
    int flag=0;
    for (int i=0;i<NID;i++){
        if (ID[i].length()==3){
            if (ID[i][0]=='V' && ID[i][1]=='U' && ID[i][2]=='A') flag=1;
            if (ID[i][0]=='T' && ID[i][1]=='H' && ID[i][2]=='D') flag=2;
        }
        if (ID[i].length()>3){
            if (ID[i][0]=='V' && ID[i][1]=='U' && ID[i][2]=='A') flag=1;
            for (unsigned int j=1; j<=(ID[i].length()-1);j++)
                if (ID[i][j]=='T' && ID[i][j+1]=='H' && ID[i][j+2]=='D')
                    flag=2;
        }
    }
    return flag;
}
string readyForBattle(const string ID[], const int NID, const string input1[], const int N1)
{
    string decode1[N1];
    for(int i=0;i<N1;i++){
        for (unsigned int j=0;j<input1[i].length();j++){
            if (input1[i][j]=='0'){
                if (input1[i][j+1]=='0')      decode1[i]+='0';
                else if (input1[i][j+1]=='1') decode1[i]+='1';
                j++;
            }
            else if (input1[i][j]=='1'){
                if (input1[i][j+1]=='0')      decode1[i]+='2';
                else if (input1[i][j+1]=='1') decode1[i]+='3';
                j++;
            }
            else if (input1[i][j]==' ') decode1[i]+=' ';
        }
    }
    //Decode decimal to character
    string decode2[N1];
    for (int i=0;i<N1;i++){
        for (unsigned int j=0;j<decode1[i].length();j++){
        //Decode 0's
            if (decode1[i][j]=='0'){
                if (decode1[i][j+1]!='0')      {decode2[i]+='E';j++;goto chr_1;}
                else if (decode1[i][j+1]==' ') {decode2[i]+='E';j+=2;continue;}
            }
            if (decode1[i][j]=='0' && decode1[i][j+1]=='0'){
                if (decode1[i][j+2]!='0')      {decode2[i]+='F';j+=2;goto chr_1;}
                else if (decode1[i][j+2]==' ') {decode2[i]+='F';j+=3;continue;}
            }
             if (decode1[i][j]=='0' && decode1[i][j+1]=='0' && decode1[i][j+2]=='0'){
                if (decode1[i][j+3]!='0')      {decode2[i]+='G';j+=3;goto chr_1;}
                else if (decode1[i][j+3]==' ') {decode2[i]+='G';j+=4;continue;}
            }
            if (decode1[i][j]=='0' && decode1[i][j+1]=='0' && decode1[i][j+2]=='0' && decode1[i][j+3]=='0'){
                if (decode1[i][j+4]!='0')      {decode2[i]+='H';j+=4;goto chr_1;}
                else if (decode1[i][j+4]==' ') {decode2[i]+='H';j+=5;continue;}
            }
            if (decode1[i][j]=='0' && decode1[i][j+1]=='0' && decode1[i][j+2]=='0' && decode1[i][j+3]=='0' && decode1[i][j+4]=='0'){
                if (decode1[i][j+5]!='0')      {decode2[i]+='I';j+=5;goto chr_1;}
                else if (decode1[i][j+5]==' ') {decode2[i]+='I';j+=6;continue;}
            }
            if (decode1[i][j]=='0' && decode1[i][j+1]=='0' && decode1[i][j+2]=='0' && decode1[i][j+3]=='0' && decode1[i][j+4]=='0' && decode1[i][j+5]=='0'){
                if (decode1[i][j+6]!='0')      {decode2[i]+='J';j+=6;goto chr_1;}
                else if (decode1[i][j+6]==' ') {decode2[i]+='J';j+=7;continue;}
            }
            if (decode1[i][j]=='0' && decode1[i][j+1]=='0' && decode1[i][j+2]=='0' && decode1[i][j+3]=='0' && decode1[i][j+4]=='0' && decode1[i][j+5]=='0' && decode1[i][j+6]=='0'){
                if (decode1[i][j+7]!='0')      {decode2[i]+='K';j+=7;goto chr_1;}
                else if (decode1[i][j+7]==' ') {decode2[i]+='K';j+=8;continue;}
            }
            if (decode1[i][j]=='0' && decode1[i][j+1]=='0' && decode1[i][j+2]=='0' && decode1[i][j+3]=='0' && decode1[i][j+4]=='0' && decode1[i][j+5]=='0' && decode1[i][j+6]=='0' && decode1[i][j+7]=='0'){
                j+=6; continue;
            }
            chr_1:;
        //Decode 1's
            if (decode1[i][j]=='1'){
                if (decode1[i][j+1]!='1')      {decode2[i]+='L';j++;goto chr_2;}
                else if (decode1[i][j+1]==' ') {decode2[i]+='L';j+=2;continue;}
            }
            if (decode1[i][j]=='1' && decode1[i][j+1]=='1'){
                if (decode1[i][j+2]!='1')      {decode2[i]+='M';j+=2;goto chr_2;}
                else if (decode1[i][j+2]==' ') {decode2[i]+='M';j+=3;continue;}
            }
            if (decode1[i][j]=='1' && decode1[i][j+1]=='1' && decode1[i][j+2]=='1'){
                if (decode1[i][j+3]!='1')      {decode2[i]+='N';j+=3;goto chr_2;}
                else if (decode1[i][j+3]==' ') {decode2[i]+='N';j+=4;continue;}
            }
            if (decode1[i][j]=='1' && decode1[i][j+1]=='1' && decode1[i][j+2]=='1' && decode1[i][j+3]=='1'){
                if (decode1[i][j+4]!='1')      {decode2[i]+='O';j+=4;goto chr_2;}
                else if (decode1[i][j+4]==' ') {decode2[i]+='O';j+=5;continue;}
            }
            if (decode1[i][j]=='1' && decode1[i][j+1]=='1' && decode1[i][j+2]=='1' && decode1[i][j+3]=='1' && decode1[i][j+4]=='1'){
                if (decode1[i][j+5]!='1')      {decode2[i]+='P';j+=5;goto chr_2;}
                else if (decode1[i][j+5]==' ') {decode2[i]+='P';j+=6;continue;}
            }
            if (decode1[i][j]=='1' && decode1[i][j+1]=='1' && decode1[i][j+2]=='1' && decode1[i][j+3]=='1' && decode1[i][j+4]=='1' && decode1[i][j+5]=='1'){
                if (decode1[i][j+6]!='1')      {decode2[i]+='Q';j+=6;goto chr_2;}
                else if (decode1[i][j+6]==' ') {decode2[i]+='Q';j+=7;continue;}
            }
            if (decode1[i][j]=='1' && decode1[i][j+1]=='1' && decode1[i][j+2]=='1' && decode1[i][j+3]=='1' && decode1[i][j+4]=='1' && decode1[i][j+5]=='1' && decode1[i][j+6]=='1'){
                if (decode1[i][j+7]!='1')      {decode2[i]+='R';j+=7;goto chr_2;}
                else if (decode1[i][j+7]==' ') {decode2[i]+='R';j+=8;continue;}
            }
            if (decode1[i][j]=='1' && decode1[i][j+1]=='1' && decode1[i][j+2]=='1' && decode1[i][j+3]=='1' && decode1[i][j+4]=='1' && decode1[i][j+5]=='1' && decode1[i][j+6]=='1' && decode1[i][j+7]=='1'){
               j+=6; continue;
            }
            chr_2:;
        //Decode 2's
            if (decode1[i][j]=='2'){
                if (decode1[i][j+1]!='2')      {decode2[i]+='#';j++;goto chr_3;}
                else if (decode1[i][j+1]==' ') {decode2[i]+='#';j+=2;continue;}
            }
            if (decode1[i][j]=='2' && decode1[i][j+1]=='2'){
                if (decode1[i][j+2]!='2')      {decode2[i]+='T';j+=2;goto chr_3;}
                else if (decode1[i][j+2]==' ') {decode2[i]+='T';j+=3;continue;}
            }
            if (decode1[i][j]=='2' && decode1[i][j+1]=='2' && decode1[i][j+2]=='2'){
                if (decode1[i][j+3]!='2')      {decode2[i]+='U';j+=3;goto chr_3;}
                else if (decode1[i][j+3]==' ') {decode2[i]+='U';j+=4;continue;}
            }
            if (decode1[i][j]=='2' && decode1[i][j+1]=='2' && decode1[i][j+2]=='2' && decode1[i][j+3]=='2'){
                if (decode1[i][j+4]!='2')      {decode2[i]+='V';j+=4;goto chr_3;}
                else if (decode1[i][j+4]==' ') {decode2[i]+='V';j+=5;continue;}
            }
            if (decode1[i][j]=='2' && decode1[i][j+1]=='2' && decode1[i][j+2]=='2' && decode1[i][j+3]=='2' && decode1[i][j+4]=='2'){
                if (decode1[i][j+5]!='2')      {decode2[i]+='W';j+=5;goto chr_3;}
                else if (decode1[i][j+5]==' ') {decode2[i]+='W';j+=6;continue;}
            }
            if (decode1[i][j]=='2' && decode1[i][j+1]=='2' && decode1[i][j+2]=='2' && decode1[i][j+3]=='2' && decode1[i][j+4]=='2' && decode1[i][j+5]=='2'){
                if (decode1[i][j+6]!='2')      {decode2[i]+='X';j+=6;goto chr_3;}
                else if (decode1[i][j+6]==' ') {decode2[i]+='X';j+=7;continue;}
            }
            if (decode1[i][j]=='2' && decode1[i][j+1]=='2' && decode1[i][j+2]=='2' && decode1[i][j+3]=='2' && decode1[i][j+4]=='2' && decode1[i][j+5]=='2' && decode1[i][j+6]=='2'){
                if (decode1[i][j+7]!='2')      {decode2[i]+='Y';j+=7;goto chr_3;}
                else if (decode1[i][j+7]==' ') {decode2[i]+='Y';j+=8;continue;}
            }
            if (decode1[i][j]=='2' && decode1[i][j+1]=='2' && decode1[i][j+2]=='2' && decode1[i][j+3]=='2' && decode1[i][j+4]=='2' && decode1[i][j+5]=='2' && decode1[i][j+6]=='2' && decode1[i][j+7]=='2'){
                j+=6; continue;
            }
            chr_3:;
        //Decode 3's
            if (decode1[i][j]=='3'){
                if (decode1[i][j+1]!='3')      {decode2[i]+='@';j++;continue;}
                else if (decode1[i][j+1]==' ') {decode2[i]+='@';j+=2;continue;}
            }
            if (decode1[i][j]=='3' && decode1[i][j+1]=='3'){
                if (decode1[i][j+2]!='3')      {decode2[i]+='A';j+=2;continue;}
                else if (decode1[i][j+2]==' ') {decode2[i]+='A';j+=3;continue;}
            }
            if (decode1[i][j]=='3' && decode1[i][j+1]=='3' && decode1[i][j+2]=='3'){
                if (decode1[i][j+3]!='3')      {decode2[i]+='S';j+=3;continue;}
                else if (decode1[i][j+3]==' ') {decode2[i]+='S';j+=4;continue;}
            }
            if (decode1[i][j]=='3' && decode1[i][j+1]=='3' && decode1[i][j+2]=='3' && decode1[i][j+3]=='3'){
                if (decode1[i][j+4]!='3')      {decode2[i]+='Z';j+=4;continue;}
                else if (decode1[i][j+4]==' ') {decode2[i]+='Z';j+=5;continue;}
            }
            if (decode1[i][j]=='3' && decode1[i][j+1]=='3' && decode1[i][j+2]=='3' && decode1[i][j+3]=='3' && decode1[i][j+4]=='3'){
                if (decode1[i][j+5]!='3')      {decode2[i]+='B';j+=5;continue;}
                else if (decode1[i][j+5]==' ') {decode2[i]+='B';j+=6;continue;}
            }
            if (decode1[i][j]=='3' && decode1[i][j+1]=='3' && decode1[i][j+2]=='3' && decode1[i][j+3]=='3' && decode1[i][j+4]=='3' && decode1[i][j+5]=='3'){
                if (decode1[i][j+6]!='3')      {decode2[i]+='C';j+=6;continue;}
                else if (decode1[i][j+6]==' ') {decode2[i]+='C';j+=7;continue;}
            }
            if (decode1[i][j]=='3' && decode1[i][j+1]=='3' && decode1[i][j+2]=='3' && decode1[i][j+3]=='3' && decode1[i][j+4]=='3' && decode1[i][j+5]=='3' && decode1[i][j+6]=='3'){
                if (decode1[i][j+7]!='3')      {decode2[i]+='D';j+=7;continue;}
                else if (decode1[i][j+7]==' ') {decode2[i]+='D';j+=8;continue;}
            }
            if (decode1[i][j]=='3' && decode1[i][j+1]=='3' && decode1[i][j+2]=='3' && decode1[i][j+3]=='3' && decode1[i][j+4]=='3' && decode1[i][j+5]=='3' && decode1[i][j+6]=='3' && decode1[i][j+7]=='3'){
                j+=6; continue;
            }
        }
    }
    //Decode in case of '#' ; '@,
    string decode3[N1];
    string temp="";
    for (int i=0;i<N1;i++){
        for (unsigned int j=0;j<decode2[i].length();j++){
            if (decode2[i][j]!='@' || decode2[i][j]!='#') decode3[i]+=decode2[i][j];
            if (decode2[i][j]=='@'){
                for(unsigned int k=j+1;k<=decode2[i].length();k++){
                    if (decode2[i][k]=='@' || decode2[i][k]=='#'){
                        for (unsigned int m=j+1 ; m<k ; m++){
                            temp+=decode2[i][m];
                        }
                        int N = temp.length();
                        char swap;
                        for (int x=0; x < N/2; x++){
                            swap = temp[x];
                            temp[x] = temp[N-x-1];
                            temp[N-x-1] = swap;
                        }
                        decode3[i]+=temp;
                        temp = "";
                        j=(k-1);
                        goto special;
                    }
                    else if (k==(decode2[i].length()-1)){
                        for (unsigned int m=j+1 ; m<=k ; m++){
                            temp+=decode2[i][m];
                        }
                        int N = temp.length();
                        char swap;
                        for (int x=0; x<N/2 ; x++){
                            swap = temp[x];
                            temp[x] = temp[N-x-1];
                            temp[N-x-1] = swap;
                        }
                        decode3[i]+=temp;
                        temp="";
                        j=k;
                        goto special;
                    }
                }
            }
            if (decode2[i][j]=='#'){
                for (unsigned int k=j+1 ; k<decode2[i].length() ; k++){
                    if (decode2[i][k]=='@' || decode2[i][k]=='#'){
                        for (unsigned int m=j+1 ; m<k ; m++){
                            temp+=decode2[i][m];
                        }
                        int N = temp.length();
                        char add='\0';
                        if (temp[N-1]!='Z') add = temp[N-1] + 1;
                        else if (temp[N-1]=='Z') add = 'A';
                        temp+=add;
                        decode3[i]+=temp;
                        temp="";
                        j=(k-1);
                        goto special;
                    }
                    else if (k==(decode2[i].length()-1)){
                        for (unsigned int m=j+1 ; m<=k ; m++){
                            temp+=decode2[i][m];
                        }
                        int N = temp.length();
                        char add='\0';
                        if (temp[N-1]!='Z') add = temp[N-1] + 1;
                        else if (temp[N-1]=='Z') add='A';
                        temp+=add;
                        decode3[i]+=temp;
                        temp="";
                        j=k;
                        goto special;
                    }
                }
            }
            special:;
        }
    }
    //Delete '@' and '#'
    string decode4[N1];
    for (int i=0;i<N1;i++){
        for (unsigned int j=0;j<decode3[i].length();j++){
            if (decode3[i][j]=='@' || decode3[i][j]=='#'){
                if (j<(decode3[i].length()-1)) {decode4[i]+=decode3[i][j+1];j++;continue;}
                else if (j==(decode3[i].length()-1)) continue;
            }
            else decode4[i]+=decode3[i][j];
        }
    }
    //Decode when existing King Tran
    int flag = recognize(ID,NID);
    //New string that reverse characters in even position and odd position
    string VUA_rev[N1];
    string temp_V="";
    for (int i=0;i<N1;i++){
        temp_V+=decode4[i];
        int N = temp_V.length();
        char swap_e,swap_o;
        if ((N%2)==1){
            for (int j=0;j<N/2;j+=2){
                swap_e = temp_V[j];
                temp_V[j] = temp_V[N-j-1];
                temp_V[N-j-1] = swap_e;
            }
            for (int j=1;j<N/2;j+=2){
                swap_o = temp_V[j];
                temp_V[j] = temp_V[N-j-1];
                temp_V[N-j-1] = swap_o;
            }
        }
        if ((N%2)==0){
            for (int j=0;j<N/2;j+=2){
                swap_e = temp_V[j];
                temp_V[j] = temp_V[N-j-2];
                temp_V[N-j-2] = swap_e;
            }
            for (int j=1;j<N/2;j+=2){
                swap_o = temp_V[j];
                temp_V[j] = temp_V[N-j];
                temp_V[N-j] = swap_o;
            }
        }
        VUA_rev[i]+=temp_V;
        temp_V="";
    }
    //Compare with the new string and retain larger character
    string VUA_ase[N1];
    for (int i=0;i<N1;i++){
        for (unsigned int j=0;j<VUA_rev[i].length();j++){
            if (VUA_rev[i][j]>decode4[i][j]) VUA_ase[i]+=VUA_rev[i][j];
            if (VUA_rev[i][j]<decode4[i][j]) VUA_ase[i]+=decode4[i][j];
            if (VUA_rev[i][j]==decode4[i][j]) VUA_ase[i]+=decode4[i][j];
        }
    }
    //Decode when existing THD
    string THD[N1];
    string temp_T="";
    //Remove characters in the 3-divisible position
    for (int i=0;i<N1;i++)
        for (unsigned int j=0;j<decode4[i].length();j++){
            if ((j%3)==0) continue;
            else THD[i]+=decode4[i][j];
            }
    //Sort in ascending order
    string THD_asc[N1];
    for (int i=0;i<N1;i++){
        temp_T += THD[i];
        int N = temp_T.length();
        for (int j=0;j<N-1;j++)
            for (int k=j+1;k<N;k++){
                char temp;
                if (temp_T[j]>temp_T[k]){
                    temp = temp_T[j];
                    temp_T[j] = temp_T[k];
                    temp_T[k] = temp;
                }
            }
        THD_asc[i] += temp_T;
        temp_T="";
    }
    //Concatenation of all string elements in the array, separated by a space
    string result="";
    if (flag==0){
        for (int i=0;i<N1;i++){
            if (i<=(N1-2)){
                result += decode4[i];
                result += ' ';
            }
            else if (i==(N1-1)) result += decode4[i];
        }
    }
    else if (flag==1){
        for (int i=0;i<N1;i++){
            if (i<=(N1-2)){
                result += VUA_ase[i];
                result += ' ';
            }
            else if (i==(N1-1)) result += VUA_ase[i];
        }
    }
    else if (flag==2){
        for (int i=0;i<N1;i++){
            if (i<=(N1-2)){
                result += THD_asc[i];
                result += ' ';
            }
            else if (i==(N1-1)) result += THD_asc[i];
        }
    }
    return result;
}



int decode(const string A, const string B)
{
    int count=0;
    int L1 = A.length();
    int L2 = B.length();
    string temp = "";
    for (int i=0;i<=(L1-L2);i++){
        temp = A.substr(i,L2);
        if (temp==B) count++;
        temp = "";
    }
    return count;
}



string findRoute(const string input3)
{
    // Take N,B,S out of input3
    int L = input3.length();
    string N =""; string B=""; string S="";
    int stop = 0;
    int stop1 = 0;
    for (int i=0;i<L;i++){
        if (input3[i]!=' ') N+=input3[i];
        else if (input3[i]==' ') {i++;stop=i;break;}
    }
    for (int i=stop;i<L;i++){
        if (input3[i]!=' ') B+=input3[i];
        else if (input3[i]==' ') {i++;stop1=i;break;}
    }
    for (int i=stop1;i<L;i++){
        S+=input3[i];
    }
    int n = stoi(N);
    int b = stoi(B);
    int SL = S.length();
    // 1st transformation
    string S_1=S;
    if (b>0){
        for (int i=0;i<SL;i++){
            S_1[(i+b)%SL]=S[i];
        }
    }
    else if (b<0){
        int step_back = abs(b) % SL;
        for (int i=0;i<SL;i++){
            S_1[(i+abs(SL-step_back))%SL]=S[i];
        }
    }
    // 2nd transformation
    int step=0;
    int SL1 = S_1.length();
    for (int i=0;i<SL1;i++){
        if (S_1[i]=='U'){
            step = abs(n-2*i);
            if ((step%4)==1) {S_1[i]='D';continue;}
            if ((step%4)==2) {S_1[i]='L';continue;}
            if ((step%4)==3) {S_1[i]='R';continue;}
            if ((step%4)==0) {S_1[i]='U';continue;}
        }
        if (S_1[i]=='D'){
            step = abs(n-2*i);
            if ((step%4)==1) {S_1[i]='L';continue;}
            if ((step%4)==2) {S_1[i]='R';continue;}
            if ((step%4)==3) {S_1[i]='U';continue;}
            if ((step%4)==0) {S_1[i]='D';continue;}
        }
        if (S_1[i]=='L'){
            step = abs(n-2*i);
            if ((step%4)==1) {S_1[i]='R';continue;}
            if ((step%4)==2) {S_1[i]='U';continue;}
            if ((step%4)==3) {S_1[i]='D';continue;}
            if ((step%4)==0) {S_1[i]='L';continue;}
        }
        if (S_1[i]=='R'){
            step = abs(n-2*i);
            if ((step%4)==1) {S_1[i]='U';continue;}
            if ((step%4)==2) {S_1[i]='D';continue;}
            if ((step%4)==3) {S_1[i]='L';continue;}
            if ((step%4)==0) {S_1[i]='R';continue;}
        }
    }
    // Calculate the coordinate
    int x=0,y=0;
    for (unsigned int i=0;i<S_1.length();i++){
        if (S_1[i]=='U') y++;
        if (S_1[i]=='D') y--;
        if (S_1[i]=='L') x--;
        if (S_1[i]=='R') x++;
    }
    // Put x,y into the string form: (x,y)
    string x_chr,y_chr;
    x_chr = to_string(x);
    y_chr = to_string(y);
    string coord_0="(", coord_2="," , coord_4=")";
    string coord=coord_0 + x_chr + coord_2 + y_chr + coord_4;
    return coord;
}



string decodeVfunction(const string A, const string B)
{
    int Va=0,Vb=0;
    for (unsigned int i=0;i<A.length();i++){
        if (A[i]=='V') Va++;
    }
    for (unsigned int i=0;i<B.length();i++){
        if (B[i]=='V') Vb++;
    }
    int prod = Va*Vb;
    char result[MAX_ARRAY_SIZE] = {};
    if (prod==0){
        result[0] = {'0'};
        goto output;
    }
    for (int i=0;i<prod*2;i+=2){
        result[i]='V';
        result[i+1]='(';
    }
    result[prod*2]='0';
    for (int i=prod*2+1;i<MAX_ARRAY_SIZE;i++){
        result[i]=')';
        if (i==prod*3) break;
    }
    output:;
    return result;
}



string findBetrayals(const string input5[], const int N5)
{
   int point[26] = {};
    for (int i=0;i<26;i++){
        point [i] = 0;
    }

    char name[26] = {'Z','Y','X','W','V','U','T','S','R','Q','P','O','N','M','L','K','J','I','H','G','F','E','D','C','B','A'};
    // Calculate point for each name
    for (int i=0;i<N5;i++){
        for (int j=0;j<6;j++){
            for (int k=0;k<26;k++){
                if (input5[i][j] == name[k]) point[k]+=(6-j);
            }
        }
    }
    // Find out top 3 largest point
    int max_1 = point[0];
    for (int i=1;i<26;i++)
        if (point[i]>max_1) max_1 = point[i];
    int max_2 = MIN;
    for (int i=0;i<26;i++)
        if (point[i]>max_2 && point[i]<max_1) max_2 = point[i];
    int max_3 = MIN;
    for (int i=0;i<26;i++)
        if (point[i]>max_3 && point[i]<max_2) max_3 = point[i];
    // Calculate the number of appearance of max_1,max_2,max_3 in point
    string result = "";
    char result_chr[3] = {};
    int i1=0,i2=0,i3=0;
    for (int i=0;i<26;i++){
        if (point[i]==max_1) i1++;
        if (point[i]==max_2) i2++;
        if (point[i]==max_3) i3++;
    }
    // Store the position that equal to max_1, max_2,max_3
    int n1[i1];
    int n2[i2];
    int n3[i3];
    for (int i=0;i<i1;){
         for (int j=0;j<26;j++){
            if (point[j] == max_1) {n1[i]=j;i++;}
         }
    }
    for (int i=0;i<i2;){
         for (int j=0;j<26;j++){
            if (point[j] == max_2) {n2[i]=j;i++;}
         }
    }
    for (int i=0;i<i3;){
         for (int j=0;j<26;j++){
            if (point[j] == max_3) {n3[i]=j;i++;}
         }
    }
    // Find out 3 betrayals
    if (i1>3){
        result_chr[0]=name [n1[i1-1]];
        result_chr[1]=name [n1[i1-2]];
        result_chr[2]=name [n1[i1-3]];
    }
    else if (i1==3) {
        result_chr[0]=name[n1[2]];
        result_chr[1]=name[n1[1]];
        result_chr[2]=name[n1[0]];
    }
    else if (i1==2) {
        result_chr[0]=name[n1[1]];
        result_chr[1]=name[n1[0]];
        if (i2>3)       result_chr[2]=name[n2[i2-1]];
        else if (i2==3) result_chr[2]=name[n2[2]];
        else if (i2==2) result_chr[2]=name[n2[1]];
        else if (i2==1) result_chr[2]=name[n2[0]];
    }
    else if (i1==1){
        result_chr[0]=name[n1[0]];
        if (i2>3){
            result_chr[1]=name[n2[i2-1]];
            result_chr[2]=name[n2[i2-2]];
        }
        else if (i2==3) {
            result_chr[1]=name[n2[2]];
            result_chr[2]=name[n2[1]];
        }
        else if (i2==2) {
            result_chr[1]=name[n2[1]];
            result_chr[2]=name[n2[0]];
        }
        else if (i2==1) {
            result_chr[1]=name[n2[0]];
            if (i3>3)       result_chr[2]=name[n3[i3-1]];
            else if (i3==3) result_chr[2]=name[n3[2]];
            else if (i3==2) result_chr[2]=name[n3[1]];
            else if (i3==1) result_chr[2]=name[n3[0]];
            }
    }
    for (int i=0;i<3;i++){
        result+=result_chr[i];
    }
    return result;
}



int attack(const string input6[])
{
    int num_0[10]={};
    int num_2[10]={};
    int pos[10]={}; int pp = 0, x=0, y=0;
    // Count the number of civilians and elite trooper of each row
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            if (input6[i][j]=='0') x++;
            if (input6[i][j]=='2') y++;
        }
        num_0[i]=x; num_2[i]=y;
        x=0;y=0;
    }
    // Find the maximum civilian among all rows without elite trooper
    int max=0;
    for (int i=0;i<10;i++){
        if (max<num_0[i] && num_2[i]==0)
            max=num_0[i];
    }
    // Put the position of weak rows into an array
    for (int i=0;i<10;i++){
        if (num_0[i]==max && num_2[i]==0) pos[i]=i;
        else pos[i]=-1;
    }
    // Find out the row to attack
    if (pos[0]==-1 && pos[1]==-1 && pos[2]==-1 && pos[3]==-1 && pos[4]==-1 && pos[5]==-1 && pos[6]==-1 && pos[7]==-1 && pos[8]==-1 && pos[9]==-1)
        pp=-1;
    for (int i=0;i<10;i++){
        if (pos[i]!=-1) pp=i;
    }
    return pp;
}



void matrix_build (const string input7Matrix[],int N7, long long arr[100][100], int k_index){
    int N = input7Matrix[k_index].length();
    string temp="";
    temp = input7Matrix[k_index];
    for (int i=0;i<N7;i++){
        for (int j=0;j<N7;j++){
            size_t space = temp.find(' ');
            arr[i][j] = stoi (temp.substr(0,space));
            temp = temp.substr(space+1,N-space);
        }
    }
}
void matrix_multiplication(long long rslt[100][100],long long temp1[100][100],long long temp2[100][100],int N7,long long V){
    for (int i=0;i<N7;i++){
        for (int j=0;j<N7;j++){
            rslt[i][j] = 0;
            for (int k=0;k<N7;k++){
                rslt[i][j] += (temp1[i][k]%V) * (temp2[k][j]%V);
            }
        }
    }
}
void copy_arr(long long temp1[100][100], long long rslt[100][100],int N7){
    for (int i=0;i<N7;i++)
        for (int j=0;j<N7;j++)
            temp1[i][j] = rslt[i][j];
}
long long calculate_R(long long x,long long y){
    long long R = 0;
    long long d = x%y;
    if (d>=0) R=d;
    else if (d<0) R = d + y;
    return R;
}
int calculateNoOfWaitingDays(const string input7Str, const string input7Matrix[], const int k)
{
    //Take the value of N7, V, i,j out of input7Str
    int stop = 0;
    int stop1 = 0;
    int stop2 = 0;
    string n7=""; string v=""; string I=""; string J="";
    for (unsigned int i=0;i<input7Str.length();i++){
        if (input7Str[i]!=' ') n7+=input7Str[i];
        if (input7Str[i]==' ') {i++;stop=i;break;}
    }
    for (unsigned int i=stop;i<input7Str.length();i++){
        if (input7Str[i]!=' ')  v+=input7Str[i];
        if (input7Str[i]==' ') {i++;stop1=i;break;}
    }
    for (unsigned int i=stop1;i<input7Str.length();i++){
        if (input7Str[i]!=' ') I+=input7Str[i];
        if (input7Str[i]==' ') {i++;stop2=i;break;}
    }
    for (unsigned int i=stop2;i<input7Str.length();i++){
        J+=input7Str[i];
    }
    int N7 = stoi(n7);
    long long V = stoi(v);
    int i = stoi(I);
    int j = stoi(J);
    //Perform Matrix's Multiplication
    long long rslt[100][100] = {};
    long long temp1[100][100] = {};
    long long temp2[100][100] = {};
    int k_index = 0;
    matrix_build (input7Matrix,N7,rslt,k_index);
    for (int x = 1;x<k;x++){
        k_index = x;
        matrix_build (input7Matrix,N7,temp2,k_index);
        copy_arr (temp1,rslt,N7);
        matrix_multiplication(rslt,temp1,temp2,N7,V);
    }
    return calculate_R(rslt[i][j],V);
}

#endif /* MONGOL_H */
