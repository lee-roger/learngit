#ifndef CALCULATOR_H_
#define CALCULATOR_H_
#define MAXSIZE 100      //栈的最大容量 
#include<conio.h>
#include<string.h>
#include<math.h>

typedef int Elemtype;

typedef struct Charstack  //字符栈 
{
	char data[MAXSIZE];
	int top;
}charstack;

typedef struct Datastack //数据栈
{
	Elemtype data[MAXSIZE];
	int top;	
}datastack;



//--------------------------------------------字符栈的基本操作--------------------------------------------- 

void inic(charstack *s)  //字符栈初始化 
{
	s->top=-1;
 } 


int Pushc(charstack *s, char e)  //字符栈压栈 
{
	if(s->top<MAXSIZE)
	{
		s->data[++s->top]=e;
		return 1;
	}
	else
	{
		printf("运算出错");
		getch(); 
		return 0;
	}
}

char Gettopc(charstack *s)     //取字符栈顶元素
{
	if(s->top>=0)
	return s->data[s->top];
	
} 

char Poptopc(charstack *s)    //字符栈出栈 
{
	if(s->top>=0)
	return s->data[s->top--]; 
} 

//---------------------------------------------------------数据栈的基本操作--------------------------------------------

void inid(datastack *s)  //数据栈初始化
{
	s->top=-1; 
}

int Pushd(datastack *s,Elemtype data)   //数据栈压栈   
{
	if(s->top<MAXSIZE)
	{
		s->data[++s->top]=data;
		return 1; 
	} 
	else
	return 0;
}
 
Elemtype Poptopd(datastack *s)			//数据栈出栈 
{
	if(s->top>=0)
	return s->data[s->top--];
}
 
//-------------------------------------------------------运算----------------------------------------------------------

int judge(char c)   //判定优先级 
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
 
void Tran(char *c1,char *c2)     //将c1转化为后缀表达式c2 
{
	int i=0,j=0;
	charstack c;     //搞个字符栈

	int key=0,key2=1;       //判断前一个数是数字还是符号 
	char top,pop;
	inic(&c);
//-----------------------------------------------------处理负数的情况--------------------------------------------- 
	while(c1[i]!='\0')
	{
		if(c1[0]=='-')
		{
			j=strlen(c1);
			for(j;j>0;j--)
			c1[j+5]=c1[j];    //增加五个位置，处理负号 
			c1[0]='(';
			c1[1]='0';
			c1[2]='-';
			c1[3]='1';
			c1[4]=')'; 
			c1[5]='*';
		}
		if(c1[i]=='('&&c1[i+1]=='-')    //处理运算中的负数 
		{
			j=strlen(c1);
			for(j;j>i+1;j--)    //将i位置后空出五个位置 
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
//--------------------------------------------------------转化为后缀运算------------------------------------------------------------------
	i=0;
	j=0;
	while(c1[i]!='\0')
	{
		if(c1[i]=='('||c1[i]=='+'||c1[i]=='-'||c1[i]=='/'||c1[i]=='*' )  //判断是否为运算符
		{
			if(key)
			{	
				c2[j++]=' ';
			} 
			
			while(1)
			{
			top=Gettopc(&c);  //获得栈顶的运算符 
			if((judge(top)>=judge(c1[i]))&&(c1[i]!='('))        //比较栈顶的优先级 
		   	{
		   		c2[j++]=Poptopc(&c);
			}
			else
			{
		 
				Pushc(&c, c1[i]);
				break;
			}
			}
			key=0;    //说明这一次的字符为运算符  
		} 
		else if(c1[i]>='0'&&c1[i]<='9')                //判断为数字
		{
			c2[j++]=c1[i];
			key=1;                       //说明这一次为数字 
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

