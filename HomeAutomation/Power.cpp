//
//  Power.cpp
//  testMain
//
//  Created by 전경안 on 2020/02/17.
//  Copyright © 2020 전경안. All rights reserved.
//
#include "HomeAutomation.h"
#include "Power.h"
#include <ctime>

int Power::calPowerConsumption(HomeAutomation &rHa){
    int restime=0;
    for(int i=0;i<rHa.applianceCnt;i++){
        if(rHa.applianceArray[i]->getPowerFlag() == false){
            restime += rHa.applianceArray[i]->getUseHour() * rHa.applianceArray[i]->getPowerConsumption();
        }
    }
    return restime;
}
