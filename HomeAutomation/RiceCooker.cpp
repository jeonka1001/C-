//
//  RiceCooker.cpp
//  testMain
//
//  Created by 전경안 on 2020/02/17.
//  Copyright © 2020 전경안. All rights reserved.
//

#include "RiceCooker.h"
RiceCooker::RiceCooker()
:machineState(NO_OPERATION),Appliance(){}
RiceCooker::RiceCooker(string machineName, int powerConsumption)
:Appliance(machineName,powerConsumption),machineState(NO_OPERATION){}

int RiceCooker::getMachineState() const {
    return this->machineState;
}
void RiceCooker::setMachineState(int machineState) {
    this->machineState = machineState;
    stateView();
}
void RiceCooker::stateView() {
    cout << "제품명 : " << Appliance::getMachineName();
    if (Appliance::getPowerFlag() == true)cout << " (ON) ";
    else {
        cout << " (OFF) "<<endl;
        return ;
    }
    cout << "설정상태 : ";
    switch (machineState) {
        case NO_OPERATION:
            cout << "대기";
            break;
        case WARM:
            cout <<"보온";
            break;
        case COOK:
            cout <<"취사";
            break;
        case HEAT:
            cout <<"데우기";
            break;
        default:
            break;
    }
    cout <<endl;
}

enum { NO_OPERATION = 1, WARM, COOK, HEAT };
