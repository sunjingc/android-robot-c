/*
 * moveForward.cpp
 *
 *  Created on: 2018Äê4ÔÂ9ÈÕ
 *      Author: sj
 */
#include <GPIOlib.h>

using namespace GPIO;

int moveForward(int direction,int speed,int milliseconds){
	//init
	init();

	//move forward
	controlLeft(direction,speed);
	controlRight(direction,speed);
	delay(milliseconds);

	//stop
	stopLeft();
	stopRight();

	return 0;
}

