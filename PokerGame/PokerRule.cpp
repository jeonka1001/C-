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
int Rule::straight(std::vector<int> num){
    int check[MAX_CARD]={1,};
    for(int a=0;a<MAX_CARD-1;a++){
        if(num[a+1]-num[a]==1){
            check[a+1]+=check[a];
            
        }
    }
    for(int i=0;i<MAX_CARD;i++){
        if(check[i]==5&&num[i]==5&&num[0]==1){
            return BACK_STRAIGHT;
        }
        if(check[i]>=4&&num[i]==13&&num[0]==1){
            return MOUNTAIN;
        }
        if(check[i]>=5){
            return STRAIGHT;
        }
    }
    return 0;
}
int Rule::numPair(Card*(&card)[MAX_CARD]){
    int check[MAX_CARD]={1,},add=0,max=1;
    std::vector<int> num;
    for(auto a:card){
        num.push_back(a->getNum());
    }
    std::sort(num.begin(),num.end());
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
            if(straight(num)!=0)return STRAIGHT;
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

int Rule::shapePair(Card*(&card)[MAX_CARD])//스트레이트 플러쉬 구현 방법 찾기 아마numpair에서 수행
{
    int check[MAX_CARD]={1,},i=0;
    std::vector<int> shape;
    for(auto a:card){
        shape[i]=a->getShape();
        i++;
    }
    std::sort(shape.begin(),shape.end());
    for(int i=0;i<MAX_CARD-1;i++){
        if(shape[i]==shape[i+1]){
            check[i+1]+=check[i];
            check[i]=0;
        }
    }
    for(int i=0;i<MAX_CARD;i++){
        if(check[i]==5){
            return shape[i];
        }
    }
    return -1;

}
