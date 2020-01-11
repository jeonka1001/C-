//
//  main.cpp
//  3-3 문제 사과장수
//
//  Created by 전경안 on 2020/01/11.
//  Copyright © 2020 전경안. All rights reserved.
//

#include <iostream>
using namespace std;

class fruitseller{//class of seller
    enum{
        APPLE_PRICE=500//standard price of apple
        
    };
private:
    int mymoney;
    int myapple;
public:
    void initseller(int,int);
    int sellapple(int);
    void showstate();
};
void fruitseller::initseller(int apple,int money){
    mymoney=money;
    myapple=apple;
}
int fruitseller::sellapple(int money){
    int num=money/APPLE_PRICE;
    mymoney+=money;
    myapple-=num;
    return num;
}
void fruitseller::showstate(){
    cout<<"currently seller have  : "<<myapple<<" apple"<<endl;
    cout<<"currently seller have  : "<<mymoney<<" won"<<endl;
}
//////seller class/////

class fruitbuyer{
private:
    int mymoney;
    int myapple;
public:
    void initbuyer(int,int);
    void buyapple(fruitseller&,int);
    void showstate();
};
void fruitbuyer::initbuyer(int money,int apple){
    mymoney=money;
    myapple=apple;
}
void fruitbuyer::buyapple(fruitseller &seller,int money){
    mymoney-=money;
    myapple+=seller.sellapple(money);
}
void fruitbuyer::showstate(){
    cout<<"currently buyer have : "<<mymoney<<" won"<<endl;
    cout<<"currently buyer have : "<<myapple<<" apple"<<endl;
}
int main() {
    int smoney,sapple;
    fruitseller seller;
    cout<<"input current saller's money and apple: ";
    cin>>sapple>>smoney;
    seller.initseller(sapple,smoney);
    
    int bmoney,bapple;
    fruitbuyer buyer;
    cout<<"How much apples and money dose the buyer have?";
    cin>>bmoney>>bapple;
    buyer.initbuyer(bmoney,bapple);
    cout<<"Write down the amount you will pay.:";
    cin>>bmoney;
    buyer.buyapple(seller,bmoney);
    buyer.showstate();
    seller.showstate();
    return 0;
}
