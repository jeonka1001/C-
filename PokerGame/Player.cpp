//
//  Player.cpp
//  Poker_Game
//
//  Created by 전경안 on 2020/03/02.
//  Copyright © 2020 전경안. All rights reserved.
//

#include "Player.h"

Player::Player():money(100000),number(0){
    for(int i=0;i<MAX_CARD;i++){
        myCard[i] = new Card;
    }
}
/*====================
 사용자가 가지고 있는 카드를 출력
 =======================*/
void Player::prnCard(){
    std::cout << "사용자의 카드 : ";
    for(int i=0;i<number;i++){
        myCard[i]->prnCard();
    }
    std::cout << std::endl;
}
/*====================
 사용자가 카드 한장을 부여받음.
 =======================*/
bool Player::setCard(int shape,int num){
    if(number == MAX_CARD)return false;
    for(auto a:myCard){
        if(a->getNum()==num&&a->getShape()==shape){
            return false;
        }
    }
    myCard[number]->setNum(num);
    myCard[number]->setShape(shape);
    number++;
    return true;
}
/*====================
 사용자의 돈을 설정 (입력받은 금액만큼 돈이 초기화 됨)
 =======================*/
void Player::setMoney(int money){
    this->money = money;
}
/*====================
 사용자가 이겼을 경우 돈을 얻는다.
 m = 상금
 =======================*/
void Player::addMoney(int m){
    this->money += m;
}
/*====================
 사용자의 돈을 출력
 =======================*/
int Player::getMoney(){
    return this->money;
}
/*====================
 사용자가 베팅을 한다.
 m = 이전 사람이 배팅한 금액.
 =======================*/
int Player::call(int m){
    this->money -=m;
    return m;
}
/*====================
 사용자가 베팅을 한다.
 자신의 현재 금액의 절반.
 =======================*/
int Player::half(){
    this->money/=2;
    return this->money;
}

void Player::prnSsol(){
    game.prnSol(myCard);
}
