#include "duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
	(*L)= (DuLinkedList)malloc(sizeof(DuLNode));
	DuLinkedList p1, p2;  //���� 
	int n=0;
	(*L)->next = (*L)->prior=NULL;
	p1 = p2 = (DuLinkedList)malloc(sizeof(DuLNode));
	scanf("%d",&p1->data);
	*L=NULL;
	while (p1->data!=0)
	{
		n =n+1;
		if (n == 1)
		(*L)= p1;
		else 
		{
		p2->next = p1;   
		p1->prior = p2;
		}
		p2 = p1;
		p1 = (DuLinkedList)malloc(sizeof(DuLNode));
		scanf("%d",&p1->data);
	}
		p2->next = NULL;

}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
	DuLinkedList p;
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
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
	//��pǰ����q 
	if(q==NULL||p==NULL)
	printf("��������");
	else
	{
		q->prior = p->prior;
		p->prior = q;
	 } 
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
	if(q==NULL||p==NULL)
	printf("��������");
	else
	{
		q->next = p->next;
		p->next = q;
	 } 
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
	if(p==NULL)
	{
		printf("����������������"); 
	 } 
	else
	{
		DuLinkedList q,temp;
		int i;
		q=p;
		while(q->data!=*e)
		{
			temp=q;    //��������� 
			q=q->next; //�ƶ�����һ�� 
		}
		temp->next=q->next;//��q�����������ɾ����
		q->next->prior=temp;//����ָ��ǰ�� 
		printf("ɾ���ɹ�");
		getch();
		free(q);//�ͷſռ�
		
		getch();
	}
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	DuLinkedList p ;
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
