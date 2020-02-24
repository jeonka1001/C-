//
//  Chattroom.cpp
//  STL_libray_testcode
//
//  Created by 전경안 on 2020/02/24.
//  Copyright © 2020 전경안. All rights reserved.
//

#include "Chattroom.h"

void Chattroom::addMessage(std::string message,bool check){
    Chat temp;
    temp.sendM(message,check);
    this->chatting.push_back(temp);
}
void Chattroom::prnMessage(){
    for(auto a: this->chatting){
        a.prnMessage();
    }
}
std::string Chattroom::getName(){
    return this->name;
}
