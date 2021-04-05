#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status 
{
    ERROR = 0, 
	SUCCESS = 1
} Status;

typedef int ElemType;

typedef  struct StackNode //结点 
{
	ElemType data;       //数据域 
	struct StackNode *next;//指针域 
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top; 
	int	count;   
	bool test=0;    
}LinkStack;



//链栈
Status initLStack(LinkStack *s)//初始化栈
{
	LinkStackPtr p;  //结点 
	p=(StackNode *)malloc(sizeof(StackNode));
	p->next=NULL;
	s->top=p;
	s->count=-1;
	s->test=1;
	printf("初始化成功"); 
	getch();
} 
Status isEmptyLStack(LinkStack *s)//判断栈是否为空
{
	if(s->count==-1)
	printf("这个链栈为空");
	else
	printf("这个链栈不为空"); 
}

Status getTopLStack(LinkStack *s,ElemType *e)//得到栈顶元素
{
	if(s->count==-1)
	{
	printf("这个栈是空栈");
	getch();
	}
	else
	{ 
	*e=s->top->data;
	printf("%d",*e);
	getch();
	}
}
Status destroyLStack(LinkStack *s)//销毁栈
{
	LinkStackPtr p;
	for(s->count;s->count>=0;s->count--)
	{
		p=s->top;
		s->top=p->next;
		free(p);
	}
	printf("销毁成功"); 
	getch();
}
Status LStackLength(LinkStack *s,int *length)//检测栈长度
{
	*length=s->count;
	printf("%d",*length+1);
	getch();
}
Status pushLStack(LinkStack *s,ElemType data)//入栈
{  
	LinkStackPtr p;
	p=(LinkStackPtr)malloc(sizeof(StackNode));
	p->data=data;
	p->next=s->top;
	s->top=p;
	s->count+=1;
	printf("入栈成功"); 
	getch();
	
}
Status popLStack(LinkStack *s,ElemType *data)//出栈
{
	LinkStackPtr x;
	if(s->count==-1)
	{
		printf("这是一个空栈");
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
		printf("出栈成功");
		getch(); 
	}
}


#endif 
