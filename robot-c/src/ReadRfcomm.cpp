/*
 * ReadRfcomm.cpp
 *
 *  Created on: 2018Äê4ÔÂ25ÈÕ
 *      Author: mm
 */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	ifstream in;//ifstream read a file
	string filename = "/dev/rfcomm0";//data is restored in /dev/rfcomm0
	in.open(filename);//open the file
	if(!in){//if fail to open the file,return
		cerr << "Fail to open the file!" <<endl;
		return 1;
	}

	char ch;//restore the content of the file

	int flag = 0;
	int direction = 0;
	int leftDirection = 0;
	int rightDirection = 0;
	int speed = 0;
	int leftSpeed = 0;
	int rightSpeed = 0;
	int milliseconds = 0;

	while(!in.eof){//there isn't the end of the file
		string str = "";
		int counter = 0;
		in.read(&ch, 1);
		while(ch!='\n'){
			if(ch!=';'){
			str = str + ch;
			}else{
				if(counter == 0){
					flag = stoi(str);
				}
				if(flag == 1){
					switch(counter){
						case 1:
							direction = stoi(str);
							break;
						case 2:
							speed = stoi(str);
							break;
						case 3:
							milliseconds = stoi(str);
							break;
					}
				}else if(flag == 0){
					switch(counter){
						case 1:
							leftDirection = stoi(str);
							break;
						case 2:
							rightDirection = stoi(str);
							break;
						case 3:
							leftSpeed = stoi(str);
							break;
						case 4:
							rightSpeed = stoi(str);
							break;
						case 5:
							milliseconds = stoi(str);
							break;
					}
				}
				str = "";
				counter++;
			}
			in.read(&ch,1);
		}
	}
	in.close();//close the file
	return 1;
}
