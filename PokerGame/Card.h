//
//  Card.h
//  Poker_Game
//
//  Created by 전경안 on 2020/03/02.
//  Copyright © 2020 전경안. All rights reserved.
//

#ifndef Card_h
#define Card_h
/* ================================
 Spade = 4/ Diamond = 3/ Heart = 2/ Clover = 1/
 ================================*/
#include <iostream>
#define S 4
#define D 3
#define H 2
#define C 1
class Card{
private:
    int shape;
    int num;
public:
    Card(int shape=0,int num=0):shape(shape),num(num){}
    int getShape();
    int getNum();
    void setShape(int shape);
    void setNum(int num);
    void prnCard();
};
#endif /* Card_h */
