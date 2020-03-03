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
#include "Player.h"
#include <algorithm>
class Rule{
public:
    enum{TOP=0,ONE_PAIR,TWO_PAIR,TRIPLE,STRAIGHT,
        BACK_STRAIGHT,MOUNTAIN,
        FLUSH,FULL_HOUSE,FOUR_CARD,
        STRAIGHT_FLUSH,
        BACK_STRAIGHT_FLUSH,
        ROYAL_STRAIGHT_FLUSH
    };
    bool royalStraightFlush(Card*(&)[MAX_CARD])const;
    bool backStraightFlush(Card*(&)[MAX_CARD])const;
    bool StraightFlush(Card*(&)[MAX_CARD])const;
    bool fourCard(Card*(&)[MAX_CARD])const;
    bool fullHouse(Card*(&)[MAX_CARD])const;
    bool flush(Card*(&)[MAX_CARD])const;
    bool mountain(Card*(&)[MAX_CARD])const;
    bool backStraight(Card*(&)[MAX_CARD])const;
    
    int straight(std::vector<int>);
  
    
    int numPair(Card*(&)[MAX_CARD]);
    int shapePair(Card*(&)[MAX_CARD]);
};
#endif /* PokerRule_hpp */
