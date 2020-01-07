//
//  main.cpp
//  2-5좌표 연산
//
//  Created by 전경안 on 2020/01/07.
//  Copyright © 2020 전경안. All rights reserved.
//

#include <iostream>
using namespace std;
typedef struct __point{
    int xpos;
    int ypos;
}point;

point& pointadd(const point &p1ref,const point &p2ref){
    point *ps=new point;
    ps->xpos = p1ref.xpos + p2ref.xpos;
    ps->ypos = p1ref.ypos + p2ref.ypos;
    return *ps;
}
int main() {
    point *p1=new point;
    cout<<"x,y좌표를 입력하세요:";
    cin>>p1->xpos>>p1->ypos;
    
    point *p2=new point;
    cout<<"x좌표를 입력하세요:";
    cin>>p2->xpos>>p2->ypos;
    
    point &psum = pointadd(*p1,*p2);//point 타입의 주소참조변수
    
    cout<<"두 좌표의 합은 : "<< "( " <<psum.xpos<<" , "<<psum.ypos<<" )"<<endl;
    delete p1;//32와 마찬가지
    delete p2;//포인터의 주소를 지우면 다 지워짐
    delete &psum;//참조하는 대상의 메모리를 지움
    return 0;
}
