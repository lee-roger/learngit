#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include<conio.h>
int main()
{
	int flag=1,choice,num; 
	LinkedList L=NULL; //һ��ָ��
	LinkedList p;
	int  e;
	
	
	while(flag)
	{
	system("cls");
	printf("\n\n\n\t\t\t\t\t---------------------------\n");
    printf("\t\t\t\t\t>>> 1.��ʼ������������.  \n");
    printf("\t\t\t\t\t>>> 2.�������             \n");
    printf("\t\t\t\t\t>>> 3.ɾ����������.          \n");
    printf("\t\t\t\t\t>>> 4.��ѯ���Ƿ����������  \n");
    printf("\t\t\t\t\t>>> 5.�����м���              \n");
    printf("\t\t\t\t\t>>> 6.��������              \n");
    printf("\t\t\t\t\t>>> 7.�ж��Ƿ�ɻ�              \n");
    printf("\t\t\t\t\t>>> 8.������ֵɾ��ĳһ���             \n");
    printf("\t\t\t\t\t>>> 9.��ż����  \n");
    printf("\t\t\t\t\t>>>10.������ĸ���  \n");
    printf("\t\t\t\t\t>>> 0.�˳�.               \n");
    printf("\t\t\t\t\t---------------------------\n");
    printf("������ѡ��");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			InitList(&L);break;
		
		case 2:
			p=L;
			if(L==NULL)
			{
				printf("������������");
				getch();
				break;	
			}			
			if(L!=NULL)
			TraverseList(L,visit); 
			break;
		 
		 case 3:
		 	DestroyList(&L);break; 
		 	
		 case 4:
		 	printf("��������Ҫ��ѯ����");
			 scanf("%d",&e);
			 SearchList(L, e);
			 break;
		 	
		 case 5:
			LinkedList mid;
		   	if ((mid=FindMidNode(&L))!=NULL)
		   	printf("���������м���Ϊ%d",mid->data);
		   	getch();
		  	break; 
		  	
		 case 6:
		 	ReverseList(&L);
		 	break;
		 	
		case 7:
			IsLoopList(L);
			break;
			
		case 8:
			int e;
			printf("������Ҫɾ������");
			scanf("%d",&e); 
			 DeleteList(L,&e);
			 break; 
			 
		case 9:
			L=ReverseEvenList(&L);
			break;
		case 10:num=length(L);
			printf("%d",num);
			getch(); 
		break; 
			
		 case 0: 
		 flag = 0; 
	 } 
	
		}
	return 0;
}
