//
//  Homeautomation.cpp
//  testMain
//
//  Created by 전경안 on 2020/02/17.
//  Copyright © 2020 전경안. All rights reserved.
//

#include "HomeAutomation.h"
HomeAutomation::HomeAutomation():applianceCnt(0){
    for(int i=0;i<APPLIANCE_MAX_CNT;i++){
        applianceArray[i]=NULL;
    }
}
HomeAutomation::HomeAutomation(const HomeAutomation &r):applianceCnt(r.applianceCnt){
    for(int i=0;i<r.applianceCnt;i++){
        if(dynamic_cast<Washer *>(r.applianceArray[i])){
            this->applianceArray[i] = new Washer(r.applianceArray[i]->getMachineName(),r.applianceArray[i]->getPowerConsumption());
        }
        if(dynamic_cast<RiceCooker *>(r.applianceArray[i])){
            this->applianceArray[i] = new RiceCooker(r.applianceArray[i]->getMachineName(),r.applianceArray[i]->getPowerConsumption());
        }
        if(dynamic_cast<AirConditioner *>(r.applianceArray[i])){
            this->applianceArray[i] = new AirConditioner(r.applianceArray[i]->getMachineName(),r.applianceArray[i]->getPowerConsumption());
        }
        applianceArray[i]->setPowerFlag(r.applianceArray[i]->getPowerFlag());
    }
}
HomeAutomation::~HomeAutomation(){
    for(int i=0;i<applianceCnt;i++){
        delete applianceArray[i];
    }
}

// getter, setter member function
Appliance ** HomeAutomation::getApplianceArray(){
    return applianceArray;
}
int HomeAutomation::getApplianceCnt() const {
    return applianceCnt;
}

// member function
HomeAutomation & HomeAutomation::operator=(const HomeAutomation &r){
    if(this==&r)return *this;
    for(int i=0;i<applianceCnt;i++){
        delete applianceArray[i];
    }
    applianceCnt=r.applianceCnt;
    for(int i=0;i<r.applianceCnt;i++){
        if(dynamic_cast<Washer *>(r.applianceArray[i])){
            this->applianceArray[i] = new Washer(r.applianceArray[i]->getMachineName(),r.applianceArray[i]->getPowerConsumption());
        }
        if(dynamic_cast<RiceCooker *>(r.applianceArray[i])){
            this->applianceArray[i] = new RiceCooker(r.applianceArray[i]->getMachineName(),r.applianceArray[i]->getPowerConsumption());
        }
        if(dynamic_cast<AirConditioner *>(r.applianceArray[i])){
            this->applianceArray[i] = new AirConditioner(r.applianceArray[i]->getMachineName(),r.applianceArray[i]->getPowerConsumption());
        }
        applianceArray[i]->setPowerFlag(r.applianceArray[i]->getPowerFlag());
    }
    return *this;
}

bool HomeAutomation::addAppliance(Appliance *ap){
    if(this->searchMachine(ap->getMachineName())!=-1)return false;
    if(dynamic_cast<Washer *>(ap)){
        applianceArray[applianceCnt]=new Washer(ap->getMachineName(),ap->getPowerConsumption());
    }
    if(dynamic_cast<AirConditioner *>(ap)){
        applianceArray[applianceCnt]=new AirConditioner(ap->getMachineName(),ap->getPowerConsumption());
    }
    if(dynamic_cast<RiceCooker *>(ap)){
        applianceArray[applianceCnt]=new RiceCooker(ap->getMachineName(),ap->getPowerConsumption());
    }
    applianceCnt++;
    return true;
}

int HomeAutomation::searchMachine(string machineName){
    for(int i=0;i<applianceCnt;i++){
        if(applianceArray[i]->getMachineName() == machineName)return i;
    }
    return -1;
}

bool HomeAutomation::deleteAppliance(string machineName){
    int delnum = searchMachine(machineName);
    if(delnum==-1)return false;
    delete applianceArray[delnum];
    for(int i=delnum;i<applianceCnt -1;i++){
        applianceArray[i]=applianceArray[i+1];
    }
    applianceCnt--;
    return true;
}

void HomeAutomation::listDisplayAppliance(){
    for(int i=0;i<applianceCnt;i++){
        applianceArray[i]->stateView();
    }
}

bool HomeAutomation::controlAppliance(string machineName){
    int selNum=searchMachine(machineName);
    char n;
    if(selNum ==-1)return false;
    if(applianceArray[selNum]->getPowerFlag() == false){
        cout << "전원을 켜시겠습니까?(Y/N) :";
        cin >>n;
        if(n=='y'||n=='Y'){
            applianceArray[selNum]->setStartHour();
            applianceArray[selNum]->turnOn();
            setStateAppliance(applianceArray[selNum]);
            return true;
        }
        else return false;
    }
    setStateAppliance(applianceArray[selNum]);
    return true;
}

void HomeAutomation::setStateAppliance(Appliance * ap){
    int select;
    if(dynamic_cast<Washer *>(ap)){
        while(1){
            cout <<"모드변경(1.무동작/2.일반빨래/3.삶은빨래/4.건조/5.끄기):";
            cin >>select;
            switch(select){
                case 1:
                    dynamic_cast<Washer *>(ap)->setMachineState(Washer::NO_OPERATION);
                    return;
                case 2:
                    dynamic_cast<Washer *>(ap)->setMachineState(Washer::GENERAL);
                    return;
                case 3:
                    dynamic_cast<Washer *>(ap)->setMachineState(Washer::BOIL);
                    return;
                case 4:
                    dynamic_cast<Washer *>(ap)->setMachineState(Washer::DRY);
                    return;
                case 5:
                    dynamic_cast<Washer *>(ap)->setMachineState(Washer::NO_OPERATION);
                    ap->setUseHour();
                    ap->turnOff();
                    return;
                default:
                    break;
            }
        }
    }
    if(dynamic_cast<AirConditioner *>(ap)){
        while(1){
            cout <<"모드변경(1.송풍/2.냉방/3.난방/4.끄기):";
            cin >>select;
            switch(select){
                case 1:
                    dynamic_cast<AirConditioner *>(ap)->setMachineState(AirConditioner::SENDAIR);
                    return;
                case 2:
                    dynamic_cast<AirConditioner *>(ap)->setMachineState(AirConditioner::COOLER);
                    return;
                case 3:
                    dynamic_cast<AirConditioner *>(ap)->setMachineState(AirConditioner::HEATER);
                    return;
                case 4:
                    dynamic_cast<AirConditioner *>(ap)->setMachineState(AirConditioner::SENDAIR);
                    ap->setUseHour();
                    ap->turnOff();
                    return;
                default:
                    break;
            }
        }
    }
    if(dynamic_cast<RiceCooker *>(ap)){
        while(1){
            cout <<"모드변경(1.무동작/2.보온/3.밥짓기/4.데우기/5.끄기):";
            cin >>select;
            switch(select){
                case 1:
                    dynamic_cast<RiceCooker *>(ap)->setMachineState(RiceCooker::NO_OPERATION);
                    return;
                case 2:
                    dynamic_cast<RiceCooker *>(ap)->setMachineState(RiceCooker::WARM);
                    return;
                case 3:
                    dynamic_cast<RiceCooker *>(ap)->setMachineState(RiceCooker::COOK);
                    return;
                case 4:
                    dynamic_cast<RiceCooker *>(ap)->setMachineState(RiceCooker::HEAT);
                    return;
                case 5:
                    dynamic_cast<RiceCooker *>(ap)->setMachineState(RiceCooker::NO_OPERATION);
                    ap->setUseHour();
                    ap->turnOff();
                    return;
                default:
                    break;
            }
        }
    }
    
}
