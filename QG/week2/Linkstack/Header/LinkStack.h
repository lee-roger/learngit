#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status 
{
    ERROR = 0, 
	SUCCESS = 1
} Status;

typedef int ElemType;

typedef  struct StackNode //��� 
{
	ElemType data;       //������ 
	struct StackNode *next;//ָ���� 
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top; 
	int	count;   
	bool test=0;    
}LinkStack;



//��ջ
Status initLStack(LinkStack *s)//��ʼ��ջ
{
	LinkStackPtr p;  //��� 
	p=(StackNode *)malloc(sizeof(StackNode));
	p->next=NULL;
	s->top=p;
	s->count=-1;
	s->test=1;
	printf("��ʼ���ɹ�"); 
	getch();
} 
Status isEmptyLStack(LinkStack *s)//�ж�ջ�Ƿ�Ϊ��
{
	if(s->count==-1)
	printf("�����ջΪ��");
	else
	printf("�����ջ��Ϊ��"); 
}

Status getTopLStack(LinkStack *s,ElemType *e)//�õ�ջ��Ԫ��
{
	if(s->count==-1)
	{
	printf("���ջ�ǿ�ջ");
	getch();
	}
	else
	{ 
	*e=s->top->data;
	printf("%d",*e);
	getch();
	}
}
Status destroyLStack(LinkStack *s)//����ջ
{
	LinkStackPtr p;
	for(s->count;s->count>=0;s->count--)
	{
		p=s->top;
		s->top=p->next;
		free(p);
	}
	printf("���ٳɹ�"); 
	getch();
}
Status LStackLength(LinkStack *s,int *length)//���ջ����
{
	*length=s->count;
	printf("%d",*length+1);
	getch();
}
Status pushLStack(LinkStack *s,ElemType data)//��ջ
{  
	LinkStackPtr p;
	p=(LinkStackPtr)malloc(sizeof(StackNode));
	p->data=data;
	p->next=s->top;
	s->top=p;
	s->count+=1;
	printf("��ջ�ɹ�"); 
	getch();
	
}
Status popLStack(LinkStack *s,ElemType *data)//��ջ
{
	LinkStackPtr x;
	if(s->count==-1)
	{
		printf("����һ����ջ");
		getch(); 
	}
	else
	{
		*data=s->top->data;
		x=s->top;
		s->top=x->next;
		s->count-=1;
		free(x);
		printf("%d",*data);
		printf("��ջ�ɹ�");
		getch(); 
	}
}


#endif 
