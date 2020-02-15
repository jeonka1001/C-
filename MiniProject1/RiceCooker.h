//
//  RiceCooker.hpp
//  MiniProject
//
//  Created by 전경안 on 2020/02/15.
//  Copyright © 2020 전경안. All rights reserved.
//


#ifndef __RICECOOKER_H__
#define    __RICECOOKER_H__
#include "Appliance.h"
#include <iostream>
#pragma warning (disable:4996)
using namespace std;
class RiceCooker : public Appliance
{
private:
    int machineState; // 제품상태(1:무동작, 2:보온, 3:밥짓기, 4:데우기)
    public :
    RiceCooker(); // Appliance는 default생성자로 생성, machineState는 무동작으로 초기화
    RiceCooker(string machineName); // Appliance는 Overloaded 생성자로 생성, machineState는 무동작으로 초기화
    // getter, setter member function
    int getMachineState() const; // machineState 멤버 값 반환 함수
    void setMachineState(int machineState); // machineState 멤버 초기화 함수
    // member function
    void stateView(); // 객체의 상태 출력
    enum {NO_OPERATION=1, WARM, COOK, HEAT}; // 밥솥의 상태를 나타내는 열거형 상수
};
#endif
