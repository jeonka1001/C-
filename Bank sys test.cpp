//
//  main.cpp
//  HW12_20200210
//
//  Created by 전경안 on 2020/02/10.
//  Copyright © 2020 전경안. All rights reserved.
//

#include <iostream>
#define NAME_LEN 20
using namespace std;
class Save{
private:
    char name[NAME_LEN];
    int capital;
    int profit;
    int tax;
    int tot;
    static double ratio;
public:
    static double tax_ratio;
    Save(const char *np="아무개",int n=0):capital(n),profit(capital*ratio),tax(profit*tax_ratio){
        strcpy(name,np);
    }
    void calculate();
    static void set_ratio(double r);
    void getInfo()const;
};
double Save::ratio = 0.2;
double Save::tax_ratio = 0.1;
void Save::calculate(){
    profit = capital*ratio;
    tax = profit*tax_ratio;
    tot = capital + profit - tax;
}
void Save::set_ratio(double r){
    ratio = r;
}
void Save::getInfo()const{
    cout<<"이름 :"<<name<<endl;
    cout<<"원금 :"<<capital<<endl;
    cout<<"이자소득 :"<<profit<<endl;
    cout<<"세금 :"<<tax<<endl;
    cout<<"총금액 :"<<tot<<endl;
    cout<<"이율 :"<<ratio<<endl;
    cout<<"세율 :"<<tax_ratio<<endl<<endl;
}
int main(int argc, const char * argv[]) {
    Save a("철이",1000000),b("메텔", 2000000);
    a.calculate();
    a.getInfo();
    Save::tax_ratio=0.15;
    Save::set_ratio(0.25);
    b.calculate();
    b.getInfo();
    return 0;
}
