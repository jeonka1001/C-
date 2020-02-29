//
//  Account.cpp
//  STL_libray_testcode
//
//  Created by 전경안 on 2020/02/24.
//  Copyright © 2020 전경안. All rights reserved.
//

#include "Account.h"

bool Account::createChat(std::string name,bool check,std::string message){//전달인자를 객체로 수정해보자
    for(auto a: chatroom){
        if(a.getName() == name) return false;
    }
    chatroom.push_back(Chattroom(name,check,message));
    return true;
}
void Account::sendM(std::string name,std::string message, bool check){
    if(!cmpFriend(name))return;
    for(auto &a: chatroom){
        if(a.getName() == name){
            a.addMessage(message,check);
            return;
        }
    }
    std::cout<<this->myID << "먼저 채팅방을 개설해 주세요"<<std::endl;
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
    if(cmpFriend(name))return ;
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
Account& Account::myObj(){
    return *this;
}

void Account::prnChat(std::string name){
    for(auto a: chatroom){
        if(a.getName() == name){
            std::cout <<"[[ "<< a.getName() <<" 님 과의 채팅 ]]"<<std::endl;
            std::cout <<"===================="<<std::endl;
            a.prnMessage();
        }
    }
}
void Account::prnChatroom(){
    std::cout << this->myID<<" 님의 친구 리스트"<<std::endl;
    std::cout <<"=================="<<std::endl;
    for ( auto a: chatroom){
        std:: cout<< a.getName()<<std:: endl;
    }
    std::cout <<std::endl<<"=================="<<std::endl;
}
