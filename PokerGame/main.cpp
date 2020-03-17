//
//  main.cpp
//  Poker_Game
//
//  Created by 전경안 on 2020/03/02.
//  Copyright © 2020 전경안. All rights reserved.
//

#include <iostream>
#include <random>

#include "Player.h"
#include "PokerRule.h"

void settingCard(Player &i);
//void betting(Player&i);
int randNum();//숫자 결정
int randShape();// 모양 결정
int main(int argc, const char * argv[]) {
    Player i;
    srand((unsigned int)time(NULL));
    while(i.getNumber()!=MAX_CARD){
        settingCard(i);
        
        //betting(i);
    }
    i.prnCard();
    i.prnSsol();
    
    return 0;
}

void settingCard(Player &i){
    int num;
    int shape;
    bool check;
    while(1){
        num=randNum();
        shape=randShape();
        std::cout << "shape : "<< shape<<std::endl;
        check = i.setCard(shape, num);
        if(check){
            return ;
        }
    }
}
int randNum(){return (rand()%13)+1;}
int randShape(){return (rand()%4)+1;}
