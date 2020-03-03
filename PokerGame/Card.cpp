//
//  Card.cpp
//  Poker_Game
//
//  Created by 전경안 on 2020/03/02.
//  Copyright © 2020 전경안. All rights reserved.
//

#include "Card.h"

int Card::getShape(){
    return shape;
}
int Card::getNum(){
    return num;
}
void Card::setShape(int shape){
    this->shape=shape;
}
void Card::setNum(int num){
    this->num = num;
}
void Card::prnCard(){
    switch(this->shape){
        case C:
            std::cout <<"♧"<<num<<"/";
        case H:
            std::cout <<"♡"<<num<<"/";
        case D:
            std::cout <<"♢"<<num<<"/";
        case S:
            std::cout <<"♤"<<num<<"/";
    }
}
