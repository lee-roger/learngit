#include<stdio.h>
#include "calculator.h"
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define MAXSIZE 100
int main()
{
	char s1[MAXSIZE];			//用于存储前缀表达式 
	char s2[MAXSIZE];			//用于存储转换后的表达式 
	printf("请输入表达式:");
	scanf("%s",s1);
	
	Tran(s1,s2);				//处理字符串，并转化为后缀表达式,存放在s2中 
	  
//	printf("%d",Transform(s1));
//	printf("计算结果为: %d\n",JUSTDOIT(s2));		//后缀表达式求值 
	printf("%s",s2);
		
	return 0;
}
