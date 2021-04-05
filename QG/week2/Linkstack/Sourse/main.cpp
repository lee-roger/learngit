#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include "LinkStack.h"
int main(void)
{
	int flag=1,choice,length=0;//循环开关
	LinkStack s;	
	ElemType data;
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
		printf("\t\t\t\t\t---------------------------\n");
		printf("请选择");
		scanf("%d",&choice); 
		switch(choice)
			{
				case 0:flag=0;break;
				
				case 1:initLStack(&s);
						break;
				
				case 2:
					if(!s.test)
					{ 
					printf("这个栈没有初始化，操作错误");
					getch(); 
					}
					else
					{
					printf("请输入要入栈的数字");
					scanf("%d",&data); 
					pushLStack(&s,data);
					}
					break;
				
				case 3:
					if(!s.test)
					{
						printf("这个栈没有初始化");
						getch(); 
					}
					else
					{
						popLStack(&s,&data);
					}
					break;
					
				case 4:	if(!s.test)
						{ 
						printf("这个栈没有初始化，操作错误");
						getch(); 
						}
						else
						getTopLStack(&s,&data);
						break;
						
				case 5:if(!s.test)
						{ 
						printf("这个栈没有初始化，操作错误");
						getch(); 
						}
						else
						{
							destroyLStack(&s);
						}
						break;
				case 6:
						if(!s.test)
						{ 
						printf("这个栈没有初始化，操作错误");
						getch(); 
						}
						else
						LStackLength(&s,&length);
						break;
				
				case 7:if(!s.test)
						{ 
						printf("这个栈没有初始化，操作错误");
						getch(); 
						}
						else
						isEmptyLStack(&s);
						break;
					
			}
	}
} 
