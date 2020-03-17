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
 *** 만의자리= 모양 / 천,백의자리 = 탑 카드 / 십,일의자리 = 패의 값 ***
 Spade = 4/ Diamond = 3/ Heart = 2/ Clover = 1/
 SHAPE_NUM = 10000
 TOP_NUM = 100
 ================================*/
#include <iostream>
#define S 4
#define D 3
#define H 2
#define C 1
#define SHAPE_NUM 10000
#define TOP_NUM 100

#define MAX_CARD 7

class Card{
private:
    int shape;
    int num;
public:
    Card(int shape=0,int num=-1):shape(shape),num(num){}
    int getShape();
    int getNum();
    void setShape(int shape);
    void setNum(int num);
    void prnCard();
    void operator=(Card card1);
};
#endif /* Card_h */
