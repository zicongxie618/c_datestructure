#include <stdio.h>
#include <stdlib.h>
#define Stack_Size 50
#define M 100
#define N 10 
#define FALSE 0
#define TRUE 1
typedef int StackElementType;
typedef struct{
	StackElementType elem[Stack_Size];
	int top;
}SeqStack;
//≥ı ºªØ
void InitStack(SeqStack *S){
	S->top=-1;
} 
//Ω¯’ª
int Push(SeqStack *S,StackElementType x){
	if(S->top==Stack_Size-1){
		return (FALSE);
	}
	S->top++;
	S->elem[S->top]=x;
	return (TRUE);
} 
//≥ˆ’ª
int Pop(SeqStack *S,StackElementType *x){
	if(S->top==-1){
		return (FALSE);
	}
	else{
		*x=S->elem[S->top];
	}
	S->top--;
	return (TRUE);
} 
 //∂¡’ª∂•‘™Àÿ
int GetTop(SeqStack *S,StackElementType *x){
		if(S->top==-1){
		return (FALSE);
	}
	else{
		*x=S->elem[S->top];
	}
	return (TRUE); 
} 
//∂®“ÂÀ´∂ÀÀ≥–Ú’ª 
typedef struct{
	StackElementType Stack[M];
	StackElementType top[2];
}DqStack;
//≥ı ºªØÀ´∂ÀÀ≥–Ú’ª
void InitStack(DqStack *S){
	S->top[0]=-1;
	S->top[1]=M;
} 
//À´∂ÀÀ≥–Ú’ªΩ¯’ª≤Ÿ◊˜
int Push(DqStack *S,StackElementType x,int i){
	if(S->top[0]+1==S->top[1]){
		return (FALSE); 
	}
	switch(i){
		case 0:
			S->top[0]++;
			S->Stack(S->top[0])=x;
			break;
		case 1:
			S->top[1]--;
			S->Stack(S->top[1])=x;
		default:
			return (FALSE);
	}
	return (TRUE);
} 
//À´∂ÀÀ≥–Ú’ª≥ˆ’ª≤Ÿ◊˜ 
int Pop(DqStack *S,StackElemType *x,int i){
	switch(i){
		case 0:
			if(S->top[0]==-1){
				return (FALSE);
			}
			*x=S->Stack[S->top[0]];
			S->top[0]--;
			break;
		case 1:
			if(S->top[1]==M){
				return (FALSE);
			}
			*x=S->Stack[S->top[1];
			S->top[1]++;
			break;
		default:
			return (FALSE);
	}
} 
//¡¥’ª 
typedef struct node{
	StackElementType data;
	struct node * next;
}LinkStackNode;
typedef LinkStackNode *LinkStack;
//¡¥’ªΩ¯’ª
int Push(LinkStack top,StackElementType *x){
	LinkStackNode *temp;
	temp=top->next;
	if(temp==NULL){
		return (FALSE);
	}
	top->next=temp->next;
	*x=temp->data;
	free(temp);
	return (TRUE);
}
//∂‡’ª‘ÀÀ„ 
typedef struct node{
	StackElementType data;
	struct node *next;
}LinkStackNode,*LinkStack;
LinkStack top[N];
//¿®∫≈∆•≈‰À„∑®
void BracketMatch(char *str){
	Stack S;int i;char ch;
	InitStack(&S);
	for(i=0;str[i]!='\0';i++){
		switch(str[i]){
			case'(':
			case'[':
			case'{':
				break;
				Push(&S,str[i]);
				break;
			case')':
			case']':
			case'}':
				if(IsEmpty(&S)){
					printf("\n”“¿®∫≈∂‡”‡£°")£ªreturn; 
				}
				else{
					GetTop(&S,&ch);
					if(Match(ch,str[i])){
						Pop(&S,&ch);
					}
					else{
						printf("\n∂‘”¶µƒ◊Û”“¿®∫≈≤ªÕ¨¿‡£°";return;)
					} 
				}
		}
	}
	if(IsEmpty(S)){
		printf("\n¿®∫≈∆•≈‰£°"); 
	}
	else{
		printf("\n◊Û¿®∫≈∂‡”‡£°"); 
	}
} 
