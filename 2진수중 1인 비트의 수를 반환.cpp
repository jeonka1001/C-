//
//  main.cpp
//  이진수중 1 반환
//
//  Created by 전경안 on 2020/01/22.
//  Copyright © 2020 전경안. All rights reserved.
// 주어진 두 수의 곱을 이진수로 변환해서 비트중 1의 수를 반환하는 코드.

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int a,b;
    cout <<"두 수를 입력해 주세요:";
    cin >>a>>b;
    int num;
    num=a*b;
    int count=0;
    while(num!=0){
        if(num%2==1){
            count++;
        }else{
            ;
        }
        num/=2;
    }
    cout<<"2진 숫자중 1인 비트는 : "<<count<<" 개"<<endl;
    return 0;
}
