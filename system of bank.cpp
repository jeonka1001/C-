//
//  main.cpp
//  1-6 oop프로젝트1 은행
//
//  Created by 전경안 on 2020/01/05.
//  Copyright © 2020 전경안. All rights reserved.
// 그 어떤 예외처리없이 짜본 코드
// c++은 처음이라 더 배우고 좋은 코드 짜보도록 노력...


#include <iostream>
using namespace std;

typedef struct {
    int idnumber;
    int money=0;
    char name[20];
}Data;// 계좌 정보를 저장하기 위한 구조체

Data data[1100];//계좌정보를 저장한 배열
int credata=1000;

void select(int);//메뉴
void creat(void);//계좌개설
void input(void);//입금
void output(void);//출금
void printdata(void);
int main() {
    int menu;
    while(1){
        cout<<"----Menu----\n"<<"1.계좌개설\n"<<"2.입금\n"<<"3.출금\n"<<"4.계좌정보 전체 출력\n"<<"5.프로그램 종료\n"<<"선택할 문항의 번호를 입력하세요:";
        cin>>menu;
        if(menu==5){
            break;
        }
        select(menu);
    }
    return 0;
}

void select(int menu){
    switch(menu){
        case 1:
            creat();
            break;
        case 2:
            input();
            break;
        case 3:
            output();
            break;
        case 4:
            printdata();
            break;
    }

}

void creat(){
    cout<<"이름:";
    cin>>data[credata].name;
    data[credata].idnumber=credata;
    cout<<data[credata].name<<" 님 의 계좌 아이디는 "<<data[credata].idnumber<<" 이며 잔액은 "<<data[credata].money<<" 원 입니다."<<endl;
    credata++;
}

void input(){
    int num,money;
    cout<<"입금 할 계좌 아이디를 적어주세요:";
    cin>>num;
    cout<<"입금액 입력:";
    cin>>money;
    data[num].money+=money;
    cout<<"잔액은 "<<data[num].money<<" 원 입니다."<<endl;
}

void output(){
    int num,money;
    cout<<"출금 할 계좌 아이디를 적어주세요:";
    cin>>num;
    cout<<"출금액 입력:";
    cin>>money;
    data[num].money-=money;
    cout<<"잔액은 "<<data[num].money<<" 원 입니다."<<endl;
}

void printdata(){
    for(int i=1000;i<credata;i++){
        cout<<"@ ID: "<<data[i].idnumber<<endl;
        cout<<"  성명: "<<data[i].name<<endl;
        cout<<"  잔액: "<<data[i].money<<" 원"<<endl;
    }
}
