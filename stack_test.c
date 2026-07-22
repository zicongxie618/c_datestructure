#include <stdio.h>

typedef char ElementType;
#include "stack.h"

//判断左右括号是否匹配
int Match(char left,char right){
	if(left=='('&&right==')'){
		return (TRUE);
	}
	if(left=='['&&right==']'){
		return (TRUE);
	}
	if(left=='{'&&right=='}'){
		return (TRUE);
	}
	return (FALSE);
}

//括号匹配算法
void BracketMatch(char *str){
	SeqStack S;
	int i;
	char ch;

	InitStack(&S);

	for(i=0;str[i]!='\0';i++){
		switch(str[i]){
			case'(':
			case'[':
			case'{':
				Push(&S,str[i]);
				break;
			case')':
			case']':
			case'}':
				if(StackEmpty(S)){
					printf("\n右括号多余！");
					return;
				}
				else{
					GetTop(&S,&ch);
					if(Match(ch,str[i])){
						Pop(&S,&ch);
					}
					else{
						printf("\n对应的左右括号不同类！");
						return;
					}
				}
				break;
		}
	}

	if(StackEmpty(S)){
		printf("\n括号匹配！");
	}
	else{
		printf("\n左括号多余！");
	}
}

//运算符优先级
int Priority(char op){
	if(op=='*'||op=='/'){
		return 2;
	}
	if(op=='+'||op=='-'){
		return 1;
	}
	else{
		return 0;
	}
}

//判断是否为运算符
int IsOperator(char ch){
	return ch=='+'||ch=='-'||ch=='*'||ch=='/';
}

//中缀表达式转化为后缀表达式
void InfixToPostfix(char *str){
	SeqStack S;
	int i;
	int flag;
	char ch,top;

	InitStack(&S);

	for(i=0;str[i]!='\0';i++){
		ch=str[i];

		if(ch==' '){
			continue;
		}

		if((ch>='0'&&ch<='9')||(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')){
			printf("%c",ch);
		}
		else if(ch=='('){
			Push(&S,ch);
		}
		else if(ch==')'){
			flag=FALSE;

			while(!StackEmpty(S)){
				GetTop(&S,&top);
				if(top=='('){
					Pop(&S,&top);
					flag=TRUE;
					break;
				}
				Pop(&S,&top);
				printf("%c",top);
			}

			if(flag==FALSE){
				printf("\n右括号多余！");
				return;
			}
		}
		else if(IsOperator(ch)){
			while(!StackEmpty(S)){
				GetTop(&S,&top);
				if(top=='('||Priority(top)<Priority(ch)){
					break;
				}
				Pop(&S,&top);
				printf("%c",top);
			}
			Push(&S,ch);
		}
		else{
			printf("\n表达式中含有非法字符！");
			return;
		}
	}

	while(!StackEmpty(S)){
		Pop(&S,&top);
		if(top=='('){
			printf("\n左括号多余！");
			return;
		}
		printf("%c",top);
	}
}

int main(){
	SeqStack S;
	char x;
	char str[100];

	printf("顺序栈基本运算测试：\n");
	InitStack(&S);

	if(StackEmpty(S)){
		printf("初始化后：顺序栈为空\n");
	}
	else{
		printf("初始化后：顺序栈不为空\n");
	}

	Push(&S,'A');
	Push(&S,'B');
	Push(&S,'C');
	printf("依次入栈：A B C\n");

	if(StackFull(S)){
		printf("当前顺序栈已满\n");
	}
	else{
		printf("当前顺序栈未满\n");
	}

	GetTop(&S,&x);
	printf("当前栈顶元素：%c\n",x);

	Pop(&S,&x);
	printf("出栈元素：%c\n",x);

	GetTop(&S,&x);
	printf("出栈后栈顶元素：%c\n",x);

	printf("\n请输入表达式或文本，测试括号匹配：");
	scanf("%99s",str);
	BracketMatch(str);

	printf("\n\n请输入中缀表达式，转换为后缀表达式：");
	scanf("%99s",str);
	printf("后缀表达式为：");
	InfixToPostfix(str);

	return 0;
}

