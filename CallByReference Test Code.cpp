//
//  main.cpp
//  HW 07_20200205
//
//  Created by 전경안 on 2020/02/05.
//  Copyright © 2020 전경안. All rights reserved.
//

#include <iostream>
using namespace std;

struct Savings{
    int w500;
    int w100;
    int w50;
    int w10;
};
void init(Savings &s);
void input(int &unit,int &cnt);
void save(Savings &s,int unit, int cnt);
int total(Savings &s);

int main(int argc, const char * argv[]) {
    Savings ss;
    int won,num,tot;
    init(ss);
    while(1){
        input(won,num);
        save(ss,won,num);
        if(won ==-1){
            tot = total(ss);
            break;
        }
    }
    cout<<"총 저금액 :"<<tot<<endl;
    return 0;
}
int total(Savings &s){
    s.w500*=500;
    s.w100*=100;
    s.w50*=50;
    s.w10*=10;
    return s.w500+s.w100+s.w50+s.w10;
}
void save(Savings &s, int unit,int cnt){
    switch(unit){
        case 500:
            s.w500+=cnt;
            break;
        case 100:
            s.w100+=cnt;
            break;
        case 50:
            s.w50+=cnt;
            break;
        case 10:
            s.w10+=cnt;
            break;
        default:
            break;
    }
}
void input(int &unit,int &cnt){
    while(1){
        cout<<"동전의 금액(문자 입력시 종료) :";
        cin >> unit;
        if(cin.fail()){
            unit = -1;
            return ;
        }
        else{
            if(unit==500||unit==100||unit==50||unit==10){
                cout<<"동전의 개수 :";
                cin >>cnt;
                if(!cin.fail()&&cnt>=0){
                    break;
                }
            }
        }
    }
}

void init(Savings &s){
    s.w500=0;
    s.w100=0;
    s.w50=0;
    s.w10=0;
}
