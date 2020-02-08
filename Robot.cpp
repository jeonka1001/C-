//
//  Robot.cpp
//  RobotPro
//
//  Created by 전경안 on 2020/02/08.
//  Copyright © 2020 전경안. All rights reserved.
//
#include <iostream>
#include <string.h>
#include "Robot.h"
#pragma warning (disable:4996)
using namespace std;

void Robot::errPrn() {
    cout << "에너지 부족" << endl;
}
Robot::Robot():energy(0) {
    name = new char[strlen("") + 1];
    strcpy(name, "");
}
Robot::Robot(const char*name, int energy)
:energy(energy){
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}
Robot::Robot(Robot &r):energy(r.energy) {
    this->name = new char[strlen(r.name) + 1];
    strcpy(this->name, r.name);
}
void Robot::go() {
    if (this->energy < 10) {
        this->errPrn();
    }
    else {
        this->energy -= 10;
        cout << this->name << " 전진..";
    }
}
void Robot::back() {
    if (this->energy < 20) {
        this->errPrn();
    }
    else {
        this->energy -= 20;
        cout << this->name << " 후진..";
    }
}
void Robot::turn() {
    if (this->energy < 30) {
        this->errPrn();
    }
    else {
        this->energy -= 30;
        cout << this->name << " 턴..";
    }
}
void Robot::jump() {
    if (this->energy < 40) {
        this->errPrn();
    }
    else {
        this->energy -= 40;
        cout << this->name << " 점프..";
    }
}
void Robot::charge(int e) {
    if (e<0) {
        cout << "충전 에너지 양이 음수 입니다." << endl;
    }
    else {
        this->energy += e;
    }
}
char* Robot::getName() {
    return name;
}
void Robot::setName(const char*name) {
    if (this->name != NULL) {
        delete[] this->name;
    }
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}
int Robot::getEnergy() {
    return this->energy;
}
void Robot::setEnergy(int e) {
    if (e < 0) {
        this->energy = 0;
    }
    else {
        this->energy = e;
    }
}

