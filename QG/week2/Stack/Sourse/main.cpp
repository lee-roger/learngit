#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include "stack.h"
int main(void)
{
	int flag=1,choice;//循环开关
	SqStack s;
	int sizes,length;
	char key; 
	ElemType e; 
	while(flag)
	{
		system("cls");
		printf("\n\n\n\n\n");
		printf("\t\t\t\t\t---------------------------\n");
		printf("\t\t\t\t\t|>>>退出-----------------0|\n");
		printf("\t\t\t\t\t|>>>初始化栈-------------1|\n");
		printf("\t\t\t\t\t|>>>入栈-----------------2|\n");
		printf("\t\t\t\t\t|>>>出栈-----------------3|\n");
		printf("\t\t\t\t\t|>>>获得栈顶元素---------4|\n");
		printf("\t\t\t\t\t|>>>销毁栈---------------5|\n");
		printf("\t\t\t\t\t|>>>栈的大小-------------6|\n");
		printf("\t\t\t\t\t|>>>判断是否为空栈-------7|\n");
		printf("\t\t\t\t\t|>>>显示当前栈的状态-----8|\n"); 
		printf("\t\t\t\t\t---------------------------\n");
		printf("请选择");
		scanf("%d",&choice); 
		
		switch(choice)
		{
			case 1:printf("栈的大小为：");
					scanf("%d",&sizes); 
					iniStack(&s,sizes);
					break;
			
			case 2:
					if(s.test)
					{
						printf("\n请输入入栈的元素："); 
						scanf("%d",&e);
						pushStack(&s,e);
					}
					else
					{
						printf("这个栈没有初始化，操作错误");
						getch(); 
					}
					break;
					
			case 3:
					if(s.test)
						popStack(&s,&e);
	
						else
						{
							printf("这个栈没有经过初始，操作错误");
							getch(); 
						}
					break;
				
			case 4:
				getTopStack(&s,&e);
					break;
					
			case 5:destoryStack(&s);
					break;
				
			case 6:stackLength(&s,length);
					break;
					
			case 7:isEmptyStack(&s);
					break;	
					
			case 8:ShowStack(&s);
				   break;
			
			case 0:flag=0;
		 } 
	 } 
 } 
