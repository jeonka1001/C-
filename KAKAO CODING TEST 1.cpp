//
//  main.cpp
//  kakao1
//
//  Created by 전경안 on 2020/02/10.
//  Copyright © 2020 전경안. All rights reserved.
//

#include <iostream>
using namespace std;
#define INPUT_NUM 5
void trans(int);
int main(int argc, const char * argv[]) {
    int n=INPUT_NUM;
    int ary1[]={9,20,28,18,11};
    int ary2[]={30,1,21,17,28};
    
    for(int j=0;j<n;j++){
        for(int i=4;i>=0;i--){
            //cout<<((ary2[j]>>i)|0x00) ;
            if((((ary1[j]>>i)&0x01)|((ary2[j]>>i)&0x01)) == 1){
                cout<<"#";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}

