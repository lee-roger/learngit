#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include<conio.h>
int main()
{
	int flag=1,choice,num; 
	LinkedList L=NULL; //一级指针
	LinkedList p;
	int  e;
	
	
	while(flag)
	{
	system("cls");
	printf("\n\n\n\t\t\t\t\t---------------------------\n");
    printf("\t\t\t\t\t>>> 1.初始化链表，并输入.  \n");
    printf("\t\t\t\t\t>>> 2.输出链表             \n");
    printf("\t\t\t\t\t>>> 3.删除整个链表.          \n");
    printf("\t\t\t\t\t>>> 4.查询数是否存在链表中  \n");
    printf("\t\t\t\t\t>>> 5.查找中间结点              \n");
    printf("\t\t\t\t\t>>> 6.倒置链表              \n");
    printf("\t\t\t\t\t>>> 7.判断是否成环              \n");
    printf("\t\t\t\t\t>>> 8.根据数值删除某一结点             \n");
    printf("\t\t\t\t\t>>> 9.奇偶交换  \n");
    printf("\t\t\t\t\t>>>10.计算结点的个数  \n");
    printf("\t\t\t\t\t>>> 0.退出.               \n");
    printf("\t\t\t\t\t---------------------------\n");
    printf("请输入选项");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			InitList(&L);break;
		
		case 2:
			p=L;
			if(L==NULL)
			{
				printf("链表内无数据");
				getch();
				break;	
			}			
			if(L!=NULL)
			TraverseList(L,visit); 
			break;
		 
		 case 3:
		 	DestroyList(&L);break; 
		 	
		 case 4:
		 	printf("请输入你要查询的数");
			 scanf("%d",&e);
			 SearchList(L, e);
			 break;
		 	
		 case 5:
			LinkedList mid;
		   	if ((mid=FindMidNode(&L))!=NULL)
		   	printf("这个链表的中间结点为%d",mid->data);
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
			printf("请输入要删除的数");
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
