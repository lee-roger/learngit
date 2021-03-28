#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include<conio.h> 


/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
	(*L)= (LinkedList)malloc(sizeof(LNode));
	LinkedList p1, p2;
	int n=0;    //开关 
	p1 = p2 = (LinkedList)malloc(sizeof(LNode));
	scanf("%d",&p1->data);
	*L=NULL;
	while (p1->data!=0)
	{
		n =n+1;
		if (n == 1)
		(*L)= p1;
		else 
		p2->next = p1;
		p2 = p1;
		p1 = (LinkedList)malloc(sizeof(LNode));
		scanf("%d",&p1->data);
	}
		p2->next = NULL;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
	LinkedList p;
	if((*L)==NULL)
	{
	printf("该链表是空的,无需删除");
	getch();
	}
	else
	{
		p = (*L);
		while(p!=NULL)
		{
			p=p->next;
			free(*L);
			(*L)=p;
		}
		printf("已删除整个链表");
		getch();
	} 
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
	//在p后插入q 
	if(q==NULL||p==NULL)
	printf("参数错误");
	else
	{
		q->next = p->next;
		p->next = q;
	 } 

}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
	//删除某一个结点 
	if(p==NULL)
	{
		printf("参数错误，无这个结点"); 
	 } 
	else
	{
		LinkedList q,temp;
		int i,num;
		q=p;
		num =length(p);
		i=0;
		while(q->data!=*e)
		{
			temp=q;    //标记这个结点 
			q=q->next; //移动到下一个
			i++; 
		}
		if(i!=num)
		{
		temp->next=q->next;//将q这个结点的数据删除了
		printf("删除成功");
		getch();
		}
		else
		printf("没有这个结点"); 
		free(q);//释放空间
		
		getch();
	}

}
int length(LinkedList L)  //这是统计几个结点的，为了上面的delete不出bug 
{
    int num=0;
    while(L!= NULL)
    {
        num++;
        L = L->next;
    }
    return num;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
	 LinkedList p ;
	p=L;
    while(p)
    {
        visit(p->data);
        p = p->next;
    }
    getch();
    printf("\n");
}

void visit(ElemType e)
{
    printf("%d->",e);
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
	LinkedList p; 
	if(L == NULL)
	{ 
	printf("这是个空链表");
	getch(); 
	} 
	else
	{
		p=L->next;
		while(p!=NULL &&p->data!=e)
		p=p->next;
		if(p==NULL)
		{ 
		printf("这个数不在链表中");
		getch(); 
		} 
		else
		{
		printf("这个数存在链表中"); 
		getch();
		}
	 } 
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
	if((*L)==NULL)
	{
	printf("这是个空链表");
	getch();
	}
	else
	{
		LinkedList p, q;
		int temp;  // temp是一个下下策的解决方法，无论怎样，表头的数值总是倒置不了 ，师兄见谅 
		p=(*L)->next;
		(*L)->next = NULL; //断开并防止变为野指针 
		while(p!=NULL)
		{
			q=p->next;
			InsertList((*L), p);//不断在头结点后面插入 
			temp=(*L)->data;
			(*L)->data=p->data;
			p->data=temp; 
			p=q;
		 } 
		 
		 printf("倒置完成"); 
		 getch(); 
	} 

}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
	//是否成环，快指针追慢指针 
	LinkedList fast=NULL,slow=NULL; 
	if(L==NULL)
	{
		printf("这是一个空链表");
		getch(); 
	 } 
	else
	{
		slow=L;
		fast=L->next;
		while(1)
		{
			if((fast->next==NULL)||(fast==NULL))
			{
				printf("这个链表不成环");
				getch();
				break; 
			} 
			else if((fast==slow)||(fast->next==slow)) //若成环，总有相遇 
			{
				printf("这个链表成环");
				getch();
				break;
			}
			else
			{
				fast =fast->next->next;
				slow = slow->next;
			}
		}
	}
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {
	//前后指针每次走两步
	LinkedList p;
	if((*L)==NULL)
	{
		printf("这是一个空链表"); 
		getch(); 
	}
	else
	{
		LinkedList front=NULL,behind=NULL;//前后指针
		ElemType temp;
		front=(*L)->next;
		behind=(*L);
		p=(*L);
		while(behind->next!=NULL)
		{
			temp =front->data;
			front->data=behind->data;
			behind->data=temp; //交换 
			
			
			front=front->next->next;//走两步
			behind=behind->next->next; 
		 } 
		 	printf("修改完成");
			getch(); 
	 } 
	return p;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
	LinkedList fast,slow=NULL;  //快慢指针 
	if((*L)==NULL)
	{
		printf("这是一个空链表");
		getch();
		return slow; 
	}
	else
	{
		fast = slow = (*L);
		while(fast!=NULL)
		{
			if(fast->next == NULL)
			{
			fast = fast->next;
			break; 
			} 
			else
			fast = fast->next->next;  //快指针走两步
			slow = slow->next; 	
		}
	return slow;
	}
}




