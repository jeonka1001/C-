
//
//  main.cpp
//  4-1 문제 사과장수 보완
//
//  Created by 전경안 on 2020/01/11.
//  Copyright © 2020 전경안. All rights reserved.
// seller sales apples. buyer purchase apple.

#include <iostream>
using namespace std;

////////seller class//////////
class fruitseller{//class of seller
    enum{
        APPLE_PRICE=500//standard price of apple
        
    };
private:
    int mymoney;
    int myapple;
public:
    bool initseller(int,int);
    int sellapple(int);
    void showstate()const;
    int pricere()const;
//    int getapple()const;
//    int getmoney()const;
};
bool fruitseller::initseller(int apple,int money){
    if(apple<=0||money<0){
        return false;
    }
    mymoney=money;
    myapple=apple;
    return true;
}
int fruitseller::sellapple(int money){
    int num=money/APPLE_PRICE;
    if(num>0){
        mymoney+=(num*APPLE_PRICE);
    }
    myapple-=num;
    if(myapple<0){
        return num+myapple;
    }
    return num;
}

void fruitseller::showstate()const{
    cout<<"currently seller have  : "<<myapple<<" apple"<<endl;
    cout<<"currently seller have  : "<<mymoney<<" won"<<endl;
}
int fruitseller::pricere()const{
    return APPLE_PRICE;
}

//////////////////////
//////buyer class/////

class fruitbuyer{
private:
    int mymoney;
    int myapple;
public:
    bool initbuyer(int,int);
    bool buyapple(fruitseller&,int);
    void showstate()const;
//    int getapple()const;
//    int getmoney()const;
};
bool fruitbuyer::initbuyer(int apple,int money){
    if(apple<0||money<0){
        return false;
    }
    myapple=apple;
    mymoney=money;
    return true;
}
bool fruitbuyer::buyapple(fruitseller &seller,int money){
    if(money<=0||mymoney<money){
        return false;
    }
    
    int memo=seller.sellapple(money);
    if(myapple<myapple+memo){
        myapple+=memo;
        mymoney-=memo*seller.pricere();
    }
    return true;
}
void fruitbuyer::showstate()const{
    cout<<"currently buyer have : "<<mymoney<<" won"<<endl;
    cout<<"currently buyer have : "<<myapple<<" apple"<<endl;
}
////////////////////////////////////
int main() {
    int smoney,sapple;
    bool sdis;
    fruitseller seller;
    while(1){
        cout<<"* Currently how much apples and money \n dose the seller have?: ";
        cin>>sapple>>smoney;
        sdis=seller.initseller(sapple,smoney);
        if(sdis){
            break;
        }
        cout<<"The value is not correct \n please retry write down correct value. "<<endl;
    }
    
    int bmoney,bapple;
    bool bdis,badis;
    fruitbuyer buyer;
    while(1){
        cout<<"* How much apples and money dose the buyer have?";
        cin>>bapple>>bmoney;
        bdis=buyer.initbuyer(bapple,bmoney);
        if(bdis){
            cout<<"* Write down the amount buyer will pay:";
            cin>>bmoney;
            badis=buyer.buyapple(seller,bmoney);
            if(badis){
                break;
            }
        }
        cout<<"The value is not correct \n please retry write down correct value. "<<endl;
    }
    cout<<"====buyer state===="<<endl;
    buyer.showstate();
    cout<<"====seller state===="<<endl;
    seller.showstate();
    return 0;
}
