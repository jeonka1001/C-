//
//  Chat.cpp
//  STL_libray_testcode
//
//  Created by 전경안 on 2020/02/24.
//  Copyright © 2020 전경안. All rights reserved.
//

#include "Chat.h"

void Chat::writeM(std::string message){
    this->message=message;
}
///false == 보냄 , true = 받음
void Chat::setCheck(bool check){
    this->check = check;
}
void Chat::prnMessage(){
    std::cout.precision(20);
    if(check == false){ // 보낸 문자는 오른쪽 정렬
        std::cout.setf(std::ios::right,std::ios::adjustfield);
        std::cout << this->message<<std::endl;
    }
    else{ // 받은 문자의 경우 왼쪽정렬
        std::cout.setf(std::ios::left,std::ios::adjustfield);
        std::cout << this->message<<std::endl;
    }
}
