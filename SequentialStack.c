#ifndef STACK_H
#define STACK_H 
#include <stdio.h>
#define Stack_Size 50
#define FALSE 0
#define TRUE 1
typedef struct{
    ElementType elem[Stack_Size];
    int top;
}SeqStack;
//Ë³ÐòÕ»µÄ³õÊ¼»¯
void InitStack(SeqStack *S){
    S->top=-1;
} 
//Ë³ÐòÕ»ÅÐ¿Õ 
int StackEmpty(SeqStack S) {
    if(S.top==-1){
        return (TRUE);
    }
    else{
        return (FALSE);
    }
}
//Ë³ÐòÕ»ÅÐÂú
int StackFull(SeqStack S) {
    if(S.top==Stack_Size-1){
        return (TRUE);
    }
    else{
        return (FALSE);
    }
} 
//½øÕ»
int Push(SeqStack *S,ElementType x){
    if(StackFull(*S)){
        return (FALSE);
    }
    S->top++;
    S->elem[S->top]=x;
    return (TRUE);
} 
//³öÕ»
int Pop(SeqStack *S,ElementType *x){
    if(StackEmpty(*S)){
        return (FALSE);
    }
    else{
        *x=S->elem[S->top];
    }
    S->top--;
    return (TRUE);
} 
//¶ÁÈ¡Õ»¶¥ÔªËØ
int GetTop(SeqStack *S,ElementType *x){
    if(StackEmpty(*S)){
        return (FALSE);
    }
    else{
        *x=S->elem[S->top];
    }
    return (TRUE); 
} 
//ÅÐ¶Ï×óÓÒÀ¨ºÅÊÇ·ñÆ¥Åä
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
//À¨ºÅÆ¥ÅäËã·¨
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
                    printf("\nÓÒÀ¨ºÅ¶àÓà£¡");
                    return; 
                }
                else{
                    GetTop(&S,&ch);
                    if(Match(ch,str[i])){
                        Pop(&S,&ch);
                    }
                    else{
                        printf("\n¶ÔÓ¦µÄ×óÓÒÀ¨ºÅ²»Í¬Àà£¡");
                        return;
                    } 
                }
                break;
        }
    }

    if(StackEmpty(S)){
        printf("\nÀ¨ºÅÆ¥Åä£¡"); 
    }
    else{
        printf("\n×óÀ¨ºÅ¶àÓà£¡"); 
    }
} 
//ÔËËã·ûÓÅÏÈ¼¶
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
//ÅÐ¶ÏÊÇ·ñÎªÔËËã·û
int IsOperator(char ch){
    return ch=='+'||ch=='-'||ch=='*'||ch=='/';
}
//ÖÐ×º±í´ïÊ½×ª»¯Îªºó×º±í´ïÊ½ 
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
                printf("\nÓÒÀ¨ºÅ¶àÓà£¡");
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
            printf("\n±í´ïÊ½ÖÐº¬ÓÐ·Ç·¨×Ö·û£¡");
            return;
        }
    }

    while(!StackEmpty(S)){
        Pop(&S,&top);
        if(top=='('){
            printf("\n×óÀ¨ºÅ¶àÓà£¡");
            return;
        }
        printf("%c",top);
    }
}

#endif
