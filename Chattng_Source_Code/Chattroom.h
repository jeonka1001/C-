//
//  Chattroom.hpp
//  STL_libray_testcode
//
//  Created by 전경안 on 2020/02/24.
//  Copyright © 2020 전경안. All rights reserved.
//

#ifndef Chattroom_h
#define Chattroom_h

#include <iostream>
#include "Chat.h"
#include <list>
class Chattroom:public Chat{
private:
    std::list<Chat> chatting;
    std::string name;// 누구와의 채팅방인지 체크할 변수
public:
    Chattroom(std::string name="주인없음",bool check=false,std::string message="채팅방이 개설되었습니다.")
    :Chat(check,message),name(name){ }
    ~Chattroom(){}
    void addMessage(std::string message,bool check);
    void prnMessage();
    std::string getName();
};


#endif /* Chattroom_hpp */
