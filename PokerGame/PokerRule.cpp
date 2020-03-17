//
//  PokerRule.cpp
//  Poker_Game
//
//  Created by 전경안 on 2020/03/02.
//  Copyright © 2020 전경안. All rights reserved.
//

#include "PokerRule.h"
using std::cout;
using std::endl;
int Rule::straight(Card*(&card)[MAX_CARD])const{
    int check[MAX_CARD]={1,},flushCheck=1,topNum=0;
    
    for(int i=0;i<MAX_CARD-1;i++){
        if((card[i+1]->getNum()-card[i]->getNum())==1){
            check[i+1]+=check[i];
            check[i]=0;
            topNum=i;
            if(card[i+1]->getShape() == card[i]->getShape()){
                flushCheck++;
            }
        }
    }
    for(int i=0;i<MAX_CARD;i++){
        if(check[i]==5&&card[i]->getNum()==5&&card[0]->getNum()==1){
            if(flushCheck == 5){
                return (card[i]->getShape()*SHAPE_NUM)+(card[topNum]->getNum()*TOP_NUM)+BACK_STRAIGHT_FLUSH;
            }
            return (card[i]->getShape()*SHAPE_NUM)+(card[topNum]->getNum()*TOP_NUM)+BACK_STRAIGHT;
        }
        if(check[i]>=4&&card[i]->getNum()==13&&card[0]->getNum()==1){
            if(flushCheck == 4&&card[i]->getShape()==card[0]->getShape()){
                return (card[i]->getShape()*SHAPE_NUM)+(card[topNum]->getNum()*TOP_NUM)+ROYAL_STRAIGHT_FLUSH;
            }
                return (card[i]->getShape()*SHAPE_NUM)+(card[topNum]->getNum()*TOP_NUM)+MOUNTAIN;
        }
        if(check[i]>=5){
            if(flushCheck == 5){
                return (card[i]->getShape()*SHAPE_NUM)+(card[topNum]->getNum()*TOP_NUM)+STRAIGHT_FLUSH;
            }
            return (card[i]->getShape()*SHAPE_NUM)+(card[topNum]->getNum()*TOP_NUM)+STRAIGHT;
        }
    }
    return -1;
}
int Rule::numPair(Card*(&card)[MAX_CARD])const{
    
    int pairCheck[MAX_CARD],topNum=0;
    
    for(int i=0;i<MAX_CARD;i++){
        pairCheck[i]=1;
    }
    for(int i=0;i<MAX_CARD-1;i++){
        if(card[i]->getNum()==card[i+1]->getNum()){
            pairCheck[i+1]+=pairCheck[i];
            pairCheck[i]=0;
        }
    }
    cout << "페어 체크 ";
    for(auto a : pairCheck){
        cout <<a<<" ";
    }
    cout << endl;
    int max=1,add=0;
    for(int i=0;i<MAX_CARD;i++){
        if(max<=pairCheck[i]){
            max=pairCheck[i];
        }
        if(pairCheck[i]>1){
            add+=pairCheck[i];
        }
    }
    int fl=flush(card);
    
    switch(max){
        case 1:
            if(fl==-1)return (card[topNum]->getShape()*SHAPE_NUM)+(card[topNum]->getNum()*TOP_NUM)+TOP;
            break;
        case 2:
            if(fl==-1){
                if(add>=4){
                    return (card[topNum]->getShape()*SHAPE_NUM)+(card[topNum]->getNum()*TOP_NUM)+TWO_PAIR;
                }
                else return (card[topNum]->getShape()*SHAPE_NUM)+(card[topNum]->getNum()*TOP_NUM)+ONE_PAIR;
            }
            break;
        case 3:
            if(add>=5)return (card[topNum]->getShape()*SHAPE_NUM)+(card[topNum]->getNum()*TOP_NUM)+FULL_HOUSE;
            if(fl==-1){
                return (card[topNum]->getShape()*SHAPE_NUM)+(card[topNum]->getNum()*TOP_NUM)+TRIPLE;
            }
            break;
        case 4:
            return (card[topNum]->getShape()*SHAPE_NUM)+(card[topNum]->getNum()*TOP_NUM)+FOUR_CARD;
    }
    return fl;
}

int Rule::flush(Card*(&card)[MAX_CARD])const
{
    int check[4]={0,};
    for(int i=0;i<MAX_CARD;i++){
        check[card[i]->getShape()-1]+=1;
        cout<< card[i]->getShape()<<endl;
        if(check[card[i]->getShape()-1] >= 5)
        {
            return (card[i]->getShape()*SHAPE_NUM)+(card[i]->getNum()*TOP_NUM)+FLUSH;
        }
    }
    return -1;
}

void Rule::cardSort(Card*(&card)[MAX_CARD])const{ /// 이부분 고치기
    int minNum=0;
    while(minNum!=(MAX_CARD-1)){
        for(int i=minNum;i<MAX_CARD;i++){
            if(card[minNum]->getNum() > card[i]->getNum()){
                cardSwap(card[minNum],card[i]);
            }
        }
        minNum++;
    }
}
void Rule::cardSwap(Card*&card1,Card*&card2)const{
    Card temp;
    temp = *card2;
    *card2 = *card1;
    *card1 = temp;
}
void Rule::prnSol(Card*(&card)[MAX_CARD])const{
    cardSort(card);
    
    int solCheck=straight(card);
    int shape,top;
    
    if(solCheck!=-1){
        calcSol(shape,top,solCheck);
    }
    else{
        solCheck=numPair(card);
        cout << "solcheck : "<< solCheck <<endl;
        calcSol(shape,top,solCheck);
        
    }
    prnVal(solCheck);
    cout << "/ Top Card : ";
    card[MAX_CARD-1]->prnCard();
    cout << endl;
//    }
//    switch(shape){
//        case C:
//            prnVal(solCheck);
//            std::cout << "TOP : CLOVER " << top <<std::endl;
//            break;
//        case H:
//            prnVal(solCheck);
//            std::cout << "TOP : HEART " << top <<std::endl;
//            break;
//        case D:
//            prnVal(solCheck);
//            std::cout << "TOP : DIAMOND " << top <<std::endl;
//            break;
//        case S:
//            prnVal(solCheck);
//            std::cout << "TOP : SPADE " << top <<std::endl;
//            break;
//    }

}

void Rule::calcSol(int &shape,int &top,int &solCheck)const{
//    shape=solCheck/SHAPE_NUM;
//    solCheck-=shape*SHAPE_NUM;
//    top=solCheck/TOP_NUM;
//    solCheck-=top*TOP_NUM;
    solCheck = solCheck%100;
}

void Rule::prnVal(int n)const{
    switch(n){
        case TOP:
            cout <<" NO PAIR ";
            break;
        case ONE_PAIR:
            cout << " ONE PAIR ";
            break;
        case TWO_PAIR:
            cout << " TWO PAIR ";
            break;
        case TRIPLE:
            cout << " TRIPLE ";
            break;
        case STRAIGHT:
            cout <<" STRAIGHT ";
            break;
        case BACK_STRAIGHT:
            cout <<" BACK STRAIGHT ";
            break;
        case MOUNTAIN:
            cout <<" MOUNTAIN " ;
            break;
        case FLUSH:
            cout <<" FLUSH " ;
            break;
        case FULL_HOUSE:
            cout <<" FULL HOUSE ";
            break;
        case FOUR_CARD:
            cout << " FOUR CARD ";
            break;
        case STRAIGHT_FLUSH:
            cout << " STRAIGHT FLUSH ";
            break;
        case BACK_STRAIGHT_FLUSH:
            cout << " BACK STRAGIHT FLUSH ";
            break;
        case ROYAL_STRAIGHT_FLUSH:
            cout << " ROYAL STRAGIHT FLUSH ";
            break;
        default:
            break;
    }
}
