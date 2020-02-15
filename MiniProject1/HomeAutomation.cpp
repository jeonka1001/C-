//
//  HomeAutomation.cpp
//  MiniProject
//
//  Created by 전경안 on 2020/02/15.
//  Copyright © 2020 전경안. All rights reserved.
//

#include "HomeAutomation.h"

HomeAutomation::HomeAutomation():riceCookerCnt(0) {
    for (int i = 0; i < Appliance_MAX_CNT; i++) {
        riceCookerArray[i] = NULL;
    }
}
HomeAutomation::HomeAutomation(const HomeAutomation &r):riceCookerCnt(r.riceCookerCnt) {
    for (int i = 0; i < riceCookerCnt; i++) {
        riceCookerArray[i] = new RiceCooker[i];
        riceCookerArray[i]->setMachineName(r.riceCookerArray[i]->getMachineName());
        riceCookerArray[i]->setPowerFlag(r.riceCookerArray[i]->getPowerFlag());
        riceCookerArray[i]->setMachineState(r.riceCookerArray[i]->getMachineState());
    }
}
HomeAutomation::~HomeAutomation() {
    for (int i = 0; i < riceCookerCnt; i++) {
        delete riceCookerArray[i];
    }
}

// getter, setter member function
RiceCooker ** HomeAutomation::getRiceCookerArray() {
    return riceCookerArray;
}
int HomeAutomation::getRiceCookerCnt() const {
    return riceCookerCnt;
}

// member function
HomeAutomation & HomeAutomation::operator=(const HomeAutomation &r) {
    if (this == &r)return *this;
    for (int i = 0; i < riceCookerCnt; i++) {
        delete riceCookerArray[i];
    }
    for (int i = 0; i < riceCookerCnt; i++) {
        riceCookerArray[i] = new RiceCooker[i];
        riceCookerArray[i]->setMachineName(r.riceCookerArray[i]->getMachineName());
        riceCookerArray[i]->setPowerFlag(r.riceCookerArray[i]->getPowerFlag());
        riceCookerArray[i]->setMachineState(r.riceCookerArray[i]->getMachineState());
    }
    riceCookerCnt=r.riceCookerCnt;
    return *this;
}
bool HomeAutomation::addAppliance(RiceCooker *ap) {
    if (searchMachine(ap->getMachineName())!=-1) {
        cout << "밥솥 이름 중복" << endl << endl;
        return false;
    }
    riceCookerArray[riceCookerCnt] = new RiceCooker;
    riceCookerArray[riceCookerCnt]->setMachineName(ap->getMachineName());
    riceCookerArray[riceCookerCnt]->setPowerFlag(ap->getPowerFlag());
    riceCookerArray[riceCookerCnt]->setMachineState(ap->getMachineState());
    riceCookerCnt++;
    return true;
}
int HomeAutomation::searchMachine(string machineName) {
    for (int i=0; i < riceCookerCnt; i++) {
        if (riceCookerArray[i]->getMachineName() == machineName) {
            return i;
        }
    }
    cout << "**동일 이름의 제품이 없습니다." << endl;
    return -1;
}
bool HomeAutomation::deleteAppliance(string machineName) {
    int index = searchMachine(machineName);
    if (index!=-1) {
        delete riceCookerArray[index];
        for (int i = index; i < riceCookerCnt-1; i++) {
            riceCookerArray[i] = riceCookerArray[i + 1];
        }
        riceCookerCnt--;
        return true;
    }
    return false;
}
void HomeAutomation::listDisplayAppliance() {
    for (int i = 0; i < riceCookerCnt; i++) {
        riceCookerArray[i]->stateView();
    }
}
bool HomeAutomation::controlAppliance(string machineName) {
    int index = searchMachine(machineName);
    if (index == -1)return false;
    if (riceCookerArray[index]->getPowerFlag() == true) {
        cout <<"전원이 이미 켜졌습니다."<<endl;
        setStateAppliance(riceCookerArray[index]);
        return true;
    }
    else {
        char n;
        cout << "전원을 켜시겠습니까?(Y/N) :";
        cin >> n;
        if(n != 'Y')return false;
        riceCookerArray[index]->turnOn();
        cout <<"전원이 켜졌습니다."<<endl;
        setStateAppliance(riceCookerArray[index]);
        return true;
    }
}
void HomeAutomation::setStateAppliance(RiceCooker * ap) {
    cout <<"가전제품 동작 선택(1.대기/2.보온/3.취사/4.데우기) :";
    int num;
    cin >>num;
    switch(num){
        case 1:
            ap->setMachineState(num);
            break;
        case 2:
            ap->setMachineState(num);
            break;
        case 3:
            ap->setMachineState(num);
            break;
        case 4:
            ap->setMachineState(num);
            break;
        default:
            break;
    }
}
