//
//  main.cpp
//  STL_libray_testcode
//
//  Created by 전경안 on 2020/02/24.
//  Copyright © 2020 전경안. All rights reserved.
//

#include "Account.h"
#define MAX_LEN 30
using std::cin;
using std::cout;
using std::endl;
///기능함수////
void screen(std::list<Account>&aclist);
void signIn(std::list<Account>&aclist);
void signUp(std::list<Account>&aclist);
void menuList(std::list<Account>&aclist,Account&acr);
void startChat(std::list<Account>&aclist,Account&acr,std::string name);
void findFriend(std::list<Account>&aclist,Account&acr,std::string name);
///입력예외함수///
void inputString(std::string cp,std::string &name);
int inputNum(int num, int max);
void myflush();
bool cmpString(std::string,std::list<Account>&);

int main() {
    std::list<Account> aclist;
    screen(aclist);
    return 0;
}

void screen(std::list<Account>&aclist){
    int num=-1;
    std::string menu[]={"1.로그인","2.회원가입","3.종료"};
    while(1){
        for(auto a: aclist){
            cout << a.getMyID()<< endl;
        }
        for(auto a: menu){
            cout << a <<std::endl;
        }
        cout <<"선택 : ";
        cin>>num;
        num = inputNum(num,sizeof(num));//
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
    std::string id;
    cout <<"아이디를 입력해 주세요 : ";
    cin >>id;
    for(auto &a: aclist){
        if(a.getMyID() == id){
            menuList(aclist,a);
            return ;
        }
    }
    cout << "일치하는 아이디가 없습니다."<<endl;
}
void signUp(std::list<Account>&aclist){
    std::string id,name;
    while(1){
        cout <<"원하는 아이디를 입력하세요 : ";
        cin >> id;
        if(!cmpString(id,aclist))break;
        cout <<"중복된 아이디 입니다."<<endl;
        return ;
    }
    cout <<"이름 :";
    cin >>name;
    aclist.push_back(Account(name,id));
}

void menuList(std::list<Account>&aclist,Account&acr){
    int num=-1;
    int i=1;
    std::string name;
    std::string menu[]={"친구추가","채팅방입장","로그아웃"};
    while(1){
        for(auto a: menu){
            cout<<i++<<"."<<a<<endl;
        }
        i=1;
        cout <<"선택 : ";
        cin >>num;
        num = inputNum(num,sizeof(menu));
        if(num!=-1){
            switch(num){
                case 1:
                    acr.prnChatroom();
                    inputString("추가할",name);
                    findFriend(aclist,acr,name);
                    break;
                case 2:
                    acr.prnChatroom();
                    inputString("채팅할",name);
                    startChat(aclist,acr,name);
                    break;
                default:
                    return ;
            }
        }
    }
}
void startChat(std::list<Account>&aclist,Account& acr,std::string name){
    char mes[MAX_LEN];
    if(!acr.cmpFriend(name)){
        cout <<"존재하지 않는 친구 입니다."<<endl;
        return;
    }
    acr.prnChat(name);
    cout <<"===================="<<endl;
    cout << "보낼 메세지 입력 : ";
    cin.ignore();
    cin.getline(mes,MAX_LEN);
    acr.sendM(name,mes,false);//내가 메시지를 보내기
    for(auto &a: aclist){
        if(a.getMyID()==name){
            a.sendM(acr.getMyID(),mes,true); // 상대가 메시지를 받기
        }
    }
}
void findFriend(std::list<Account>&aclist,Account&acr,std::string name){
    cout <<acr.getMyID()<<"님의 계정"<<endl;
    if(acr.cmpFriend(name)||!cmpString(name,aclist)){
        cout << "친구 추가 실패"<<endl;
        return ;
    }
    acr.addfriend(name);
    acr.createChat(name);
    for(auto &a:aclist){
        if(a.getMyID()==name){
            a.addfriend(acr.getMyID());
            a.createChat(acr.getMyID(),true);
        }
    }
    cout <<"추가완료"<<endl;
}
///
void inputString(std::string cp,std::string &name){
    std::string ccp[]={"추가할","채팅할"};
    for(auto &a: ccp){
        if(a==cp){
            cout <<a<< "아이디를 입력하세요 :";
            cin>>name;
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
