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
    int straight(Card*(&)[MAX_CARD]);
    
    int numPair(Card*(&)[MAX_CARD]);
    int flush(Card*(&card)[MAX_CARD]);
    
    void cardSort(Card*(&)[MAX_CARD]);
    void cardSwap(Card*&card1,Card*&card2);
    
    void prnSol(Card*(&card)[MAX_CARD]);
    void prnVal(int);
    void calcSol(int&,int&,int&);
};
#endif /* PokerRule_hpp */
