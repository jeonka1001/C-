//
//  PokerRule.cpp
//  Poker_Game
//
//  Created by 전경안 on 2020/03/02.
//  Copyright © 2020 전경안. All rights reserved.
//

#include "PokerRule.h"

bool Rule::royalStraightFlush(Card*(&card)[MAX_CARD])const{
    
}
bool Rule::backStraightFlush(Card*(&card)[MAX_CARD])const{
    
}
bool Rule::StraightFlush(Card*(&card)[MAX_CARD])const{
    
}
bool Rule::fourCard(Card*(&card)[MAX_CARD])const{
    
}
bool Rule::fullHouse(Card*(&card)[MAX_CARD])const{
    
}
bool Rule::flush(Card*(&card)[MAX_CARD])const{
    
}
bool Rule::mountain(Card*(&card)[MAX_CARD])const{
    
}
bool Rule::backStraight(Card*(&card)[MAX_CARD])const{
    
}
bool Rule::straight(Card*(&card)[MAX_CARD])const{
    
}
bool Rule::triple(Card*(&card)[MAX_CARD])const{
    
}
bool Rule::twopair(Card*(&card)[MAX_CARD])const{
    
}
bool Rule::onepair(Card*(&card)[MAX_CARD])const{
    int num[MAX_CARD],i=0,check[MAX_CARD];
    for(auto a:card){
        num[i]=a->getNum();
        i++;
    }
    std::sort(num[0],num[MAX_CARD-1]);
    
}

int Rule::numPair(int (&num)[MAX_CARD])const{
    int check[MAX_CARD]={1,},add=0,max=1;
    for(int i=0;i<MAX_CARD-1;i++){
        if(num[i]==num[i+1]){
            check[i+1]+=check[i];
            check[i]=0;
        }
    }
    for(auto a:check){
        if(max<a){
            max=a;
        }
        if(a>1){
            add+=a;
        }
    }
    switch(max){
        case 1:
            return TOP;
        case 2:
            if(add>=4)return TWO_PAIR;
            else return ONE_PAIR;
            break;
        case 3:
            if(add>=5)return FULL_HOUSE;
            else return TRIPLE;
        case 4:
            return FOUR_CARD;
    }
}
bool Rule::shapePair(Card*card1,Card*card2)const{
    if(card1->getShape() == card2->getShape())return true;
    else return false;
}
