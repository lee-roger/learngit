#include<stdio.h>
#include "calculator.h"
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define MAXSIZE 100
int main()
{
	char s1[MAXSIZE];			//���ڴ洢ǰ׺���ʽ 
	char s2[MAXSIZE];			//���ڴ洢ת����ı��ʽ 
	printf("��������ʽ:");
	scanf("%s",s1);
	
	Tran(s1,s2);				//�����ַ�������ת��Ϊ��׺���ʽ,�����s2�� 
	  
//	printf("%d",Transform(s1));
//	printf("������Ϊ: %d\n",JUSTDOIT(s2));		//��׺���ʽ��ֵ 
	printf("%s",s2);
		
	return 0;
}
