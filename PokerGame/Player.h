//
//  Player.hpp
//  Poker_Game
//
//  Created by 전경안 on 2020/03/02.
//  Copyright © 2020 전경안. All rights reserved.
//

#ifndef Player_h
#define Player_h

#include <iostream>
#include "Card.h"
#include "PokerRule.h"

class Player
{
private:
    Card *(myCard[MAX_CARD]);
    int money; //가진 돈
    int number; // 가진 카드의 수
    Rule game;
public:
    Player();
//    ~Player(){
//        for(int i=0;i<MAX_CARD;i++){
//            delete myCard[i];
//        }
//    }
    void prnCard();
    bool setCard(int shape,int num);
    void setMoney(int money);
    void addMoney(int m);
    int getMoney();
    int getNumber(){return number;}
    // 베팅 //
    int call(int m);
    int half();
    void prnSsol();
};

#endif /* Player_hpp */
