/*
 * moveForward.cpp
 *
 *  Created on: 2018年4月3日
 *      Author: mm
 */

#include "GPIOlib.h"

using namespace GPIO;

int main(){
	//初始化
	init();

	//前进
	controlLeft(FORWARD,10);
	controlRight(FORWARD,10);
	delay(1000);

	//后退
	controlLeft(BACKWARD,20);
	controlRight(BACKWARD,20);
	delay(1000);

	//停止
	stopLeft();
	stopRight();

	return 0;
}
