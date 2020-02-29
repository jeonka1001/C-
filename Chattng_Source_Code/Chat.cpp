//
//  Chat.cpp
//  STL_libray_testcode
//
//  Created by 전경안 on 2020/02/24.
//  Copyright © 2020 전경안. All rights reserved.
//

#include "Chat.h"


void Chat::prnMessage(){
    if(check == false){ // 보낸 문자는 오른쪽 정렬
        std::cout <<std::right;
        std::cout <<std::setw(40)<< this->message<<" << ME"<<std::endl;
    }
    else{ // 받은 문자의 경우 왼쪽정렬
        std::cout <<std::left;
        std::cout<<"OTHER >> "<<std::setw(40)<< this->message<<std::endl;
    }
}
