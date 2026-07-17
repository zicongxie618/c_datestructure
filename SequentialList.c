#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef struct{
    ElemType elem[MAXSIZE];
    int last;
} SeqList;
void InitList(SeqList *L){
    L->last = -1;
}
void PrintList(SeqList *L){
    int i;
    if(L->last==-1){
        printf("顺序表为空\n");
        return;
    }   
    for(i = 0; i <= L->last; i++){
        printf("%d ", L->elem[i]);
    }
    printf("\n");
}
int Inslist(SeqList*L,int i,ElemType e){
    int k;
    if((i<1)||(i>L->last+2)){
        printf("插入位置不合法！");
        return(ERROR);
    }
    if(L->last==MAXSIZE-1){
        printf("顺序表已满，不能插入！");
        return(ERROR);
    }
    for(k=L->last;k>=i-1;k--){
        L->elem[k+1]=L->elem[k];
    }
     L->elem[i-1]=e;
    L->last++;
    return(OK);
}
int Delist(SeqList*L,int i,ElemType*e){
    int k;
    if((i<1)||(i>L->last+1)){
        printf("删除位置不合法！");
        return(ERROR);
    }
    *e=L->elem[i-1];
    for(k=i;k<=L->last;k++){
        L->elem[k-1]=L->elem[k];
    }
    L->last--;
    return(OK);
}
int Length(SeqList L){
    return(L.last+1);
}
void Reverse(SeqList *L){
    ElemType Temp;
    int i;
    for(i=0;i<Length(*L)/2;i++){
        Temp=L->elem[i];
        L->elem[i]=L->elem[L->last-i];
        L->elem[L->last-i]=Temp;
    }
}
void SortList(SeqList *L){
    int i,j;
    ElemType Temp;
    for(i=0;i<L->last;i++){
        for(j=0;j<L->last-i;j++){
            if(L->elem[j]>=L->elem[j+1]){
                Temp=L->elem[j];
                L->elem[j]=L->elem[j+1];
                L->elem[j+1]=Temp;
            }
        }
    }
}
void  DelMax(SeqList *L){
    int j,i,max=0;
    ElemType e;
    for(i=1;i<Length(*L);i++){
        if(L->elem[i]>L->elem[max]){
            max=i;
        }
    }
    Delist(L,max+1,&e);
    printf("删除的最大值为：%d\n",e);
}
void  DelMin(SeqList *L){
    int j,i,min=0;
    ElemType e;
    for(i=1;i<Length(*L);i++){
        if(L->elem[i]<L->elem[min]){
            min=i;
        }
    }
    Delist(L,min+1,&e);
    printf("删除的最小值为：%d\n",e);
}
void MergeList(SeqList *LA,SeqList *LB,SeqList *LC){
    int i,j,k,l;
    i=j=k=0;
    while(i<=LA->last&&j<=LB->last){
        if(LA->elem[i]<=LB->elem[j]){
            LC->elem[k]=LA->elem[i];
            i++;
            k++;
        }
        else{
            LC->elem[k]=LB->elem[j];
            j++;
            k++;
        }
    }
    while(i<=LA->last){
         LC->elem[k]=LA->elem[i];
            i++;
            k++;
    }
    while(j<=LB->last){
        LC->elem[k]=LB->elem[j];
        j++;
        k++;
    }
    LC->last=LA->last+LB->last+1;
}
int Del_ik(SeqList *L,int i,int k,ElemType *e){
    int j;   
    if((i<1)||(i>L->last+1)){
        printf("删除位置不合法！");
        return(ERROR);
    }
    for(j=i+k-1;j<=L->last;j++){
        L->elem[j-k]=L->elem[j];
    }
     L->last=L->last-k;
    printf("已经从第%d个元素开始删除%d个元素。",i,k);
    return(OK);
}
int InsertorderedList(SeqList *L, ElemType x) {
    if (L->last>= MAXSIZE-1){
        printf("顺序表已满，不能插入！");
        return (ERROR);
    }
    int i;
    for (i = L->last; i >= 0 && L->elem[i] > x; i--){
        L->elem[i + 1] = L->elem[i];
    } 
    L->elem[i + 1] = x;  
    L->last++;
    printf("元素%d已插入顺序表中。\n", x);
    return (OK);
}
int main(){
    SeqList L, LA, LB, LC;
    ElemType e;
    int i;
    printf("初始化并插入元素\n");
    InitList(&L);
    for(i = 1; i <= 8; i++){
        Inslist(&L, i, i * 10);  
    }
    printf("初始顺序表：");
    PrintList(&L);   
    printf("\n在第3位插入25\n");
    Inslist(&L, 3, 25);
    PrintList(&L); 
    printf("\n 删除第5个元素\n");
    Delist(&L, 5, &e);
    printf("被删除的元素：%d\n", e);  
    PrintList(&L);                    
    printf("\n当前表长\n");
    printf("表长：%d\n", Length(L));   
    printf("\n 逆置顺序表 \n");
    Reverse(&L);
    PrintList(&L);  
    printf("\n删除最大值\n");
    DelMax(&L);      
    PrintList(&L);   
    printf("\n删除最小值\n");
    DelMin(&L);    
    PrintList(&L);   
    printf("\n升序排序\n");
    SortList(&L);
    PrintList(&L);   
    printf("\n 有序插入 45 \n");
    InsertorderedList(&L, 45);
    PrintList(&L);
    printf("\n从第2位开始删除3个元素 \n");
    Del_ik(&L, 2, 3, &e);
    printf("\n");
    PrintList(&L);  
    printf("\n合并两个有序表 \n");
    InitList(&LA);  InitList(&LB);  InitList(&LC);
    Inslist(&LA, 1, 1);
    Inslist(&LA, 2, 3);
    Inslist(&LA, 3, 5);
    Inslist(&LA, 4, 7);
    Inslist(&LB, 1, 2);
    Inslist(&LB, 2, 4);
    Inslist(&LB, 3, 6);
    printf("LA:");  PrintList(&LA);
    printf("LB:");  PrintList(&LB);
    MergeList(&LA, &LB, &LC);
    printf("合并后 LC:");
    PrintList(&LC);  

    return 0;
}
