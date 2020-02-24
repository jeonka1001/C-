//
//  Account.cpp
//  STL_libray_testcode
//
//  Created by 전경안 on 2020/02/24.
//  Copyright © 2020 전경안. All rights reserved.
//

#include "Account.h"

bool Account::createChat(std::string name,std::string message,bool check){
    for(auto a:this->chatroom){
        if(a.getName() == name) return false;
    }
    Chattroom temp(name,check,message);
    chatroom.push_back(temp);
    return true;
}
void Account::sendM(std::string message, bool check){
    Chattroom temp;
    temp.addMessage(message,check);
    chatroom.push_front(temp);
}
bool Account::searchName(std::string name){
    for(auto a: this->chatroom){
        if(a.getName() == name)return true;
    }
    return false;
}
std::string Account::getMyID(){
    return this->myID;
}
void Account::addfriend(std::string name){
    this->friendName.push_front(name);
}
bool Account::cmpFriend(std::string name){
    for (auto a: friendName){
        if(a == name){
            return true;
        }
    }
    return false;

}
