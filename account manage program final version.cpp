//
//  main.cpp
//  7-5 final account project
//
//  Created by 전경안 on 2020/01/23.
//  Copyright © 2020 전경안. All rights reserved.
//

#include <iostream>
#include <cstring>
#define NAME_LEN 20
#define ACC_LEN 20
using namespace std;
enum{MAKE_ACC=1,DEPOSIT,WITHDRAW,PRINTINFO,ENDPRO};
class Accountdata{
private:
    char *name;
    char *accountnum;
    int money;
public:
    Accountdata(char*,char*);
    void deposit(int);
    void withdraw(int);
    void showinfo()const;
    
    int returnmoney()const{return money;}
    char* returnname()const{return name;}
    char* returnaccountnum()const{return accountnum;}
    ~Accountdata();
};
////////////////////////////
class Accountmanage
{
private:
    int accnum=0;
    Accountdata *acdata[100];
public:
    Accountmanage();
    void createacc();
    void inmoney();
    void outmoney();
    void showinfoman()const;
    ~Accountmanage();
};
void showmenu(void);
int main() {
    Accountmanage accman;
    while(1){
        showmenu();
        int select;
        cout<<"선택: ";
        cin>>select;
        switch(select){
            case MAKE_ACC:
                cout<<"[계좌개설]"<<endl;
                accman.createacc();
                break;
            case DEPOSIT:
                cout<<"[입금]"<<endl;
                accman.inmoney();
                break;
            case WITHDRAW:
                cout<<"[출금]"<<endl;
                accman.outmoney();
                break;
            case PRINTINFO:
                accman.showinfoman();
                break;
            case ENDPRO:
                cout<<"시스템을 종료합니다."<<endl;
                return 0;
                break;
            default:
                cout<<"다시 입력하세요."<<endl;
                break;
        }
    }
}
void showmenu(){
    cout<<"=======MENU======="<<endl;
    cout<<"1. 계좌개설"<<endl;
    cout<<"2. 입금"<<endl;
    cout<<"3. 출금"<<endl;
    cout<<"4. 전체 정보 출력"<<endl;
    cout<<"5. 종료"<<endl;
}
////Accountdata function////
Accountdata::Accountdata(char *n,char *a)
:money(0){
    name = new char[strlen(n)+1];
    strcpy(name,n);
    
    accountnum=new char[strlen(a)+1];
    strcpy(accountnum,a);
}
void Accountdata::deposit(int m){
    money+=m;
}
void Accountdata::withdraw(int m){
    money-=m;
}
void Accountdata::showinfo()const{
    cout<<"이름: "<<name<<endl;
    cout<<"계좌번호: "<<accountnum<<endl;
    cout<<"잔액: "<<money<<endl;
    }
Accountdata::~Accountdata(){
    delete []name;
    delete []accountnum;
}
///////////////////////////////////
////Accountmanage Function////
Accountmanage::Accountmanage()
{
    
}
void Accountmanage::createacc(){
    char n[NAME_LEN];
    cout<<"이름: ";
    cin>>n;
    char a[ACC_LEN];
    cout<<"계좌ID: ";
    cin>>a;
    acdata[accnum]=new Accountdata(n,a);
    accnum++;
}
void Accountmanage::inmoney(){
    char n[NAME_LEN];
    cout<<"이름: ";
    cin>>n;
    char a[ACC_LEN];
    cout<<"계좌ID: ";
    cin>>a;
    for(int i=0;i<accnum;i++){
        if(strcmp(n,acdata[i]->returnname())==0){
            if(strcmp(a,acdata[i]->returnaccountnum())==0){
                int m;
                cout<<"입금액을 입력해주세요:";
                cin>>m;
                acdata[i]->deposit(m);
            }
            else{
                //cout<<"유효하지 않은 ACCID 입니다."<<endl;
            }
        }
        else{
            //cout<<"유효하지 않은 이름 입니다."<<endl;
        }
    }
}
void Accountmanage::outmoney(){
    char n[NAME_LEN];
    cout<<"이름: ";
    cin>>n;
    char a[ACC_LEN];
    cout<<"계좌ID: ";
    cin>>a;
    for(int i=0;i<accnum;i++){
        if(strcmp(n,acdata[i]->returnname())==0){
            if(strcmp(a,acdata[i]->returnaccountnum())==0){
                int m;
                cout<<"입금액을 입력해주세요:";
                cin>>m;
                acdata[i]->withdraw(m);
            }
        }
    }
}

void Accountmanage::showinfoman() const{
    for(int i=0;i<accnum;i++){
        cout<<"=========="<<endl;
        acdata[i]->showinfo();
    }
}
Accountmanage::~Accountmanage(){
    for(int i=0;i<accnum;i++){
        delete acdata[i];
    }
}
