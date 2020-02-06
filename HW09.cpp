#include <time.h>
//#include<windows.h>
#include<iostream>
#include <cstring>
#include <cstdlib>
#define ITEM_LEN 50
#define DAY_START 0 //1900.01.01을 0일로 카운트를 한다.(1900.01.01을 1일로 계산할 시 1로 변경)
using namespace std;

struct date {
    unsigned int da_year;
    unsigned int da_mon;
    unsigned int da_day;
};

struct Goods{
    char item[ITEM_LEN];
    int price;
    int year;
    int mon;
    int day;
    int discount;
};
void input(Goods &s);//
void sellingPrice(Goods &s);//
void prn(const Goods &s);
int totDays(int y,int m,int d);//
int leapCheck(int year);//
void getdate(struct date *);//

int main()
{
    struct date stdate;//오늘 날짜 저장
    struct Goods userInput;
    getdate(&stdate);
    input(userInput);
    
    int inputtotal,totaldate;
    inputtotal = totDays(userInput.year,userInput.mon,userInput.day);
    totaldate = totDays(stdate.da_year,stdate.da_mon,stdate.da_day);
    userInput.discount =  inputtotal - totaldate ;
    
    sellingPrice(userInput);
    prn(userInput);
    return 0;
}


void getdate(struct date *p) // 원본 데이터를 변환할수 있도록 Call by pointer 기법 사용
{
    /*p->da_year = 2020;
    p->da_mon = 2;
     p->da_day=6;*/ //s_strdate(temp); 함수에 Use of undeclared identifier '_strdate' 에러떠서 주석처리한 데이터를 활용했습니다!
    char temp[128];
    char *cp, syear[5] = "20";
    _strdate(temp); // temp char배열 안에 08/10/04(월/일/년)순으로 년월일이 문자열 상태로 저장
    cp = strtok(temp, "/"); // temp배열의 첫번째 '/'까지 문자열를 끊어내어 cp에게 "08" 문자열의 시작주소를 리턴
    p->da_mon = atoi(cp); // 끊어낸 "08"문자열을 정수형 데이터 8로 변환하여 p->da_mon에 저장
    cp = strtok(NULL, "/"); // temp배열의 두번째 '/'까지 문자열를 끊어내어 cp에게 "10" 문자열의 시작주소를 리턴
    p->da_day = atoi(cp); // 끊어낸 "10"문자열을 정수형 데이터 10로 변환하여 p->da_day에 저장
    cp = strtok(NULL, "/"); // temp배열의 세번째 '/'까지 문자열를 끊어내려하나 '/'은 나타나지 않고 문자열이
    // 끝나게 되므로 남은 문자열 전체를 리턴한다 즉, cp에게 "04" 문자열의 시작주소가 리턴한다.
    strcat(syear, cp); // syear내의 "20"과 cp가 가리키는 "04"을 붙여서 "2004" 문자열을 syear변수에 저장
    p->da_year = atoi(syear); // syear내의 "2004" 문자열을 정수형 데이터 2004로 변환하여 p->da_year에 저장
}
void prn(const Goods &s){
    cout << "품명 :"<<s.item<<endl;
    cout<<"판매가 :"<<s.price<<endl;
    cout<< "유통기한 :"<<s.year<<"년 "<<s.mon<<"월 "<<s.day<<"일"<<endl;
    cout<<"할인율 :"<<s.discount<<"%"<<endl;
}
int leapCheck(int year){
    if(year%400==0||(year%4==0&&year%100!=0)){
        return 1;
    }
    return 0;
}
int totDays(int y,int m,int d){
    int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int totdate=DAY_START;
    for(int i=1900;i<y;i++){
        if(leapCheck(i)==1){
            totdate++;//윤년일 경우 1일씩 증가
        }
        totdate+=365;
    }
    for(int j=0;j<m-1;j++){
        totdate+=month[j];
        if(j==1&&leapCheck(y)==1){//2월에 해당 할 때 운년 체크 후 운년이면 1일 증가
            totdate++;
        }
    }
    totdate+=d;
    return totdate;
}

void sellingPrice(Goods &s){
    if(0<=s.discount&&s.discount<=3){
        s.price *=0.5;
        s.discount = 50;
    }
    else if(4<=s.discount&&s.discount<=10){
        s.price *=0.8;
        s.discount = 20;
    }
    else{
        if(s.discount<0){
            cout<<endl<<" ** 유통기한이 지났습니다. ** "<<endl;
        }
        s.discount = 0;
    }
}

void input(Goods &s){
    cout<<"품목 입력 :";
    cin.getline(s.item,ITEM_LEN);
    cout << "정가 입력 :";
    cin >> s.price;
    cout << "유통기한 입력 :";
    cin >> s.year >> s.mon >> s.day;
}
