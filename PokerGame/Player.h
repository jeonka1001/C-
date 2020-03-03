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
#define MAX_CARD 7
class Player:public Rule
{
private:
    Card *(myCard[MAX_CARD]);
    int money;
    int number;
public:
    Player();
    void prnCard();
    void setCard(int shape,int num);
    void setMoney(int money);
    void addMoney(int m);
    int getMoney();
    // 배팅 //
    int call(int m);
    int half();
    void prnMySol();
};

#endif /* Player_hpp */
