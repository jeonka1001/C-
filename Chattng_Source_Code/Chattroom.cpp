//
//  Chattroom.cpp
//  STL_libray_testcode
//
//  Created by 전경안 on 2020/02/24.
//  Copyright © 2020 전경안. All rights reserved.
//

#include "Chattroom.h"

void Chattroom::addMessage(std::string message,bool check){
    chatting.push_back(Chat(check,message));
}
void Chattroom::prnMessage(){
    for(auto a: this->chatting){
        a.prnMessage();
    }
}
std::string Chattroom::getName(){
    return this->name;
}
Chattroom& Chattroom::myChattroom(){
    return *this;
}
