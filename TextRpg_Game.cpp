//
//  main.cpp
//  Game build
//
//  Created by 전경안 on 2020/02/02.
//  Copyright © 2020 전경안. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
class Enemy;

class UserInfo//유저의 정보 저장
{
private:
    int rein;
    int level;
    int myatk;
    int mydef;
    int myhp;
    int mymoney;
public:
    UserInfo():myatk(15),mydef(0),myhp(100),mymoney(0),level(1),rein(0){}
    int returnATK(void) const;
    int returnHP(void)const;
    int returnDEF(void)const;
    int returnMoney(void)const;
    void levelUP();
    void userBeHit(int eatk);//적에게 공격당했을때
    void reinUser(int addatk,int adddef,int addhp,int cnt);//강화 성공시
    void calcmoney(int n);//돈 계산
    void initHP(int curhp);//적과 전투 후 hp 초기화
    void display(void)const;//상태 출력
};

class Enemy//적군에 대한 정보//////////////////////////
{
private:
    int eatk;
    int edef;
    int ehp;
public:
    Enemy(int stage):eatk(10+(3*stage)),edef(1+(2*stage/2)),ehp(45+(stage*13)){}
    int returnEATK(void)const;
    int returnEHP(void)const;
    int returnEDEF(void)const;
    void displayEn(void)const;//상태 출력
    void enemyBeHit(int uatk);//유저에게 공격당했을 시
    //void initEHP(int curehp);
};

class Dungeon:public Enemy{//던전 입장
private:
    int stage;
public:
    Dungeon(int num):Enemy(num){}
    int showFightMenu(void)const;
    int fight(UserInfo ui);//유저와 적군의 싸움
};
//////////////////////////////////////////////////////////
class Reinforce{
private:
    int addatk;
    int adddef;
    int addhp;
    int count;
    int luck;
public:
    Reinforce(int cnt):luck(0),addatk(4),adddef(2),addhp(10),count(1*cnt){}
    int reintry(UserInfo &ui);//강화 시도
    void reinstore(UserInfo &ui);//강화석 구매 함수
};

int jackPot(int money);//잭 팟!
void showMenu(void);//메뉴 출력 함수
int selectMenu(void);//메뉴 선택 함수

int main() {
    srand((unsigned int)time(NULL));
    int select,refight;
    int stagecount=1;
    int reincount=1;
    int cnt=1;
    UserInfo data;
    Dungeon *stage;
    Reinforce *rein;
    while(1){
        data.display();
        select = selectMenu();
        cout<<endl;
        switch(select){
            case 1:
                cout<<"[던전에 입장합니다.]"<<endl;
                cout<<"Stage : "<<stagecount<<endl;
                stage = new Dungeon(stagecount);
                refight=stage->fight(data);
                if(refight == 0){
                    cout<<endl<<"Stage Clear, 보상으로 "<<100*stagecount<<" Money 를 획득합니다."<<endl<<endl;
                    data.calcmoney(100*stagecount);
                    stagecount++;
                    if(stagecount%cnt == 0){
                        cout<<"LEVEL UP !"<<endl;
                        data.levelUP();
                        cnt++;
                    }
                }
                else{
                    cout<<endl<<"도전 실패..."<<endl<<endl;;
                }
                delete stage;
                break;
            case 2:
                cout<<"[캐릭터 강화 화면 입니다.]"<<endl;
                rein = new Reinforce(reincount);
                reincount +=rein->reintry(data);
                delete rein;
                break;
            case 3:
                cout<<"[잭팟에 도전하세요]"<<endl;
                data.calcmoney(jackPot(data.returnMoney()));
                cout<<endl<<"게임 결과 :"<<data.returnMoney()<<endl<<endl;
                break;
            case 4:
                cout<<"클리어 한 Stage :"<<stagecount<<endl;
                return 0;
            default:
                cout<<"유효하지 않은 변수 입니다."<<endl;
                break;
        }
        cout<<"======================================"<<endl;
    }
}
///유저 함수 정의////=============
int UserInfo::returnATK()const{return myatk;}
int UserInfo::returnHP()const{return myhp;}
int UserInfo::returnDEF()const{return mydef;}
int UserInfo::returnMoney()const{return mymoney;}
void UserInfo::userBeHit(int eatk){
    myhp=myhp - ( eatk - mydef);
}
void UserInfo::reinUser(int addatk,int adddef,int addhp,int cnt){
    myatk += addatk;
    myhp += addhp;
    mydef += adddef;
    rein = cnt;
}
void UserInfo::calcmoney(int n){
    mymoney += n;
}
void UserInfo::levelUP(){
    myatk+=2;
    myhp+=10;
    mydef++;
    mymoney = mymoney + (150*level);
    level++;
    if(level%3==0){
        myatk++;
        myhp+=5;
        mydef++;
    }
}
void UserInfo::initHP(int curhp){
    myhp=curhp;
}
void UserInfo::display(void)const{
    cout<<"[[[유저 정보]]]"<<endl;
    cout<<"LV :"<<level<<"( +"<<rein<<" )"<<endl;
    cout<<"ATK :"<<myatk<<endl;
    cout<<"DFE :"<<mydef<<endl;
    cout<<"HP :"<<myhp<<endl;
    cout<<"MONEY :"<<mymoney<<endl<<endl;
}
//적군 함수 정의//==================
int Enemy::returnEATK(void)const{
    return eatk;
}
int Enemy::returnEHP(void)const{
    return ehp;
}
int Enemy::returnEDEF(void)const{
    return edef;
}
void Enemy::enemyBeHit(int uatk){
    ehp=ehp - ( uatk - edef);
}
/*void Enemy::initEHP(int curehp){
    ehp=curehp;
}*/
void Enemy::displayEn(void)const{
    cout<<"[[[적군 정보]]]"<<endl;
    cout<<"ATK :"<<eatk<<endl;
    cout<<"DFE :"<<edef<<endl;
    cout<<"HP :"<<ehp<<endl<<endl;
}
///던전 함수 정의//=================
int Dungeon::showFightMenu(void)const{
    int select;
    cout<<"====[던전 메뉴 선택]===="<<endl;
    cout<<"1. 공격하기"<<endl;
    cout<<"2. 도망가기"<<endl;
    cout<<endl<<"선택 :";
    cin>>select;
    return select;
}

int Dungeon::fight(UserInfo ui){
    int select;
    int curhp = ui.returnHP();
    displayEn();
    while(1){
        if(ui.returnHP() <= 0){
            ui.initHP(curhp);
            return 1;
        }
        else if(returnEHP() <= 0){
            ui.initHP(curhp);
            return 0;
        }
        else{
            select = showFightMenu();
            cout<<endl;
            switch(select){
            case 1:
                    enemyBeHit(ui.returnATK());
                    cout<<"유저가 적을 공격했다."<<endl;
                    ui.userBeHit(returnEATK());
                    cout<<"적이 유저률 공격했다."<<endl<<endl;
                    cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
                    cout<<"유저의 현재 체력: "<<ui.returnHP()<<" <<"<<endl;
                    cout<<"적의 현재 체력: "<<returnEHP()<<" <"<<endl;
                    cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl<<endl;
                break;
            default:
                    ui.initHP(curhp);
                    return -1;
            }
        }
    }
}
//강화 함수 정의//=================
int Reinforce::reintry(UserInfo &ui){
    int plus=0;
    char select;
    if(ui.returnMoney()<500){
        cout<<"Gold가 부족합니다."<<endl;
        cout<<"현재 잔액 :"<<ui.returnMoney()<<endl<<endl;
        return 0;
    }
    cout<<"강화에는 500 GOLD가 소모됩니다."<<endl;
    ui.calcmoney(-500);
    cout<<"현재 잔액"<<ui.returnMoney()<<endl;
    cout<<"현재 강화 확률 : "<<(100-count*3)+plus<<" %"<<endl<<endl<<"강화석(개당 1500Gold)을 구매하시겠습니까?(y/n) :";
    cin>>select;
    if(select == 'y'){
        reinstore(ui);
        plus +=(luck*18);
    }
    cout<<"강화를 시도합니다.(확률: "<<(100-count*3)+plus<<"% )"<<endl;
    int randnum=rand()%100;
    if(randnum<(100-count*3)+plus){
        cout<<"[[강화 성공]]"<<endl;
        ui.reinUser(addatk,adddef,addhp,count);
        return 1;
    }
    else{
        cout<<randnum;
        cout<<"[[강화 실패.....]]"<<endl;
        return 0;
    }
}
void Reinforce::reinstore(UserInfo &ui){
    int money = ui.returnMoney();
    int count;
    cout<<"몇개 구매하시겠습니까? :";
    cin>>count;
    if(money >= count*1500){
        luck = count;
        ui.calcmoney(-(count*1500));
    }
    else{
        cout<<"잔액이 부족합니다."<<endl<<endl;
    }
}
//==================================
void showMenu(){
    cout<<"=====[게임 메뉴 화면]====="<<endl;
    cout<<"1. 던전입장"<<endl;
    cout<<"2. 캐릭터 강화( 보유 500 Gold 이상 )"<<endl;
    cout<<"3. ** 잭 팟 도 전 **( 보유 200 Gold 이상)"<<endl;
    cout<<"4. 게임 포기"<<endl;
    cout<<endl;
}

int selectMenu(){
    int num;
    showMenu();
    cout<<"선택 :";
    cin>>num;
    return num;
}

int jackPot(int money){
    int randnum,a=0;
    char select;
    randnum = rand()%100;
    if(money<200){
        cout<<"저런..돈이없으시네요.."<<endl;
        return money;
    }
    cout<<"잭팟에 도전하시겠습니까?(y/n): ";
    cin>>select;
    if(select=='y'){
        if(randnum%2==0){
            a +=300;
        }
        else{
            a -=200;
        }
         return a;
    }
    return 0;
}
