//
//  Appliance.cpp
//  MiniProject
//
//  Created by 전경안 on 2020/02/15.
//  Copyright © 2020 전경안. All rights reserved.
//

#include "Appliance.h"

Appliance::Appliance():machineName(""), powerFlag(false){}
Appliance::Appliance(string machineName, bool powerFlag)
:machineName(machineName),powerFlag(powerFlag){}
string Appliance::getMachineName() const {
    return machineName;
}
bool Appliance::getPowerFlag() const {
    return powerFlag;
}
void Appliance::setMachineName(string machineName) {
    this->machineName = machineName;
}
void Appliance::setPowerFlag(bool powerFlag) {
    this->powerFlag = powerFlag;
}

bool Appliance::turnOn() {
    if (powerFlag = true) {
        return false;
    }
    else {
        powerFlag = true;
        return true;
    }
}
bool Appliance::turnOff() {
    if (powerFlag = false) {
        return false;
    }
    else {
        powerFlag = true;
        return true;
    }
}
void Appliance::stateView() {
    cout << machineName << ": ";
    if(powerFlag ==1){
        cout<<"켜짐/";
    }
    else{
        cout <<"꺼짐/";
    }
}
