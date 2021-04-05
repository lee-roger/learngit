#ifndef CALCULATOR_H_
#define CALCULATOR_H_
#define MAXSIZE 100      //ջ��������� 
#include<conio.h>
#include<string.h>
#include<math.h>

typedef int Elemtype;

typedef struct Charstack  //�ַ�ջ 
{
	char data[MAXSIZE];
	int top;
}charstack;

typedef struct Datastack //����ջ
{
	Elemtype data[MAXSIZE];
	int top;	
}datastack;



//--------------------------------------------�ַ�ջ�Ļ�������--------------------------------------------- 

void inic(charstack *s)  //�ַ�ջ��ʼ�� 
{
	s->top=-1;
 } 


int Pushc(charstack *s, char e)  //�ַ�ջѹջ 
{
	if(s->top<MAXSIZE)
	{
		s->data[++s->top]=e;
		return 1;
	}
	else
	{
		printf("�������");
		getch(); 
		return 0;
	}
}

char Gettopc(charstack *s)     //ȡ�ַ�ջ��Ԫ��
{
	if(s->top>=0)
	return s->data[s->top];
	
} 

char Poptopc(charstack *s)    //�ַ�ջ��ջ 
{
	if(s->top>=0)
	return s->data[s->top--]; 
} 

//---------------------------------------------------------����ջ�Ļ�������--------------------------------------------

void inid(datastack *s)  //����ջ��ʼ��
{
	s->top=-1; 
}

int Pushd(datastack *s,Elemtype data)   //����ջѹջ   
{
	if(s->top<MAXSIZE)
	{
		s->data[++s->top]=data;
		return 1; 
	} 
	else
	return 0;
}
 
Elemtype Poptopd(datastack *s)			//����ջ��ջ 
{
	if(s->top>=0)
	return s->data[s->top--];
}
 
//-------------------------------------------------------����----------------------------------------------------------

int judge(char c)   //�ж����ȼ� 
{
	switch(c)
	{
		case '+':return 1;break;
		case '-':return 1;break;	
		case '*':return 2;break;
		case '/':return 2;break;
		case '(':return 0;break;
	} 	
} 
 
void Tran(char *c1,char *c2)     //��c1ת��Ϊ��׺���ʽc2 
{
	int i=0,j=0;
	charstack c;     //����ַ�ջ

	int key=0,key2=1;       //�ж�ǰһ���������ֻ��Ƿ��� 
	char top,pop;
	inic(&c);
//-----------------------------------------------------�����������--------------------------------------------- 
	while(c1[i]!='\0')
	{
		if(c1[0]=='-')
		{
			j=strlen(c1);
			for(j;j>0;j--)
			c1[j+5]=c1[j];    //�������λ�ã������� 
			c1[0]='(';
			c1[1]='0';
			c1[2]='-';
			c1[3]='1';
			c1[4]=')'; 
			c1[5]='*';
		}
		if(c1[i]=='('&&c1[i+1]=='-')    //���������еĸ��� 
		{
			j=strlen(c1);
			for(j;j>i+1;j--)    //��iλ�ú�ճ����λ�� 
			c1[j+5]=c1[j];
			
			c1[j++]='(';
			c1[j++]='0';
			c1[j++]='-';
			c1[j++]='1';
			c1[j++]=')';
			c1[j]='*';	 
		}
		i++;
	 } 
//--------------------------------------------------------ת��Ϊ��׺����------------------------------------------------------------------
	i=0;
	j=0;
	while(c1[i]!='\0')
	{
		if(c1[i]=='('||c1[i]=='+'||c1[i]=='-'||c1[i]=='/'||c1[i]=='*' )  //�ж��Ƿ�Ϊ�����
		{
			if(key)
			{	
				c2[j++]=' ';
			} 
			
			while(1)
			{
			top=Gettopc(&c);  //���ջ��������� 
			if((judge(top)>=judge(c1[i]))&&(c1[i]!='('))        //�Ƚ�ջ�������ȼ� 
		   	{
		   		c2[j++]=Poptopc(&c);
			}
			else
			{
		 
				Pushc(&c, c1[i]);
				break;
			}
			}
			key=0;    //˵����һ�ε��ַ�Ϊ�����  
		} 
		else if(c1[i]>='0'&&c1[i]<='9')                //�ж�Ϊ����
		{
			c2[j++]=c1[i];
			key=1;                       //˵����һ��Ϊ���� 
		} 
		else if(c1[i]==')')
		{
			while(key2)
			{
				pop=Poptopc(&c); 
				if(pop=='(')
				key2=0;
				else
				c2[j++]=pop;
			}
		}
		                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
		i++; 
	}
	while(c.top>=0)
	c2[j++]=Poptopc(&c);
	c2[j]='\0';
 
} 

#endif  

