//
//  Appliance.hpp
//  MiniProject
//
//  Created by 전경안 on 2020/02/15.
//  Copyright © 2020 전경안. All rights reserved.
//

#ifndef __APPLIANCE_H__
#define __APPLIANCE_H__
#include <iostream>
#include <string>
using namespace std;

class Appliance
{
private:
    string machineName;  // 가전제품명
    bool powerFlag;  // 전원 on_off상태(on-ture, off-false)
    public :
    // constructor, destructor : deep copy cons.와 destructor는 별도로 선언,정의 안함
    Appliance();  // default constructor (machineName:Null string, powerFlag:false)
    Appliance(string machineName,bool powerFlag=false);
    ~Appliance() { } //소멸자
    // getter, setter member function
    string getMachineName() const;  // machineName 멤버값 반환 함수
    bool getPowerFlag() const; // powerFlag 멤버 값 반환 함수
    void setMachineName(string machineName);  // machineName 멤버 초기화 함수
    void setPowerFlag(bool powerFlag); // powerFlag 멤버 초기화 함수
    // member fucntion
    bool turnOn(); // 제품을 켜다
    bool turnOff(); // 제품을 끄다
    void stateView(); // 제품의 상태를 출력하다
};
#endif
