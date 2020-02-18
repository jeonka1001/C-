//
//  Washer.cpp
//  testMain
//
//  Created by 전경안 on 2020/02/17.
//  Copyright © 2020 전경안. All rights reserved.
//

#include "Washer.h"

Washer::Washer()
:Appliance(),machineState(NO_OPERATION){}
Washer::Washer(string machineName, int powerConsumption)
:Appliance(machineName,powerConsumption),machineState(NO_OPERATION){}
// getter, setter member function
int Washer::getMachineState() const{
    return this->machineState;
}
void Washer::setMachineState(int machineState){
    this->machineState = machineState;
}
// member function
void Washer::stateView(){
    cout << "제품명 : " << Appliance::getMachineName();
    if (Appliance::getPowerFlag() == true)cout << " (ON) ";
    else {
        cout << " (OFF) "<<endl;
        return ;
    }
    cout << "설정상태 : ";
    switch(machineState){
        case NO_OPERATION:
            cout <<"무동작";
            break;
        case GENERAL:
            cout <<"일반빨래";
            break;
        case BOIL:
            cout<<"삶은빨래";
            break;
        case DRY:
            cout<<"건조";
            break;
    }
    cout <<endl;
}
enum {NO_OPERATION=1, GENERAL, BOIL, DRY}; // 세탁기의 상태를 나타내는 열거형 상수
