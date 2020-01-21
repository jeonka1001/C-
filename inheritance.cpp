//
//  main.cpp
//  7-2 문제2
//
//  Created by 전경안 on 2020/01/22.
//  Copyright © 2020 전경안. All rights reserved.
// 상속시 생성자가 생성되는 순서와 생성자가 소멸하는 순서

#include <iostream>
#include <cstring>
using namespace std;
class myinfo{
private:
    char *name;
    int age;
public:
    myinfo(char *na,int ag)
    :age(ag)
    {
        name=new char[strlen(na)+1];
        strcpy(name,na);
        cout<<"name create"<<endl;
    }
    void showmyinfo()
    {
        cout<<"이름: "<<name<<endl;
        cout<<"나이: "<<age<<endl;
    }
    ~myinfo(){
        delete []name;
        cout<<"name delete"<<endl;
    }
};
class mydetailinfo:public myinfo
{
private:
    char *addr;
    char *phone;
public:
    mydetailinfo(char *na,int ag,char *ad,char *ph)
    :myinfo(na,ag)
    {
        addr=new char[strlen(ad)+1];
        strcpy(addr,ad);
        cout<<"addr create"<<endl;
        
        phone=new char[strlen(ph)+1];
        strcpy(phone,ph);
        cout<<"phone create"<<endl;
    }
    void showdetail(){
        showmyinfo();
        cout<<"주소: "<<addr<<endl;
        cout<<"전화번호: "<<phone<<endl;
    }
    ~mydetailinfo(){
        delete []addr;
        cout<<"addr delete"<<endl;
        delete []phone;
        cout<<"phone delete"<<endl;
    }
};
int main() {
    mydetailinfo im("jeonka",25,"gwangmyeong","010-2225-8163");
    im.showdetail();
    return 0;
}
