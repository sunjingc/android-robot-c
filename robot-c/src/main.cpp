/*
 * main.cpp
 *
 *  Created on: 2018年5月8日
 *      Author: mm
 */

#include <iostream>
#include <fstream>
#include <string>
#include "GPIOlib.h"

using namespace GPIO;
using namespace std;

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

int stop(int milliseconds){
	init();
	stopLeft();
	stopRight();
	delay(milliseconds);

	return 0;
}

int turnLeft(int angle){
	init();

	turnTo(angle);

	return 0;
}

int turnRight(int angle){
	init();

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
	int counter = 0;
	int flag = 0;
	const int speed = 10;
	int angle = 0;
	int length = 0;
	int second = 0;
	int milliseconds = 0;

	while(!in.eof()){
		string str = "";
		in.read(&ch, 1);
		while(ch!=',' && ch!='}' && ch!='{' && ch!='"' && ch!=':' && ch!='\n'){//将每个指令分开
				while(ch>='0'&&ch<='9'){
					str = str + ch;
					in.read(&ch, 1);
				}
				if(counter == 0){
					if(str != ""){
						flag = stoi(str);
					}else{
						flag = 0;
					}
					str = "";
					counter = 1;
				}else if(counter == 1){
					switch(flag){
					case 0:
						if(str != ""){
							length = stoi(str);
						}else{
							length = 0;
						}
						milliseconds = length*100;
						moveBackward(speed,milliseconds);
						break;
					case 1:
						if(str != ""){
							length = stoi(str);
						}else{
							length = 0;
						}
						milliseconds = length*100;
						moveForward(speed,milliseconds);
						break;
					case 2:
						if(str != ""){
							angle = stoi(str);
						}else{
							angle = 0;
						}
						turnRight(angle);
						break;
					case 3:
						if(str != ""){
							angle = stoi(str);
						}else{
							angle = 0;
						}
						turnLeft(angle);
						break;
					case 4:
						if(str != ""){
							second = stoi(str);
						}else{
							second = 0;
						}
						milliseconds = second*1000;
						stop(milliseconds);
						break;
					}
					str = "";
					counter = 0;
				}
			in.read(&ch, 1);
		}
	}
	return 0;
}
