#include <stdio.h>
#include <stdlib.h>
#include "dulinkedList.h"
#include<conio.h>
int main()
{
	int flag=1,choice,num; 
	DuLinkedList L=NULL; //һ��ָ��
	DuLinkedList p;
	int  e;
	
	
	while(flag)
	{
	system("cls");
	printf("\n\n\n\t\t\t\t\t---------------------------\n");
    printf("\t\t\t\t\t>>> 1.��ʼ������������.  \n");
    printf("\t\t\t\t\t>>> 2.�������             \n");
    printf("\t\t\t\t\t>>> 3.ɾ����������.          \n");
    printf("\t\t\t\t\t>>> 4.������ֵɾ��ĳһ�����  \n");
    printf("\t\t\t\t\t>>> 0.�˳�.               \n");
    printf("\t\t\t\t\t---------------------------\n");
    printf("������ѡ��");
	scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				InitList_DuL(&L);break;
			
			case 2:	
				p=L;
				if(L==NULL)
				{
					printf("������������");
					getch();
					break;	
				}			
				if(L!=NULL)
				TraverseList_DuL(L,visit); 
				break;
			
			case 3:DestroyList_DuL(&L);break; 
			
			case 4:	
				int e;
				printf("������Ҫɾ������");
				scanf("%d",&e); 
				DeleteList_DuL(L,&e);
			 	break; 
				
			case 0:
				flag=0;
		}
	}
}
