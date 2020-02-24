//
//  Chat.h
//  STL_libray_testcode
//
//  Created by 전경안 on 2020/02/24.
//  Copyright © 2020 전경안. All rights reserved.
//

#ifndef Chat_h
#define Chat_h
#include <iostream>
#include <string>

class Chat{
private:
    std::string message;
    bool check; // false 보낸 메시지 true 받은 메시지
public:
    Chat(){}
    Chat(bool check,std::string message):check(check),message(message){}
    virtual ~Chat(){}
    void writeM(std::string);
    void setCheck(bool);
    void prnMessage();
    
    void sendM(std::string message,bool check){
        setCheck(check);
        writeM(message);
    }
};

#endif /* Chat_h */
