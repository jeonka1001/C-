//
//  main.cpp
//  4-3 문제 2
//
//  Created by 전경안 on 2020/01/13.
//  Copyright © 2020 전경안. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

class Position{
public:
    enum{
        CLERK,
        SENIOR,
        ASSIST,
        MANAGER
    };
};

class Person{
private:
    char *name;
    char *job;
    char *phone;
    int a;
public:
    Person(char *yname,char *yjob, char *yphone, int ya)
    :a(ya){
        unsigned long len;
        len=(strlen(yname))+1;
        name=new char[len];
        strcpy(name,yname);//이름정보 저장
        
        len=strlen(yjob);
        job=new char[len];
        strcpy(job,yjob);//회사정보 저장
        
        len=strlen(yphone);
        phone=new char[len];
        strcpy(phone,yphone);//전화번호 저장
    }
    void showP(){
        cout<<"이름은 "<<name<<endl;
        cout<<"회사이름은 "<<job<<endl;
        cout<<"휴대폰 번호는 "<<phone<<endl;
        cout<<"직급은 ";
        switch (a){
            case Position::CLERK:
                cout<<"사원"<<endl;
                break;
            case Position::SENIOR:
                cout<<"주임"<<endl;
                break;
            case Position::ASSIST:
                cout<<"대리"<<endl;
                break;
            case Position::MANAGER:
                cout<<"과장"<<endl;
                break;
        }
    }
    ~Person(){
        delete []name;
        delete []job;
        delete []phone;
    }
};

int main() {
    Person p("jeonKA","samsung","010-2225-816",Position::CLERK);
    p.showP();
    return 0;
}
