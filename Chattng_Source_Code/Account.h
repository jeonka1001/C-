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
#include <algorithm>
#include <cstring>
class Account{
private:
    std::list<Chattroom> chatroom;
    std::list<std::string> friendName;
    std::string myID;
public:
    Account():myID("AccountList"){};
    Account(std::string name,std::string myID):myID(myID){}
    ~Account(){}
    bool createChat(std::string name,bool check=false,std::string message="hi nice to meet you");
    void sendM(std::string name,std::string message, bool check);
    bool searchName(std::string name);//채팅방 찾기
    std::string getMyID();
    void addfriend(std::string name);
    bool cmpFriend(std::string name);
    Account& myObj();
    void prnChat(std::string);
    void prnChatroom();
};

#endif /* Account_hpp */
