#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include "stack.h"
int main(void)
{
	int flag=1,choice;//ѭ������
	SqStack s;
	int sizes,length;
	char key; 
	ElemType e; 
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
		printf("\t\t\t\t\t|>>>��ʾ��ǰջ��״̬-----8|\n"); 
		printf("\t\t\t\t\t---------------------------\n");
		printf("��ѡ��");
		scanf("%d",&choice); 
		
		switch(choice)
		{
			case 1:printf("ջ�Ĵ�СΪ��");
					scanf("%d",&sizes); 
					iniStack(&s,sizes);
					break;
			
			case 2:
					if(s.test)
					{
						printf("\n��������ջ��Ԫ�أ�"); 
						scanf("%d",&e);
						pushStack(&s,e);
					}
					else
					{
						printf("���ջû�г�ʼ������������");
						getch(); 
					}
					break;
					
			case 3:
					if(s.test)
						popStack(&s,&e);
	
						else
						{
							printf("���ջû�о�����ʼ����������");
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
