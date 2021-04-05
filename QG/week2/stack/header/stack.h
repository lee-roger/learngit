#ifndef STACK_H_
#define STACK_H_

typedef int ElemType;

typedef struct SqStack
{
       ElemType	*elem;	//储存空间的基址 
       int	top;
	   int  size;     //用于栈顶指针
	   bool test=0;   //用于检测栈有没有被初始化 
}SqStack;

typedef enum Status {			//定义Status 
	ERROR,
	SUCCESS
} Status;


Status iniStack(SqStack *s,int sizes)//初始化栈
{
	char key;
	if(s->test)
	{
		printf("这个栈已经存在数据了，请问是否要替代(Y/N)"); 
		key=getch();
		if(key=='y'||key=='Y')
		{
		free(s->elem);
		s->elem=(ElemType *)malloc(sizes*sizeof(ElemType));//分配空间 
		s->top=-1;                         
		s->size=sizes;
		printf("\n重新初始化成功"); 
		getch();
		} 
		else
		printf("\n放弃重新初始化成功");
		getch(); 
	}
	else
	{
	s->elem=(ElemType *)malloc(sizes*sizeof(ElemType));//分配空间 
	s->top=-1;                         
	s->size=sizes; 	
	s->test=1; 
	printf("初始成功");
	getch();	
	}
}


Status isEmptyStack(SqStack *s)//判断是否为空栈
{
	if(s->top <= -1)
	{ 
	printf("这是一个空栈");
	getch(); 
	} 
	else if(s->test==0)
	{
		printf("这个栈没有经过初始化");
		getch(); 
	}
	else
	{ 
	printf("这不是一个空栈");
	getch(); 
	} 
} 

Status getTopStack(SqStack *s,ElemType *e)//得到栈顶元素
{
	if(s->top==-1)
	{
		printf("这是一个空栈");
		getch();
	}
	else if(s->test==0)
	{
		printf("这个栈没有经过初始化");
		getch(); 
	}
	else
	{
		*e=s->elem[s->top];
		printf("%d",*e);
		getch();
	}
} 

Status destoryStack(SqStack *s)//销毁栈
{
		if(!s->test)
	{
		printf("这个栈没有进行初始化");
		getch(); 
	}
	else if(s->top==-1)
	{
		printf("这是个空栈");
		getch(); 
	}
	else
	{
	free(s->elem);
	s->top=-1;
	s->test=0; 
	printf("销毁完毕");
	getch();
}
}


Status stackLength(SqStack *s,int length)//检测栈的大小
{
	if(!s->test)
	{
		printf("这个栈没有进行初始化");
		getch(); 
	}
	else if(s->top==-1)
	{
		printf("这是个空栈");
		getch(); 
	}
	else
	{
	length=s->top+1;
	printf("这个栈的大小为%d",length);
	getch();
	}	
}


Status pushStack(SqStack *s,ElemType datas)//入栈
{
		if(s->top == (s->size-1)) //判断是否会溢出
		{
			printf("空间满了，不能输入，这个数%d入栈失败",datas);
			getch(); 
		} 

		else
		{
			s->top++; 
			printf("第%d个元素入栈成功",s->top+1);
			s->elem[s->top]=datas;
			printf("进栈成功"); 
			getch();
		}	
} 
Status popStack(SqStack *s,ElemType *datas)//出栈
{
	if(s->top==-1)
	{
		printf("这是一个空栈");
		getch(); 
	}

	else
	{
		*datas=s->elem[s->top--];
		printf("%d",*datas);
		getch();
	}
} 

Status ShowStack(SqStack *s)
{	
	int i;
	if(s->test&&s->top>=0)
	{
		system("cls");
		printf("\n\n\n\n\n\n");
		printf("\t\t\t\t\t\t当 前 栈 为\n\n");
	for(i=s->size-s->top-1;i>0;i--)
	{
		printf("\t\t\t\t\t\t|          |\n");
		printf("\t\t\t\t\t\t------------\n");
	}
	for(i=s->top;i>=0;i--)
	{
		printf("\t\t\t\t\t\t|    %d     |\n",s->elem[i]);
		printf("\t\t\t\t\t\t------------\n");
	}
	}
	else if(s->top<0)
	{
		printf("这是一个空栈");
		getch(); 
	}
	else
	{
		printf("这个栈没有初始化");
		getch(); 
	}
	getch();
}

#endif  
