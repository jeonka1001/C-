//
//  main.cpp
//  HW15_20200212
//
//  Created by 전경안 on 2020/02/12.
//  Copyright © 2020 전경안. All rights reserved.
//

#include <iostream>
#include <cstring>
#define ARY_NUM 100
using namespace std;

class Fitness{
    int num;
    char* name;
    double weight;
    double height;
public:
    Fitness():num(0),weight(0),height(0){
        name = NULL;
    };
    Fitness(int n,char* np,double w,double h):num(n),weight(w),height(h){
        this->name = new char[strlen(np)+1];
        strcpy(this->name,np);
    }
    Fitness(Fitness& fr):num(fr.num),weight(fr.weight),height(fr.height){
        this->name = new char[strlen(fr.name)+1];
        strcpy(this->name,fr.name);
    }
    ~Fitness(){
        delete[] name;
    }
    Fitness& operator=(Fitness&fr);
    bool operator==(Fitness&r);
    double bmi()const;
    char* getName()const;
    void setName(char* tmp);
    double getWeight()const;
    double getHeight()const;
    int getNum()const;
};
double Fitness::bmi()const{
    double rbmi;
    rbmi = weight / (height*height);
    return rbmi*10000;
}
Fitness& Fitness::operator=(Fitness& fr){
    if(this==&fr)return *this;
    delete[] this->name;
    this->name = new char[strlen(fr.name)+1];
    strcpy(this->name,fr.name);
    this->height = fr.height;
    this->weight = fr.weight;
    this->num = fr.num;
    return *this;
}
bool Fitness::operator==(Fitness&r){
    if(strcmp(this->name,r.name)==0)return true;
    else{return false;}
}

char* Fitness::getName()const {return name;}
double Fitness::getWeight()const{return weight;}
double Fitness::getHeight()const{return height;}
int Fitness::getNum()const{return num;}
void Fitness::setName(char* tmp){
    if(this->name!=NULL){
        delete[] name;
    }
    this->name = new char[strlen(tmp)+1];
    strcpy(this->name,tmp);
}

void input(Fitness *&frp,int num);
void showAllInfo(const Fitness *ff);
bool searchInfo(Fitness* fp,char *tmp);
void deleteInfo(Fitness*(far[]),int num,int& cnt);
int showMenu();
void myflush();

int main(int argc, const char * argv[]) {
    int resmenu;
    Fitness *fary[ARY_NUM];
    int memberCnt=0,numCnt=1,cnt=0;
    while(1){
        resmenu = showMenu();
        switch(resmenu){
            case 1:
                cout<<"==[회원 등록 메뉴]=="<<endl;
                input(fary[memberCnt],numCnt);
                numCnt++;
                memberCnt++;
                break;
            case 2:
                cout<<"==[회원정보 출력 메뉴]=="<<endl;
                for(int i=0;i<memberCnt;i++){
                    showAllInfo(fary[i]);
                }
                break;
            case 3:
                char temp[20];
                cout<<"==[회원 정보 검색 메뉴]=="<<endl;
                cout<<"검색 할 이름을 입력하시오 :";
                cin >> temp;
                for(int i=0;i<memberCnt;i++){
                    if(searchInfo(fary[i],temp)){
                        showAllInfo(fary[i]);
                        cnt++;
                    }
                }
                if(cnt==0){
                    cout<<"존재하지 않는 회원입니다."<<endl;
                }
                cnt=0;
                break;
            case 4:
                int num;
                cout<<"==[회원 탈퇴 메뉴]=="<<endl;
                cout<<"탈퇴 할 회원번호를 입력하시오 :";
                cin >> num;
                for(int i=0;i<memberCnt;i++){
                    if(num == fary[i]->getNum()){
                        delete fary[i];
                        deleteInfo(fary,i,memberCnt);
                        memberCnt--;
                        cnt++;
                    }
                }
                if(cnt==0){
                    cout<<"존재하지 않는 회원입니다."<<endl;
                }
                cnt=0;
                break;
            case 5:
                cout<<"==[특별관리 회원 출력]=="<<endl;
                for(int i=0;i<memberCnt;i++){
                    if(fary[i]->bmi()>=25.0){
                        showAllInfo(fary[i]);
                    }
                }
                break;
            default:
                for(int i=0;i<memberCnt;i++){
                    delete fary[i];
                }
                return 0;
        }
    }
}
void deleteInfo(Fitness*(far[]),int num,int& cnt){
    for(int i=num;i<cnt;i++){
        far[i]=far[i+1];
    }
}
bool searchInfo(Fitness* fp,char *tmp){
    Fitness temp;
    temp.setName(tmp);
    if(*fp==temp){
        return true;
    }
    else{return false;}
}
void showAllInfo(const Fitness *ff){
    cout<<ff->getName()<<" : "<<"No. "<<ff->getNum()<<"/ "<<ff->getHeight()<<" cm/ "<<ff->getWeight()<<" kg";
    if(ff->bmi()<18.5){cout<<"(저체중)"<<endl;}
    else if(18.5<=ff->bmi()&&ff->bmi()<25.0){cout<<"(정상체중)"<<endl;}
    else if(25.0<=ff->bmi()&&ff->bmi()<30.0){cout<<"(과체중)"<<endl;}
    else if(30.0<=ff->bmi()&&ff->bmi()<40.0){cout<<"(비만)"<<endl;}
    else{cout<<"(고도비만)"<<endl;}
}
void input(Fitness *&frp,int num){
    char tname[20];
    double tweight,theight;
    cout<<"성명 :";
    cin >> tname;
    cout<<"몸무게(kg):";
    cin >> tweight;
    cout<<"키(cm):";
    cin>>theight;
    frp = new Fitness(num,tname,tweight,theight);
}
int showMenu(){
    int select;
    while(1){
        cout<<"1. 회원등록"<<endl<<"2. 회원전체보기"<<endl<<"3. 회원정보검색"<<endl<<"4. 회원탈퇴"<<endl
        <<"5. 특별관리회원"<<endl<<"6. 종료"<<endl;
        cout<<"선택 :";
        cin >>select;
        if(1<=select&&select<=6)return select;
        else{
            cout<<"다시 입력하세요"<<endl<<endl;
            myflush();
        }
    }
}
void myflush(){
    cin.clear();
    while(cin.get()!='\n'){
        ;
    }
    return ;
}
