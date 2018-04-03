/*
 * moveBackward.cpp
 *
 *  Created on: 2018��4��3��
 *      Author: mm
 */
#include <GPIOlib.h>

using namespace GPIO;

int main(){
	//init
	init();

	//move backward
	controlLeft(BACKWARD,20);
	controlRight(BACKWARD,20);
	delay(1000);

	//stop
	stopLeft();
	stopRight();

	return 0;
}

