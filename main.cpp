#include <iostream>
#include <cstring>
#include "Robot.h"
#define NAME_LEN 100
using namespace std;

int input(void);// 생성할 로봇 개수 입력
void input(Robot*,int);//

void work(Robot*,int);//

void outName(Robot*,int);//
void output(Robot*, int);

void myflush();

int main() {
    int rCnt,i;
    char tName[NAME_LEN];
    rCnt = input();
    Robot *rp = new Robot[rCnt];;
    
    input(rp,rCnt);
    cin.getline(tName,NAME_LEN);
    while (1) {
        outName(rp, rCnt);//로봇명 선택
        cin.getline(tName,NAME_LEN);
        if(strcmp(tName,"\0")==0){
            break;
        }
        for(i=0;i<rCnt;i++){
            if(strcmp(rp[i].getName(),tName)==0){
                work(rp, i);
                myflush();
                break;
            }
        }
        if(i==rCnt){
            cout<<"다시 입력하세요 "<<endl;
        }
    }
    output(rp,rCnt);
    
    delete[] rp;
    
    return 0;
}

void myflush(){
    cin.clear();
    while(cin.get()!='\n'){
        ;
    }
    return;
}
void output(Robot*rp, int rCnt) {
    for (int i = 0; i < rCnt; i++) {
        cout <<i+1<<". "<< rp[i].getName()<<" :";
        cout << rp[i].getEnergy() << endl;
    }
}

int input(void) {
    int num;
    while(1){
        cout << "구입할 로봇 대수를 입력하시오 :";
        cin >> num;
        if(cin.fail()){
            myflush();
        }
        else{
            if(num<=0){
                ;
            }
            else{
                return num;
            }
        }
    }
}
void input(Robot *rrp,int rCnt) {
    int energy=0,i=0;
    char name[NAME_LEN];
    while(i!=rCnt){
        cout << i+1 << "번 로봇명을 입력하시오 :";
        cin >> name;
        cout << name << "의 에너지 양을 입력하시오 :";
        cin >> energy;
        if(cin.fail()||energy<=0){
            myflush();
        }
        else{
            rrp[i].setName(name);
            rrp[i].setEnergy(energy);
            i++;
        }
    }
    return ;
}
void outName(Robot *rp,int rCnt) {
    cout <<endl<< " # 로봇명 선택 (";
    for (int i = 0; i < rCnt; i++) {
        cout << rp[i].getName() << " ";
    }
    cout << ") :";
}
void work(Robot *rp, int select) {
    int num,ee,cnt=0;
    while(cnt!=1){
        cout << "# 할 일 선택 (1.전진/2.후진/3.회전/4.점프/5.충전):";
        cin >> num;
        switch (num) {
            case 1:
                rp[select].go();
                cnt=1;
                break;
            case 2:
                rp[select].back();
                cnt=1;
                break;
            case 3:
                rp[select].turn();
                cnt=1;
                break;
            case 4:
                rp[select].jump();
                cnt=1;
                break;
            case 5:
                cout << "충전할 에너지양 입력 :";
                cin >> ee;
                rp[select].charge(ee);
                cnt=1;
                break;
            default:
                cout<<"다시 입력하세요."<<endl;
                myflush();
                break;
        }
    }
}
