#include <stdio.h>
#include <string.h>
#define MAXLEN 255
typedef struct{
	char ch[MAXLEN+1];
	int length;
}SString;
void CreateString(SString *s){
	char temp[MAXLEN+1];
	printf("请输入字符串： ");
	scanf("%s",temp);
	s->length=strlen(temp);
	strcpy(s->ch,temp); 
}
void PrintString(SString s){
	printf("串的内容： %s\n",s.ch);
	printf("串的长度： %d\n",s.length);
}
int Index_BF(SString s,SString t){
	int i=0;
	int j=0;
	while(i<s.length&&j<t.length){
		if(s.ch[i]==t.ch[j]){
			i++;j++;
		}
		else{
			i=i-j+1;
			j=0;
		}
	}
	if(j==t.length){
		return (i-t.length+1);
	}
	else{
		return 0;
	}
} 
void GetNext(SString t,int next[]){
	int j=0;
	int k=-1;
	next[0]=-1;
	while(j<t.length-1){
		if(k==-1||t.ch[j]==t.ch[k]){
			j++;k++;next[j]=k;
		}
		else{
			k=next[k];
		}
	}
} 
void GetNextval(SString t,int nextval[]){
	int j=0;
	int k=-1;
	nextval[0]=-1;
	while(j<t.length-1){
		if(k==-1||t.ch[j]==t.ch[k]){
			j++;k++;
			if(t.ch[j]!=t.ch[k]){
				nextval[j]=k;
			} 
			else{
				nextval[j]=nextval[k];
			}
		}
		else{
			k=nextval[k];
		}

		
	}
}
int Index_KMP(SString s,SString t){
	int i=0;
	int j=0;
	int next[MAXLEN];
	GetNext(t,next);
	while(i<s.length&&j<t.length){
		if(j==-1||s.ch[i]==t.ch[j]){
			j++;i++;
		}
		else{
			j=next[j];
		}
	}
	if(j==t.length){
		return (i-t.length+1);
	}
	else{
		return 0;
	}
}
int Index_KMP_Nextval(SString s,SString t){
	int i=0;
	int j=0;
	int nextval[MAXLEN];
	GetNextval(t,nextval);
	while(i<s.length&&j<t.length){
		if(j==-1||s.ch[i]==t.ch[j]){
			j++;i++;
		}
		else{
			j=nextval[j];
		}
	}
	if(j==t.length){
		return (i-t.length+1);
	}
	else{
		return 0;
	}
}
void ShowMenu() {
    printf("\n========== 串的模式匹配 ==========\n");
    printf("1. 简单模式匹配\n");
    printf("2. KMP模式匹配\n");
    printf("3. KMP改进匹配(nextval)\n");
    printf("4. 输出next数组\n");
    printf("5. 输出nextval数组\n");
    printf("0. 退出程序\n");
    printf("请选择：");
}
int main(){
	SString mainStr;
	SString patternStr;
	int choice;
	int pos;
	int next[MAXLEN];
	int nextval[MAXLEN];
	int i;
	printf("创建主串\n");
	CreateString(&mainStr);
	printf("创建模式串\n");
	CreateString(&patternStr);
	printf("\n主串信息: \n");
	PrintString(mainStr);
	printf("\n模式串信息: \n");
	PrintString(patternStr);
	do{
		ShowMenu();
		scanf("%d",&choice);
		switch(choice){
			case 1:
			pos=Index_BF(mainStr,patternStr);
			if(pos!=0){
				printf("\n简单匹配成功，位置是：%d\n",pos);
			}
			else{
				printf("\n简单匹配失败，没有找到模式串\n");
			}
			break;
			case 2:
			pos=Index_KMP(mainStr,patternStr);
			if(pos!=0){
				printf("\nKMP匹配成功，位置是：%d\n",pos);
			}
			else{
				printf("\nKMP匹配失败，没有找到模式串\n");
			}
			break;
			case 3:
			pos=Index_KMP_Nextval(mainStr,patternStr);
			if(pos!=0){
				printf("\nKMP改进匹配成功，位置是：%d\n",pos);
			}
			else{
				printf("\nKMP改进匹配失败，没有找到模式串\n");
			}
			break;
			case 4:
			GetNext(patternStr,next);
	  		printf("\nnext数组： ");
			for(i=0;i<patternStr.length;i++){
				printf("%d ",next[i]);
			} 
			printf("\n");
			break;
			case 5:
			GetNextval(patternStr,nextval);
			printf("\nnextval数组： ");
			for(i=0;i<patternStr.length;i++) {
				printf("%d ",nextval[i]);
			}
			printf("\n");
			break;
			case 0:
				printf("\n程序结束。\n");
				break; 
			default: 
				printf("\n输入错误，请重新选择。\n");
				break;
		}
	}while(choice!=0);
	return 0; 
}