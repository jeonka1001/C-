//
//  Robot.h
//  RobotPro
//
//  Created by 전경안 on 2020/02/08.
//  Copyright © 2020 전경안. All rights reserved.
//

#ifndef Robot_h
#define Robot_h


#endif /* Robot_h */
#pragma once
class Robot
{
private:
    char *name;
    int energy;
    void errPrn(); // 에너지 부족- 에러메시지 출력
public:
    Robot();  // name은 Null string으로, energy는 0으로 초기화
    Robot(const char *name, int energy = 0);
    Robot(Robot& r);
    void go();              // 전진 메시지 출력 후 에너지 10 감소
    void back();            // 후진 메시지 출력 후 에너지 20 감소
    void turn();             // 턴 메시지 출력 후 에너지 30 감소
    void jump();            // 점프 메시지 출력 후 에너지 40 감소
    void charge(int e);      // e값 만큼 충전
    char *getName();       // name멤버의 값 리턴
    void setName(const char *);   // name멤버의 값을 전달된 문자열로 재 초기화
    int getEnergy();         // energy멤버의 값 리턴
    void setEnergy(int);     // energy멤버의 값을 전달된 숫자로 재 초기화
    ~Robot(){
        delete[] name;
    };
};
