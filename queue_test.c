#include <stdio.h>

typedef int ElementType;
#include "queue.h"

void PrintYangHui(int n){
	CirQueue Q;
	int i,j,k;
	int old,last,next;

	InitQueue(&Q);
	EnQueue(&Q,1);

	for(i=1;i<=n;i++){
		for(k=0;k<n-i;k++){
			printf("  ");
		}

		last=0;
		for(j=1;j<=i;j++){
			DeQueue(&Q,&old);
			printf("%4d",old);

			next=last+old;
			EnQueue(&Q,next);
			last=old;
		}
		EnQueue(&Q,1);
		printf("\n");
	}
}

int main(){
	int n;

	printf("Input N: ");
	scanf("%d",&n);

	if(n<=0||n>=Queue_Size-1){
		printf("N must be between 1 and %d.\n",Queue_Size-2);
		return 0;
	}

	PrintYangHui(n);

	return 0;
}
