//
//  Appliance.cpp
//  testMain
//
//  Created by 전경안 on 2020/02/17.
//  Copyright © 2020 전경안. All rights reserved.
//

#include "Appliance.h"

Appliance::Appliance():machineName(NULL),powerFlag(false),powerConsumption(0)
{}
Appliance::Appliance(string machineName, int powerConsumption, bool powerFlag, time_t startHour, time_t useHour)
:machineName(machineName),powerConsumption(powerConsumption),powerFlag(powerFlag),startHour(startHour),useHour(useHour)
{}
// getter, setter member function
string Appliance::getMachineName() const {
    return this->machineName;
}
bool Appliance::getPowerFlag() const {
    return this->powerFlag;
}

int Appliance::getPowerConsumption() const {
    return this->powerConsumption;
}
time_t Appliance::getStartHour() {
    return startHour;
}
void Appliance::setStartHour(){
    time(&startHour);
}
time_t Appliance::getUseHour() {
    return useHour;
}
void Appliance::setUseHour(){
    time_t n;
    useHour = time(&n) - this->startHour;
    startHour = 0;
}
void Appliance::setMachineName(string machineName) {
    this->machineName = machineName;
}
void Appliance::setPowerFlag(bool powerFlag) {
    this->powerFlag = powerFlag;
}
void Appliance::setPowerConsumption(int powerConsumption) {
    this->powerConsumption = powerConsumption;
}
bool Appliance::turnOn() {
    if (powerFlag == true)return false;
    this->powerFlag = true;
    return true;
}
bool Appliance::turnOff() {
    if (powerFlag == false)return false;
    this->powerFlag = false;
    return true;
}
