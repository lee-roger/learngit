#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include "LinkStack.h"
int main(void)
{
	int flag=1,choice,length=0;//ѭ������
	LinkStack s;	
	ElemType data;
	while(flag)
	{
		system("cls");
		printf("\n\n\n\n\n");
		printf("\t\t\t\t\t---------------------------\n");
		printf("\t\t\t\t\t|>>>�˳�-----------------0|\n");
		printf("\t\t\t\t\t|>>>��ʼ��ջ-------------1|\n");
		printf("\t\t\t\t\t|>>>��ջ-----------------2|\n");
		printf("\t\t\t\t\t|>>>��ջ-----------------3|\n");
		printf("\t\t\t\t\t|>>>���ջ��Ԫ��---------4|\n");
		printf("\t\t\t\t\t|>>>����ջ---------------5|\n");
		printf("\t\t\t\t\t|>>>ջ�Ĵ�С-------------6|\n");
		printf("\t\t\t\t\t|>>>�ж��Ƿ�Ϊ��ջ-------7|\n");
		printf("\t\t\t\t\t---------------------------\n");
		printf("��ѡ��");
		scanf("%d",&choice); 
		switch(choice)
			{
				case 0:flag=0;break;
				
				case 1:initLStack(&s);
						break;
				
				case 2:
					if(!s.test)
					{ 
					printf("���ջû�г�ʼ������������");
					getch(); 
					}
					else
					{
					printf("������Ҫ��ջ������");
					scanf("%d",&data); 
					pushLStack(&s,data);
					}
					break;
				
				case 3:
					if(!s.test)
					{
						printf("���ջû�г�ʼ��");
						getch(); 
					}
					else
					{
						popLStack(&s,&data);
					}
					break;
					
				case 4:	if(!s.test)
						{ 
						printf("���ջû�г�ʼ������������");
						getch(); 
						}
						else
						getTopLStack(&s,&data);
						break;
						
				case 5:if(!s.test)
						{ 
						printf("���ջû�г�ʼ������������");
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
						printf("���ջû�г�ʼ������������");
						getch(); 
						}
						else
						LStackLength(&s,&length);
						break;
				
				case 7:if(!s.test)
						{ 
						printf("���ջû�г�ʼ������������");
						getch(); 
						}
						else
						isEmptyLStack(&s);
						break;
					
			}
	}
} 
