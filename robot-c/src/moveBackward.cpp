/*
 * moveBackward.cpp
 *
 *  Created on: 2018Äê4ÔÂ9ÈÕ
 *      Author: sj
 */
#include "GPIOlib.h"

using namespace GPIO;

int moveBackward(int direction,int speed,int milliseconds){
	//init
	init();

	//move backward
	controlLeft(direction,speed);
	controlRight(direction,speed);
	delay(milliseconds);

	//stop
	stopLeft();
	stopRight();

	return 0;
}
int main(){
	moveBackward(0,20,1000);
	return 0;
}

