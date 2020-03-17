//
//  PokerRule.hpp
//  Poker_Game
//
//  Created by 전경안 on 2020/03/02.
//  Copyright © 2020 전경안. All rights reserved.
//

#ifndef PokerRule_h
#define PokerRule_h

#include <iostream>
#include <vector>
#include "Card.h"

class Rule{
public:
    enum{TOP=0,ONE_PAIR,TWO_PAIR,TRIPLE,STRAIGHT,
        BACK_STRAIGHT,MOUNTAIN,
        FLUSH,FULL_HOUSE,FOUR_CARD,
        STRAIGHT_FLUSH,
        BACK_STRAIGHT_FLUSH,
        ROYAL_STRAIGHT_FLUSH
    };
    int straight(Card*(&)[MAX_CARD])const;
    
    int numPair(Card*(&)[MAX_CARD])const;
    int flush(Card*(&card)[MAX_CARD])const;
    
    void cardSort(Card*(&)[MAX_CARD])const;
    void cardSwap(Card*&card1,Card*&card2)const;
    
    void prnSol(Card*(&card)[MAX_CARD])const;
    void prnVal(int)const;
    void calcSol(int&,int&,int&)const;
};
#endif /* PokerRule_hpp */
