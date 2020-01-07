//
//  main.cpp
//  2-6 마지막 문제
//
//  Created by 전경안 on 2020/01/07.
//  Copyright © 2020 전경안. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char apple[30];
    cout<<"사과는 영어로?:";
    cin>>apple;
    cout<<"글자수: "<<strlen(apple)<<endl;//strlen 함수 확인
    
    char cpyapple[30];
    strcat(apple," pencil");
    strcpy(cpyapple,"apple pencil");
    cout<<"내가 쓰는 펜슬은: "<<apple<<endl;//strcat 함수 확인

    if(strcmp(apple,cpyapple)==0){//strcpy,strcmp함수 확인
        cout<<"같은 글자야!"<<endl;
    }
    else{
        cout<<"다른 글자야!"<<endl;
    }
    return 0;
}
