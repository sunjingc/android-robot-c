/*
 * fileGet.cpp
 *
 *  Created on: 2018��4��23��
 *      Author: mm
 */

#include <stdio.h>

int main()
{
FILE * fp;
int a=10;
int b;

fp=fopen("rfcomm","wb+");

fwrite(&a,sizeof(int),1,fp);///��aֵд���ļ���.��������ã��ƶ����ļ�ָ�롣
fseek(fp,0,0);//���ļ�ָ���ƻ��ײ�
fread(&b,sizeof(int),1,fp);

printf("b is %d\n\n",b);

fclose(fp);

return 0;
}
