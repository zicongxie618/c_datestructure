#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef struct Node{
    ElemType data;
    struct Node* next;
}Node,*LinkList;
// 初始化链表
int InitList(LinkList *L)
{
    *L=(LinkList)malloc(sizeof(Node));
    if(!(*L)){printf("申请动态内存失败！");return ERROR;}
    (*L)->next=NULL;
    return OK;
}
// 头插法建表
void CreateFromHead(LinkList L){
    Node*s;
    char c;
    int flag=1;
    while(flag){
        c=getchar();
        if(c!='$'){
            s=(Node*)malloc(sizeof(Node));
            s->data=c;
            s->next=L->next;
            L->next=s;
        }
        else{
            flag=0;
        }
    }
}
// 尾插法建表
void CreateFromTail(LinkList L){
    char c; 
    Node *r,*s;
    int flag=1;
    r=L;
    while(flag){
        c=getchar();
        if(c!='$'){
            s=(Node*)malloc(sizeof(Node));
            s->data=c;
            r->next=s;
            r=s;
        }
        else{
            flag=0;r->next=NULL;
        }
            
    }
} 
// 通过数组建表（供测试使用）
void BuildList(LinkList L, int arr[], int n) {
    Node *r = L;
    int i;
    for(i = 0; i < n; i++) {
        Node *s = (Node*)malloc(sizeof(Node));
        s->data = arr[i];
        s->next = NULL;
        r->next = s;
        r = s;
    }
}
// 单链表的插入
int InsList(LinkList L,int i,ElemType e){
    Node*pre,*s;
    int k;
    if(i<=0){
        return ERROR;
    }
    pre=L;k=0;
    while(pre!=NULL&&k<i-1){
        pre=pre->next;
        k=k+1;
    } 
    if(pre==NULL){
        printf("插入位置不合理！");
        return ERROR;    
    }
    s=(Node *)malloc(sizeof(Node));
    s->data=e;
    s->next=pre->next; 
    pre->next=s;
    return OK;
}
// 单链表的删除
int DelList(LinkList L,int i,ElemType *e){
    Node *pre,*r;
    int k;
    if(i<=0){
        printf("删除结点的位置不合理！");
        return ERROR;
    }
    pre=L;k=0;
    while(pre->next!=NULL&&k<i-1){
        pre=pre->next;
        k=k+1;
    }
    if(pre->next==NULL){
        printf("删除结点的位置不合理！");
        return ERROR;
    }
    r=pre->next;
    pre->next=r->next;
    *e=r->data;
    free(r);
    return OK;
} 
// 输出单链表（供测试使用）
void PrintList(LinkList L) {
    Node *p = L->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
// 输出单链表的各元素（带序号）
void PrintListWithIndex(Node *L) {
    Node *p =L->next;
    int i = 0;
    while (p != NULL) {
        printf("[%d] = %d\n", i++, p->data);
        p = p->next;
    }
}
// 单链表的长度
int ListLength(LinkList L){
    Node *p;
    int j;
    p=L->next;
    j=0;
    while(p!=NULL){
        p=p->next;
        j++;
    }
    return j;
}
// 单链表数据结点的按值排序
int SortList(LinkList L){
    if(!L) {
        return ERROR;
    }
    if(L->next == NULL) {
        return OK;
    }
    int swapped,temp;
    Node *p,*last=NULL;
    do{
        swapped=0;
        p=L->next;
        while(p->next!=last){
            if(p->data>p->next->data){
                temp=p->data;
                p->data=p->next->data;
                p->next->data=temp;
                swapped=1;
            }
            p=p->next;
        }
        last=p;
    }while(swapped);
    return OK;
}
// 单链表的逆置
void ReverseList(LinkList L){
    Node *p,*q;
    p=L->next;
    L->next=NULL;
    while(p!=NULL){
        q=p->next;
        p->next=L->next;
        L->next=p;
        p=q;
    }
}
// 删除单链表中最大值
LinkList DelMax(LinkList L){
    if(!L){
        return NULL;
    }
    if(L->next == NULL) {
        return L;
    } 
    Node *max=L->next,*premax=L;
    Node *p=max->next,*prep=max;
    while(p){
        if(p->data>max->data){
            max=p;
            premax=prep;
        }
        prep=p;
        p=p->next;
    } 
    premax->next=max->next;
    free(max);
    return L;
}
// 删除单链表的最小值
LinkList DelMin(LinkList L){
    if(!L){
        return NULL;
    }
    if(L->next == NULL) {
        return L;
    } 
    Node *min=L->next,*premin=L;
    Node *p=min->next,*prep=min;
    while(p){
        if(p->data<min->data){
            min=p;
            premin=prep;
        }
        prep=p;
        p=p->next;
    } 
    premin->next=min->next;
    free(min);
    return L;
}
// 合并两个有序的单链表（有序的a表和有序的b表合并之后的结果正序或逆序保存在a表中）
LinkList MergeLinkList(LinkList LA,LinkList LB){
    Node *pa,*pb,*r;
    pa=LA->next;
    pb=LB->next;
    LA->next=NULL;
    r=LA;
    while(pa!=NULL&&pb!=NULL){
        if(pa->data<=pb->data){
            r->next=pa;r=pa;pa=pa->next;
        }
        else{
            r->next=pb;r=pb;pb=pb->next;
        }
    }
    if(pa){
        r->next=pa;
    }
    else{
        r->next=pb;
    }
    free(LB);
    return(LA);
}
// 单链表的按值拆分
void SplitListValue(LinkList LA,LinkList LB,ElemType value){
    Node *pa=LA->next;
    Node *pre=LA;
    Node *rb=LB;
    while(pa){
        if(pa->data>=value){
            pre->next=pa->next;rb->next=pa;rb=pa;pa=pre->next;
        }
        else{
            pre=pa;pa=pa->next;
        }
    }
    rb->next=NULL;
}
// 单链表的按次序拆分(奇数点留在LA，偶数点留在LB)
void SplitListIndex(LinkList LA,LinkList LB){
    Node *pa=LA->next;
    Node *pre=LA;
    Node *rb=LB;
    int i=1;
    while(pa){
        if(i%2==0){
            pre->next=pa->next;rb->next=pa;rb=pa;pa=pre->next;
        }
        else{
            pre=pa;pa=pa->next;
        }
        i++;
    }
    rb->next=NULL;
}
// 单链表的按序号查找-查找第i个结点
Node *GetData(LinkList L,int i){
    int cnt;
    Node *p;
    if(i<=0){
        return NULL;
    }
    p=L;cnt=0;
    while((p->next!=NULL)&&(cnt<i)){
        p=p->next;
        cnt++;
    }
    if(i==cnt){
        return p;
    }
    else{
        return NULL;
    }
} 
// 单链表的按值查找
Node *LocateData(LinkList L,ElemType value){
    Node *p;
    p=L->next;
    while(p!=NULL){
        if(p->data!=value){
            p=p->next;
        }
        else{
            break;
        }
    }
    return p;
} 
int main() {
	int i;
    printf("========== 1. InitList 初始化 ==========\n");
    LinkList L;
    if (InitList(&L) == OK) printf("InitList 成功\n\n");

    printf("========== 2. InsList 插入 ==========\n");
    int testData[] = {5, 2, 8, 1, 9, 3};
    for (i = 0; i < 6; i++) InsList(L, i + 1, testData[i]);
    printf("插入后: "); PrintList(L);
    printf("期望:   5 2 8 1 9 3\n\n");

    printf("========== 3. ListLength 求长度 ==========\n");
    printf("长度 = %d (期望 6)\n\n", ListLength(L));

    printf("========== 4. GetData 按序号查找 ==========\n");
    Node *p = GetData(L, 3);
    if (p) printf("第3个元素 = %d (期望 8)\n\n", p->data);

    printf("========== 5. LocateData 按值查找 ==========\n");
    p = LocateData(L, 9);
    if (p) printf("查找 9 -> 找到: %d\n\n", p->data);

    printf("========== 6. InsList 在第5位插入100 ==========\n");
    InsList(L, 5, 100);
    printf("插入后: "); PrintList(L);
    printf("期望:   5 2 8 1 100 9 3\n\n");

    printf("========== 7. DelList 删除第2个元素 ==========\n");
    ElemType e;
    DelList(L, 4, &e);
    printf("删除的值 = %d (期望 2)\n", e);
    printf("删除后: "); PrintList(L);
    printf("期望:  5 2 8 100 9 3 \n\n");

    printf("========== 8. SortList 按值排序 ==========\n");
    SortList(L);
    printf("排序后: "); PrintList(L);
    printf("期望:   2 3 5 8 9 100\n\n");

    printf("========== 9. DelMax 删除最大值 ==========\n");
    L = DelMax(L);
    printf("删最大值后: "); PrintList(L);
    printf("期望:     2 3 5 8 9\n\n");

    printf("========== 10. DelMin 删除最小值 ==========\n");
    L = DelMin(L);
    printf("删最小值后: "); PrintList(L);
    printf("期望:     3 5 8 9\n\n");

    printf("========== 11. ReverseList 逆置 ==========\n");
    ReverseList(L);
    printf("逆置后: "); PrintList(L);
    printf("期望:   9 8 5 3\n\n");

    printf("========== 12. MergeLinkList 合并有序链表 ==========\n");
    LinkList LA, LB;
    InitList(&LA); InitList(&LB);
    int a[] = {1, 3, 5, 7}, b[] = {2, 4, 6};
    BuildList(LA, a, 4); BuildList(LB, b, 3);
    printf("LA: "); PrintList(LA);
    printf("LB: "); PrintList(LB);
    LA = MergeLinkList(LA, LB);
    printf("合并: "); PrintList(LA);
    printf("期望: 1 2 3 4 5 6 7\n\n");

    printf("========== 13. SplitListValue 按值拆分(value=4) ==========\n");
    LinkList L1, L2;
    InitList(&L1); InitList(&L2);
    int sd[] = {1, 5, 2, 6, 3, 7, 4};
    BuildList(L1, sd, 7);
    printf("拆分前: "); PrintList(L1);
    SplitListValue(L1, L2, 4);
    printf("LA (<4) : "); PrintList(L1);
    printf("LB (>=4): "); PrintList(L2);
    printf("期望 LA: 1 2 3    LB: 5 6 7 4\n\n");

    printf("========== 14. SplitListIndex 按次序拆分 ==========\n");
    LinkList L3, L4;
    InitList(&L3); InitList(&L4);
    int si[] = {10, 20, 30, 40, 50, 60};
    BuildList(L3, si, 6);
    printf("拆分前: "); PrintList(L3);
    SplitListIndex(L3, L4);
    printf("奇数位: "); PrintList(L3);
    printf("偶数位: "); PrintList(L4);
    printf("期望 奇数: 10 30 50   偶数: 20 40 60\n\n");

    printf("========== 15. PrintListWithIndex 带序号输出 ==========\n");
    PrintListWithIndex(L3);
    return 0;
}