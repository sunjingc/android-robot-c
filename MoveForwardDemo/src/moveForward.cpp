/*
 * moveForward.cpp
 *
 *  Created on: 2018��4��3��
 *      Author: mm
 */

#include "GPIOlib.h"

using namespace GPIO;

int main(){
	//��ʼ��
	init();

	//ǰ��
	controlLeft(FORWARD,10);
	controlRight(FORWARD,10);
	delay(1000);

	//����
	controlLeft(BACKWARD,20);
	controlRight(BACKWARD,20);
	delay(1000);

	//ֹͣ
	stopLeft();
	stopRight();

	return 0;
}
