//
//  main.cpp
//  HW16_20200213
//
//  Created by 전경안 on 2020/02/13.
//  Copyright © 2020 전경안. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <string>
#define LIST_SIZE 100
using namespace std;
class Happy{
private:
    string name;
    int money;
    char *(list[LIST_SIZE]);
    int index;
public:
    Happy(string np="",int money=10000):index(0),name(np),money(money){
        for(int i=0;i<LIST_SIZE;i++){
            list[i]=NULL;
        }
    }
    Happy(Happy&r):index(0),name(r.name),money(r.money){
        for(int i=0;i<r.index;i++){
            list[i]=new char[strlen(r.list[i])+1];
            strcpy(list[i],r.list[i]);
        }
    }
    ~Happy(){
        for(int i=0;i<index;i++){
            delete list[i];
        }
    }
    Happy& operator=(Happy&r);
    void use(char* lp,int n);
    Happy& winner(Happy&r);
    void setName(string &name);
    string& getName();
    void setMoney(int Money);
    int getMoney();
    char**getList();
    int getIndex();
};
Happy& Happy::operator=(Happy &r){
    if(this==&r)return *this;
    name = r.name;
    money = r.money;
    index=r.index;
    if(list[0]!=NULL){
        for(int i=0;i<index;i++){
            delete list[i];
        }
    }
    for(int i=0;i<r.index;i++){
        list[i]=new char[strlen(r.list[i])+1];
        strcpy(list[i],r.list[i]);
    }
    return *this;
}
void Happy::use(char*lp,int n){
    if(this->money<n){
        cout<<"너무 비싼 품목 입니다."<<endl;
        return;
    }
    this->money-=n;
    list[index]=new char[strlen(lp)+1];
    strcpy(list[index],lp);
    index++;
}
Happy& Happy::winner(Happy&r){
    if(this->money < r.money){
        if(this->index!=0){
            for(int i=0;i<index;i++){
                delete list[i];
            }
        }
        this->name = r.name;
        this->money = r.money;
        for(int i=0;i<r.index;i++){
            list[i]=new char[strlen(r.list[i])+1];
            strcpy(list[i],r.list[i]);
        }
        this->index = r.index;
    }
    return *this;
}
void Happy::setName(string &name){
    this->name=name;
}
string& Happy::getName(){
    return this->name;
}
void Happy::setMoney(int money){
    this->money = money;
}
int Happy::getMoney(){
    return money;
}
char **Happy::getList(){
    return list;
}
int Happy::getIndex(){
    return index;
}
int main() {
    Happy a("철이"),b("메텔"),w;
    char item[LIST_SIZE];
    int price;
    cout << "철이가 돈을 씁니다.."<<endl;
    while(1){
        cout<<"구입내역:";
        cin>>item;
        if(strcmp(item,"end")==0)break;
        cout<<"금액 입력:";
        cin>>price;
        a.use(item,price);
    }
    
    cout<<"메텔이 돈을 씁니다..."<<endl;
    while(1){
        cout<<"구입 내역:";
        cin>>item;
        if(strcmp(item,"end")==0)break;
        cout<<"금액 입력: ";
        cin>>price;
        b.use(item,price);
    }
    cout<<"최종 승자는?"<<endl;
    w=a.winner(b);
    cout<<w.getName()<<"이고 총 "<<w.getIndex()<<"건을 사용하고 남은 금액은"<<w.getMoney()<<"원 입니다."<<endl;
    char **tmp = w.getList();
    cout<<"사용 내역 :";
    for(int i=0;i<w.getIndex();i++){
        cout<<tmp[i]<<" ";
    }
    cout<<endl;
    return 0;
}

