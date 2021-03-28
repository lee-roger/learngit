#include <stdio.h>
#include <stdlib.h>
#include "dulinkedList.h"
#include<conio.h>
int main()
{
	int flag=1,choice,num; 
	DuLinkedList L=NULL; //一级指针
	DuLinkedList p;
	int  e;
	
	
	while(flag)
	{
	system("cls");
	printf("\n\n\n\t\t\t\t\t---------------------------\n");
    printf("\t\t\t\t\t>>> 1.初始化链表，并输入.  \n");
    printf("\t\t\t\t\t>>> 2.输出链表             \n");
    printf("\t\t\t\t\t>>> 3.删除整个链表.          \n");
    printf("\t\t\t\t\t>>> 4.根据数值删除某一个结点  \n");
    printf("\t\t\t\t\t>>> 0.退出.               \n");
    printf("\t\t\t\t\t---------------------------\n");
    printf("请输入选项");
	scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				InitList_DuL(&L);break;
			
			case 2:	
				p=L;
				if(L==NULL)
				{
					printf("链表内无数据");
					getch();
					break;	
				}			
				if(L!=NULL)
				TraverseList_DuL(L,visit); 
				break;
			
			case 3:DestroyList_DuL(&L);break; 
			
			case 4:	
				int e;
				printf("请输入要删除的数");
				scanf("%d",&e); 
				DeleteList_DuL(L,&e);
			 	break; 
				
			case 0:
				flag=0;
		}
	}
}
