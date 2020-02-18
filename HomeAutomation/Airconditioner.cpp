//
//  Airconditioner.cpp
//  testMain
//
//  Created by 전경안 on 2020/02/17.
//  Copyright © 2020 전경안. All rights reserved.
//

#include "Airconditioner.h"
AirConditioner::AirConditioner():Appliance(),setTemperature(DEFAULT_TEMP),machineState(SENDAIR){}
AirConditioner::AirConditioner(string machineName, int powerConsumption)
:Appliance(machineName,powerConsumption),machineState(SENDAIR)
{}
// getter, setter member function
int AirConditioner::getMachineState() const{
    return this->machineState;
}
int AirConditioner::getSetTemperature() const{
    return this->setTemperature;
}
void AirConditioner::setMachineState(int machineState){
    this->machineState=machineState;
}
void AirConditioner::setSetTemperature(int setTemperature){
    this->setTemperature = setTemperature;
}
AirConditioner & AirConditioner::operator++(){
    this->setTemperature++;
    return *this;
}
AirConditioner & AirConditioner::operator--(){
    this->setTemperature--;
    return *this;
}
AirConditioner AirConditioner::operator++(int ){
    AirConditioner tmp(getMachineName(),getPowerConsumption());
    this->setTemperature++;
    return tmp;
}
AirConditioner AirConditioner::operator--(int ){
    AirConditioner tmp(getMachineName(),getPowerConsumption());
    this->setTemperature--;
    return tmp;
}
void AirConditioner::stateView(){
    cout << "제품명 : " << Appliance::getMachineName();
    if (Appliance::getPowerFlag() == true)cout << " (ON) ";
    else {
        cout << " (OFF) "<<endl;
        return ;
        
    }
    cout << "설정상태 : ";
    switch(machineState){
        case SENDAIR:
            cout <<"송품";
            break;
        case COOLER:
            cout <<"냉방";
            break;
        case HEATER:
            cout<<"난방";
            break;
    }
    cout <<endl;
}
enum {SENDAIR=1, COOLER, HEATER};
