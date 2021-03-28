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
	int n=0;    //���� 
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
	printf("�������ǿյ�,����ɾ��");
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
		printf("��ɾ����������");
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
	//��p�����q 
	if(q==NULL||p==NULL)
	printf("��������");
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
	//ɾ��ĳһ����� 
	if(p==NULL)
	{
		printf("����������������"); 
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
			temp=q;    //��������� 
			q=q->next; //�ƶ�����һ��
			i++; 
		}
		if(i!=num)
		{
		temp->next=q->next;//��q�����������ɾ����
		printf("ɾ���ɹ�");
		getch();
		}
		else
		printf("û��������"); 
		free(q);//�ͷſռ�
		
		getch();
	}

}
int length(LinkedList L)  //����ͳ�Ƽ������ģ�Ϊ�������delete����bug 
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
	printf("���Ǹ�������");
	getch(); 
	} 
	else
	{
		p=L->next;
		while(p!=NULL &&p->data!=e)
		p=p->next;
		if(p==NULL)
		{ 
		printf("���������������");
		getch(); 
		} 
		else
		{
		printf("���������������"); 
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
	printf("���Ǹ�������");
	getch();
	}
	else
	{
		LinkedList p, q;
		int temp;  // temp��һ�����²ߵĽ��������������������ͷ����ֵ���ǵ��ò��� ��ʦ�ּ��� 
		p=(*L)->next;
		(*L)->next = NULL; //�Ͽ�����ֹ��ΪҰָ�� 
		while(p!=NULL)
		{
			q=p->next;
			InsertList((*L), p);//������ͷ��������� 
			temp=(*L)->data;
			(*L)->data=p->data;
			p->data=temp; 
			p=q;
		 } 
		 
		 printf("�������"); 
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
	//�Ƿ�ɻ�����ָ��׷��ָ�� 
	LinkedList fast=NULL,slow=NULL; 
	if(L==NULL)
	{
		printf("����һ��������");
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
				printf("��������ɻ�");
				getch();
				break; 
			} 
			else if((fast==slow)||(fast->next==slow)) //���ɻ����������� 
			{
				printf("�������ɻ�");
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
	//ǰ��ָ��ÿ��������
	LinkedList p;
	if((*L)==NULL)
	{
		printf("����һ��������"); 
		getch(); 
	}
	else
	{
		LinkedList front=NULL,behind=NULL;//ǰ��ָ��
		ElemType temp;
		front=(*L)->next;
		behind=(*L);
		p=(*L);
		while(behind->next!=NULL)
		{
			temp =front->data;
			front->data=behind->data;
			behind->data=temp; //���� 
			
			
			front=front->next->next;//������
			behind=behind->next->next; 
		 } 
		 	printf("�޸����");
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
	LinkedList fast,slow=NULL;  //����ָ�� 
	if((*L)==NULL)
	{
		printf("����һ��������");
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
			fast = fast->next->next;  //��ָ��������
			slow = slow->next; 	
		}
	return slow;
	}
}




