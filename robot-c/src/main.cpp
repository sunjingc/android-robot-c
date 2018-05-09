/*
 * main.cpp
 *
 *  Created on: 2018Äê5ÔÂ8ÈÕ
 *      Author: mm
 */

#include <iostream>
#include <fstream>
#include <string>
#include "GPIOlib.h"

using namespace std;
using namespace GPIO;

int moveForward(int speed,int milliseconds){
	init();

	controlLeft(1,speed);
	controlRight(1,speed);
	delay(milliseconds);

	stopLeft();
	stopRight();

	return 0;
}

int moveBackward(int speed,int milliseconds){
	init();

	controlLeft(0,speed);
	controlRight(0,speed);
	delay(milliseconds);

	stopLeft();
	stopRight();

	return 0;
}

int stop(){
	stopLeft();
	stopRight();

	return 0;
}

int turnLeft(int angle){

	turnTo(angle);

	return 0;
}

int turnRight(int angle){

	turnTo(angle);

	return 0;
}

int main(){
	ifstream in;
	string filename = "/dev/rfcomm0";
	in.open(filename);

	if(!in){
		cerr << "Fail to open the file!" << endl;
		return 1;
	}

	char ch;
	int flag = 0;
	const int speed = 50;
	int angle = 0;
	int length = 0;
	int milliseconds = 0;

	while(!in.eof()){
		string str = "";
		in.read(&ch, 1);
	}
	return 0;
}
