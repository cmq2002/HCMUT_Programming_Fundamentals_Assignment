/*
    * Ho Chi Minh City University of Technology
    * Faculty of Computer Science and Engineering
    * Initial code for Assignment 0
    * Programming Fundamentals Spring 2021
    * Author: Nguyen Thanh Nhan
    * Date: 08.02.2021
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef firstFight_h
#define firstFight_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////
int getReady(int& HP, const int& ID, int& M, const int& E1){
    //Complete this function to gain point on task 1
    if(E1<100 || E1>500)
        return -999;
    else{
        // 1st Case
        int h,J;
        h = (E1-100)%64;
        J = HP%100;
        if (100<=E1 && E1<=199){
            if (ID==0){
                if (J>h){
                    if (HP>=500 && (M%2)!=0)
                        if (M>=300){
                            HP+=50;
                            M-=300;
                        }
                    if ((M%2)==0)
                        if (M>=200){
                            HP+=25;
                            M-=200;
                        }
                  }
            }
            if (ID==1)
                HP=HP+50+25;
        }


        // 2nd Case
        int x; x=(E1%4)+1;
        if (200<=E1 && E1<=299){
            if (ID==0){
                if((M%2)!=0)
                    switch (x){
                        case 1: {if (M>=190) {HP+=5;M-=190;} break;}
                        case 2: break;
                        case 3: {if (M>=200) {HP+=9;M-=200;} break;}
                        case 4: break;
                        default: break;
                    }
                if ((M%2)==0)
                    switch (x){
                        case 1: break;
                        case 2: {if (M>=195) {HP+=7;M-=195;} break;}
                        case 3: break;
                        case 4: {if (M>=205) {HP+=11;M-=205;} break;}
                        default: break;
                }
            }
            if ((ID==1 || ID==2) || (ID==1 && ID==2))
                switch (x){
                    case 1: {if (M>=190) {HP+=5;M-=190;} break;}
                    case 2: {if (M>=195) {HP+=7;M-=195;} break;}
                    case 3: {if (M>=200) {HP+=9;M-=200;} break;}
                    case 4: {if (M>=205) {HP+=11;M-=205;} break;}
                    default: break;
            }
        }


        //3rd Case
        int n,a; n=(E1%10); // n is the last digit of E1
        int flag=0;
        if (n==0 || n==1) a=1;
        if (n>=2){
            for (int i=2; i<=sqrt(n); i++)
                if ((n%i)==0) flag++;
            if (flag==0) a=2*n;
            else a=1;
        }
        int n1; n1=(HP%10); //n1 is the last digit of HP
        int flag1=0;
        if (300<=E1 && E1<=399){
            if (ID==0 || ID==2){
                if (HP>=600){
                    if (n1==0 || n1==1)
                        if (M>=300){
                            HP=ceil((double)HP*(100+a)/100);
                            M-=300;
                        }
                    if (n1>=2){
                        for (int i=2; i<=sqrt(n1);i++)
                            if ((n1%i)==0) flag1++;
                        if (flag1==0)
                            if (M>=500){
                                HP=ceil((double)HP*(100+2*a)/100);
                                M-=500;
                            }
                        if (flag1!=0)
                            if (M>=300){
                                HP=ceil((double)HP*(100+a)/100);
                                M-=300;
                            }
                    }
                }
            }
            if (ID==1){
                if (HP>=600){
                    if (n1==0 || n1==1)
                        if (M>=300){
                            HP=ceil((double)HP*(100+a)/100);
                            M-=300;
                        }
                    if (n1>=2){
                        for (int i=2; i<=sqrt(n1);i++)
                            if ((n1%i)==0) flag1++;
                        if (flag1==0)
                            if (M>=500){
                                HP+=200;
                                M-=500;
                            }
                        if (flag1!=0)
                            if (M>=300){
                                HP=ceil((double)HP*(100+a)/100);
                                M-=300;
                           }
                    }
                }
            }
        }


        //4th Case
        if (400<=E1 && E1<=499)
            if ((E1%5)==0)
                HP=ceil((double)HP*90/100);


        //5th Case
        if (E1==500){
            HP=ceil((double)HP*3/4);
            M=ceil((double)M*3/4);
        }


        //To ensure that HP & M is always in [0;1000] if calculations make the value out of range
        if (M<0) M=0;
        else if (M>1000) M=1000;
        if (HP<0) HP=0;
        else if (HP>1000) HP=1000;
    }
    return (HP+M);
}

int firstBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E2){
    //Complete this function to gain point on task 2
    if (E2<100 || E2>499)
        return -999;
    else{
        double u,HP1_temp,HP2_temp;
        //1st Case
        if (100<=E2 && E2<=199){
            HP1_temp=ceil(HP1*(1.1-0.00001));
            HP2_temp=ceil(HP2*(1.3-0.00001));
            if (HP1_temp<0) HP1_temp=0;
            else if (HP1_temp>1000) HP1_temp=1000;
            if (HP2_temp<0) HP2_temp=0;
            else if (HP2_temp>1000) HP2_temp=1000;
            u=ceil(2*HP1_temp*HP2_temp/(HP1_temp+HP2_temp));
            if(ID1==0 && ID2==0){
                HP1=HP1_temp-abs(HP2_temp-u);
                HP2=HP2_temp-abs(HP1_temp-u);
                if (HP1<0) HP1=0;
                else if (HP1>1000) HP1=1000;
                if (HP2<0) HP2=0;
                else if (HP2>1000) HP2=1000;
                if (HP1>HP2){
                    HP1=ceil((double)HP1*80/100); //5th Case's condition
                    return 1;
                }
                else if (HP1<HP2){
                        HP1=ceil((double)HP1*80/100); //5th Case's condition
                        return -1;
                }
                else if (HP1==HP2){
                        HP1=ceil((double)HP1*80/100); //5th Case's condition
                        return 0;
                }
            }
            if (ID1==1 && ID2==2){
                HP1=ceil(HP1_temp*(0.8-0.00001)); //5th Case's condition
                HP2=HP2_temp;
                if (HP1<0) HP1=0;
                else if (HP1>1000) HP1=1000;
                if (HP2<0) HP2=0;
                else if (HP2>1000) HP2=1000;
                return 0;
            }
            if (ID1==1 && ID2==0){
                HP1=ceil(HP1_temp*(0.8-0.00001)); //5th Case's condition
                HP2=0;
                if (HP1<0) HP1=0;
                else if (HP1>1000) HP1=1000;
                return 1;
            }
            if (ID1==0 && ID2==2){
                HP1=0;
                HP2=HP2_temp;
                if (HP2<0) HP2=0;
                else if (HP2>1000) HP2=1000;
                return -1;
            }
        }


        //2nd Case
        if (200<=E2 && E2<=299){
            HP1_temp=ceil(HP1*(1.7-0.00001));
            HP2_temp=ceil(HP2*(1.2-0.00001));
            if (HP1_temp<0) HP1_temp=0;
            else if (HP1_temp>1000) HP1_temp=1000;
            if (HP2_temp<0) HP2_temp=0;
            else if (HP2_temp>1000) HP2_temp=1000;
            u=ceil(2*HP1_temp*HP2_temp/(HP1_temp+HP2_temp));
            if(ID1==0 && ID2==0){
                HP1=HP1_temp-abs(HP2_temp-u);
                HP2=HP2_temp-abs(HP1_temp-u);
                if (HP1<0) HP1=0;
                else if (HP1>1000) HP1=1000;
                if (HP2<0) HP2=0;
                else if (HP2>1000) HP2=1000;
                if (HP1>HP2){
                    HP1=ceil((double)HP1*80/100); //5th Case's condition
                    return 1;
                }
                else if (HP1<HP2){
                        HP1=ceil((double)HP1*80/100); //5th Case's condition
                        return -1;
                }
                else if (HP1==HP2){
                        HP1=ceil((double)HP1*80/100); //5th Case's condition
                        return 0;
                }
            }
            if (ID1==1 && ID2==2){
                HP1=ceil(HP1_temp*(0.8-0.00001)); //5th Case's condition
                HP2=HP2_temp;
                if (HP1<0) HP1=0;
                else if (HP1>1000) HP1=1000;
                if (HP2<0) HP2=0;
                else if (HP2>1000) HP2=1000;
                return 0;
            }
            if (ID1==1 && ID2==0){
                HP1=ceil(HP1_temp*(0.8-0.00001)); //5th Case's condition
                HP2=0;
                if (HP1<0) HP1=0;
                else if (HP1>1000) HP1=1000;
                return 1;
            }
            if (ID1==0 && ID2==2){
                HP1=0;
                HP2=HP2_temp;
                if (HP2<0) HP2=0;
                else if (HP2>1000) HP2=1000;
                return -1;
            }
        }


        //3rd Case
        if (300<=E2 && E2<=399){
            if (E2<350) HP1_temp=HP1+30;
            else HP1_temp=HP1+(E2%100);
            if (HP1_temp<0) HP1_temp=0;
            else if (HP1_temp>1000) HP1_temp=1000;
            if (HP2<0) HP2=0;
            else if (HP2>1000) HP2=1000;
            u=ceil(2*HP1_temp*HP2/(HP1_temp+HP2));
            if(ID1==0 && ID2==0){
                HP1=HP1_temp-abs(HP2-u);
                HP2-=abs(HP1_temp-u);
                if (HP1<0) HP1=0;
                else if (HP1>1000) HP1=1000;
                if (HP2<0) HP2=0;
                else if (HP2>1000) HP2=1000;
                if (HP1>HP2){
                    HP1=ceil((double)HP1*80/100); //5th Case's condition
                    return 1;
                }
                else if (HP1<HP2){
                        HP1=ceil((double)HP1*80/100); //5th Case's condition
                        return -1;
                }
                else if (HP1==HP2){
                        HP1=ceil((double)HP1*80/100); //5th Case's condition
                        return 0;
                }
            }
            if (ID1==1 && ID2==2){
                HP1=ceil(HP1_temp*(0.8-0.00001)); //5th Case's condition
                if (HP1<0) HP1=0;
                else if (HP1>1000) HP1=1000;
                if (HP2<0) HP2=0;
                else if (HP2>1000) HP2=1000;
                return 0;
            }
            if (ID1==1 && ID2==0){
                HP1=ceil(HP1_temp*(0.8-0.00001)); //5th Case's condition
                HP2=0;
                if (HP1<0) HP1=0;
                else if (HP1>1000) HP1=1000;
                return 1;
            }
            if (ID1==0 && ID2==2){
                HP1=0;
                if (HP2<0) HP2=0;
                else if (HP2>1000) HP2=1000;
                return -1;
            }
        }


        //4th Case
        if (400<=E2 && E2<=499){
            HP1_temp=ceil(HP1*(1.3-0.00001));
            HP2_temp=ceil(HP2*(0.8-0.00001));
            if (HP1_temp<0) HP1_temp=0;
            else if (HP1_temp>1000) HP1_temp=1000;
            if (HP2_temp<0) HP2_temp=0;
            else if (HP2_temp>1000) HP2_temp=1000;
            HP1_temp=ceil(HP1_temp/2);
            u=ceil(2*HP1_temp*HP2_temp/(HP1_temp+HP2_temp));
            if(ID1==0 && ID2==0){
                HP1=HP1_temp-abs(HP2_temp-u);
                HP2=HP2_temp-abs(HP1_temp-u);
                if (HP1<0) HP1=0;
                else if (HP1>1000) HP1=1000;
                if (HP2<0) HP2=0;
                else if (HP2>1000) HP2=1000;
                if (HP1>HP2){
                    HP1=ceil((double)HP1*80/100); //5th Case's condition
                    return 1;
                }
                else if (HP1<HP2){
                        HP1=ceil((double)HP1*80/100); //5th Case's condition
                        return -1;
                }
                else if (HP1==HP2){
                        HP1=ceil((double)HP1*80/100); //5th Case's condition
                        return 0;
                }
            }
            if (ID1==1 && ID2==2){
                HP1=ceil(HP1_temp*(0.8-0.00001)); //5th Case's condition
                HP2=HP2_temp;
                if (HP1<0) HP1=0;
                else if (HP1>1000) HP1=1000;
                if (HP2<0) HP2=0;
                else if (HP2>1000) HP2=1000;
                return 0;
            }
            if (ID1==1 && ID2==0){
                HP1=ceil(HP1_temp*(0.8-0.00001)); //5th Case's condition
                HP2=0;
                if (HP1<0) HP1=0;
                else if (HP1>1000) HP1=1000;
                return 1;
            }
            if (ID1==0 && ID2==2){
                HP1=0;
                HP2=HP2_temp;
                if (HP2<0) HP2=0;
                else if (HP2>1000) HP2=1000;
                return -1;
            }
        }
    }
    return -1;
}

int secondBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E3){
    //Complete this function to gain point on task 3
    if (E3<100 || E3>299)
        return -999;
    else{
        double u,HP1_temp,HP2_temp;
        HP1_temp=ceil(HP1*(1.4-0.00001));
        HP2_temp=ceil(HP2*(1.6-0.00001));
        if (HP1_temp<0) HP1_temp=0;
        else if (HP1_temp>1000) HP1_temp=1000;
        if (HP2_temp<0) HP2_temp=0;
        else if (HP2_temp>1000) HP2_temp=1000;

        //1st Case
        if(100<=E3 && E3<=199){
           if (ID1==0 && ID2==0){
               HP2_temp=ceil(HP2_temp*95/100);
               u=ceil(2*HP1_temp*HP2_temp/(HP1_temp+HP2_temp));
               HP1=HP1_temp-abs(HP2_temp-u);
               HP2=HP2_temp-abs(HP1_temp-u);
               if (HP1<0) HP1=0;
               else if (HP1>1000) HP1=1000;
               if (HP2<0) HP2=0;
               else if (HP2>1000) HP2=1000;
               if (HP1>HP2) return 1;
               else if (HP1==HP2) return 0;
               else if (HP1<HP2){
                    HP1=HP1_temp;
                    if (HP1<0) HP1=0;
                    else if (HP1>1000) HP1=1000;
                    return -1;
               }
            }
            if (ID1==1 && ID2==2){
                HP1=HP1_temp*2;
                HP2=HP2_temp;
                if (HP1<0) HP1=0;
                else if (HP1>1000) HP1=1000;
                if (HP2<0) HP2=0;
                else if (HP2>1000) HP2=1000;
                return 0;
            }
            if (ID1==1 && ID2==0){
                HP1=HP1_temp*2;
                HP2=0;
                if (HP1<0) HP1=0;
                else if (HP1>1000) HP1=1000;
                return 1;
            }
            if (ID1==0 && ID2==2){
                HP1=HP1_temp;
                HP2=HP2_temp;
                if (HP1<0) HP1=0;
                else if (HP1>1000) HP1=1000;
                if (HP2<0) HP2=0;
                else if (HP2>1000) HP2=1000;
                return -1;
           }
        }


        //2nd Case
        if (200<=E3 && E3<=299){
            if (ID1==0 && ID2==0) {HP1=HP1_temp; HP2=ceil(HP2_temp*95/100);}
            if (ID1==1 && ID2==2) {HP1=HP1_temp*2; HP2=HP2_temp;}
            if (ID1==1 && ID2==0) {HP1=HP1_temp*2; HP2=ceil(HP2_temp*95/100);}
            if (ID1==0 && ID2==2) {HP1=HP1_temp; HP2=HP2_temp;}
            if (HP1<0) HP1=0;
            else if (HP1>1000) HP1=1000;
            if (HP2<0) HP2=0;
            else if (HP2>1000) HP2=1000;
            return 0;
        }
    }
    return -1;
}


int finalBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E4){
    //Complete this function to gain point on task 4
    if (E4<100 || E4>299)
        return -999;
    else{
        //1st Case
        if (100<=E4 && E4<=199){
            if (ID2==0)
                HP2=ceil((double)HP2*10/100);
            else if (ID2==2)
                HP2=ceil((double)HP2*30/100);
            if (HP1<0) HP1=0;
            else if (HP1>1000) HP1=1000;
            if (HP2<0) HP2=0;
            else if (HP2>1000) HP2=1000;
            return 0;
        }


        //2nd Case
        if (200<=E4 && E4<=299){
            HP2=0;
            if (HP1<0) HP1=0;
            else if (HP1>1000) HP1=1000;
            return 1;
        }
    }
    return -1;
}
////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* firstFight_h */
