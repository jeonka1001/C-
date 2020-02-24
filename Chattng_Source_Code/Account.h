//
//  Account.hpp
//  STL_libray_testcode
//
//  Created by 전경안 on 2020/02/24.
//  Copyright © 2020 전경안. All rights reserved.
//

#ifndef Account_h
#define Account_h

#include <iostream>
#include "Chattroom.h"
#include <list>
#include <string>

class Account{
private:
    std::list<Chattroom> chatroom;
    std::list<std::string> friendName;
    std::string myID;
public:
    Account():myID("AccountList"){};
    Account(std::string name,std::string myID):myID(myID){}
    ~Account(){}
    bool createChat(std::string name,std::string message,bool check);//이미 채팅방이 개설된 경우
    void sendM(std::string message,bool check);
    bool searchName(std::string);//채팅방 찾기
    std::string getMyID();
    void addfriend(std::string);
    bool cmpFriend(std::string);
};

#endif /* Account_hpp */
