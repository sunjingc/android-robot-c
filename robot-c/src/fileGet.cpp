/*
 * fileGet.cpp
 *
 *  Created on: 2018年4月23日
 *      Author: mm
 */

#include <stdio.h>

int main()
{
FILE * fp;
int a=10;
int b;

fp=fopen("rfcomm","wb+");

fwrite(&a,sizeof(int),1,fp);///将a值写到文件中.这句起作用，移动了文件指针。
fseek(fp,0,0);//将文件指针移回首部
fread(&b,sizeof(int),1,fp);

printf("b is %d\n\n",b);

fclose(fp);

return 0;
}
