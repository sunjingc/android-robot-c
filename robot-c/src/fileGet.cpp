/*
 * fileGet.cpp
 *
 *  Created on: 2018定4埖23晩
 *      Author: mm
 */

#include <stdio.h>
#include <stdlib.h>

void main( int argc, char *argv[] ){
　　char ch;
　　FILE *fp;
　　int i;

　　if((fp=fopen(argv[1],"/dev/rfcomm0"))==NULL)
　　{
　　　　printf("音嬬嬉蝕猟周\n");
　　　　exit(0);
　　}

　　while ((ch=fgetc(fp))!=EOF)
　　putchar(ch);

　　fclose(fp);
}
