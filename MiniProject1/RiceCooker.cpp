//
//  RiceCooker.cpp
//  MiniProject
//
//  Created by 전경안 on 2020/02/15.
//  Copyright © 2020 전경안. All rights reserved.
//

#include "RiceCooker.h"

RiceCooker::RiceCooker():Appliance(),machineState(1)
{}
RiceCooker::RiceCooker(string machineName):Appliance(machineName),machineState(1)
{
}
int RiceCooker::getMachineState() const {
    return machineState;
}
void RiceCooker::setMachineState(int machineState) {
    this->machineState = machineState;
}

void RiceCooker::stateView() {
    Appliance::stateView();
    switch(machineState){
        case 1:
            cout << "대기"<<endl;
            break;
        case 2:
            cout << "보온"<<endl;
            break;
        case 3:
            cout << "밥짓기"<<endl;
            break;
        case 4:
            cout << "데우기"<<endl;
            break;
    }
}
