//
//  main.cpp
//  STL_libray_testcode
//
//  Created by 전경안 on 2020/02/24.
//  Copyright © 2020 전경안. All rights reserved.
//

#include "Account.h"
using std::cin;
using std::cout;
using std::endl;
void screen();
void signIn(std::list<Account>&);
void signUp(std::list<Account>&);
void menuList(std::list<Account>&);
///입력예외함수///
int inputNum(int,int);
void myflush();
bool cmpString(std::string,std::list<Account>&);
int main() {
    screen();
    return 0;
}

void screen(){
    std::list<Account> aclist;
    int num=-1;
    std::string menu[]={"1.로그인","2.회원가입","3.종료"};
    while(1){
        for(auto a: menu){
            cout << a <<std::endl;
        }
        cout <<"선택 : ";
        cin>>num;
        num = inputNum(num,sizeof(num));
        if(num!=-1){
            switch(num){
                case 1:
                    signIn(aclist);
                    break;
                case 2:
                    signUp(aclist);
                    break;
                default:
                    return;
            }
        }
    }
}
void signIn(std::list<Account>&aclist){
    std::string name;
    cout <<"아이디를 입력해 주세요 : ";
    cin >>name;
    if(!cmpString(name,aclist)){
        cout <<"아이디가 일치하지 않습니다."<<endl;
        return ;
    }
    menuList(aclist);
}
void signUp(std::list<Account>&aclist){
    std::string id,name;
    while(1){
        cout <<"원하는 아이디를 입력하세요 : ";
        cin >> id;
        if(!cmpString(id,aclist)) break;
        cout <<"중복된 아이디 입니다."<<endl;
    }
    cout <<"이름 :";
    cin >>name;
    Account temp(name,id);
    aclist.push_back(temp);
}

void menuList(std::list<Account>&aclist){
    int num=-1;
    std::string menu[]={"1.친구찾기","2.채팅방 입장","3.로그아웃"};
    while(1){
        for(auto a: menu){
            cout <<a<<endl;
        }
        cout <<"선택 : ";
        cin >>num;
        num = inputNum(num,sizeof(menu));
        if(num!=-1){
            switch(num){
                case 1:
                    cout <<"개발 예정"<<endl;
                    break;
                case 2:
                    cout <<"개발 예정"<<endl;
                    break;
                default:
                    return ;
            }
        }
    }
}
bool cmpString(std::string id,std::list<Account>&acr){
    for(auto a: acr){
        if(a.getMyID()==id)return true;
    }
    return false;
}

int inputNum(int num, int max){
    if(cin.fail()){
        myflush();
    }
    else{
        if(0<num&&num<=max){
            return num;
        }
    }
    cout <<"다시 입력해주세요 (1-"<<max<<")"<<endl;
    return -1;
}
void myflush(){
    cin.clear();
    while(cin.get() != '\n'){
        ;
    }
}
