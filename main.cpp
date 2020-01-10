//
//  main.cpp
//  3-2 문제2
//
//  Created by 전경안 on 2020/01/10.
//  Copyright © 2020 전경안. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

class Printer{
private:
    string st;
    
public:
    void scanner(string);
    void printing();
};

void Printer::scanner(string st1){
    st=st1;
}
void Printer::printing(){
    cout<<st<<endl;
}
int main() {
    Printer prt;
    prt.scanner("hello word!");
    prt.printing();
    
    prt.scanner("i luv c++");
    prt.printing();
    return 0;
}
