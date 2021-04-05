#ifndef STACK_H_
#define STACK_H_

typedef int ElemType;

typedef struct SqStack
{
       ElemType	*elem;	//����ռ�Ļ�ַ 
       int	top;
	   int  size;     //����ջ��ָ��
	   bool test=0;   //���ڼ��ջ��û�б���ʼ�� 
}SqStack;

typedef enum Status {			//����Status 
	ERROR,
	SUCCESS
} Status;


Status iniStack(SqStack *s,int sizes)//��ʼ��ջ
{
	char key;
	if(s->test)
	{
		printf("���ջ�Ѿ����������ˣ������Ƿ�Ҫ���(Y/N)"); 
		key=getch();
		if(key=='y'||key=='Y')
		{
		free(s->elem);
		s->elem=(ElemType *)malloc(sizes*sizeof(ElemType));//����ռ� 
		s->top=-1;                         
		s->size=sizes;
		printf("\n���³�ʼ���ɹ�"); 
		getch();
		} 
		else
		printf("\n�������³�ʼ���ɹ�");
		getch(); 
	}
	else
	{
	s->elem=(ElemType *)malloc(sizes*sizeof(ElemType));//����ռ� 
	s->top=-1;                         
	s->size=sizes; 	
	s->test=1; 
	printf("��ʼ�ɹ�");
	getch();	
	}
}


Status isEmptyStack(SqStack *s)//�ж��Ƿ�Ϊ��ջ
{
	if(s->top <= -1)
	{ 
	printf("����һ����ջ");
	getch(); 
	} 
	else if(s->test==0)
	{
		printf("���ջû�о�����ʼ��");
		getch(); 
	}
	else
	{ 
	printf("�ⲻ��һ����ջ");
	getch(); 
	} 
} 

Status getTopStack(SqStack *s,ElemType *e)//�õ�ջ��Ԫ��
{
	if(s->top==-1)
	{
		printf("����һ����ջ");
		getch();
	}
	else if(s->test==0)
	{
		printf("���ջû�о�����ʼ��");
		getch(); 
	}
	else
	{
		*e=s->elem[s->top];
		printf("%d",*e);
		getch();
	}
} 

Status destoryStack(SqStack *s)//����ջ
{
		if(!s->test)
	{
		printf("���ջû�н��г�ʼ��");
		getch(); 
	}
	else if(s->top==-1)
	{
		printf("���Ǹ���ջ");
		getch(); 
	}
	else
	{
	free(s->elem);
	s->top=-1;
	s->test=0; 
	printf("�������");
	getch();
}
}


Status stackLength(SqStack *s,int length)//���ջ�Ĵ�С
{
	if(!s->test)
	{
		printf("���ջû�н��г�ʼ��");
		getch(); 
	}
	else if(s->top==-1)
	{
		printf("���Ǹ���ջ");
		getch(); 
	}
	else
	{
	length=s->top+1;
	printf("���ջ�Ĵ�СΪ%d",length);
	getch();
	}	
}


Status pushStack(SqStack *s,ElemType datas)//��ջ
{
		if(s->top == (s->size-1)) //�ж��Ƿ�����
		{
			printf("�ռ����ˣ��������룬�����%d��ջʧ��",datas);
			getch(); 
		} 

		else
		{
			s->top++; 
			printf("��%d��Ԫ����ջ�ɹ�",s->top+1);
			s->elem[s->top]=datas;
			printf("��ջ�ɹ�"); 
			getch();
		}	
} 
Status popStack(SqStack *s,ElemType *datas)//��ջ
{
	if(s->top==-1)
	{
		printf("����һ����ջ");
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
		printf("\t\t\t\t\t\t�� ǰ ջ Ϊ\n\n");
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
		printf("����һ����ջ");
		getch(); 
	}
	else
	{
		printf("���ջû�г�ʼ��");
		getch(); 
	}
	getch();
}

#endif  
