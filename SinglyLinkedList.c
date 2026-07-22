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
void ClearList(LinkList L) {
    Node *p = L->next;
    while (p) {
        Node *q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL;
}

void InputList(LinkList L) {
    int n;
    ElemType e;

    ClearList(L);
    printf("请输入元素个数: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("请输入第%d个元素: ", i);
        scanf("%d", &e);
        InsList(L, i, e);
    }
}

void ShowMenu(void) {
    printf("\n========== 单链表操作菜单 ==========\n");
    printf("1. 初始化/重新建立链表\n");
    printf("2. 插入元素\n");
    printf("3. 删除元素\n");
    printf("4. 输出链表\n");
    printf("5. 求链表长度\n");
    printf("6. 按值排序\n");
    printf("7. 逆置链表\n");
    printf("8. 删除最大值\n");
    printf("9. 删除最小值\n");
    printf("10. 按序号查找\n");
    printf("11. 按值查找\n");
    printf("12. 合并两个有序链表\n");
    printf("13. 按值拆分链表\n");
    printf("14. 按次序拆分链表\n");
    printf("15. 带序号输出链表\n");
    printf("0. 退出\n");
    printf("请选择: ");
}

int main() {
    LinkList L;
    int choice, pos;
    ElemType e, key;
    Node *p;

    if (InitList(&L) == ERROR) {
        return ERROR;
    }

    do {
        ShowMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                InputList(L);
                printf("当前链表: ");
                PrintList(L);
                break;

            case 2:
                printf("请输入插入位置和元素值: ");
                scanf("%d%d", &pos, &e);
                if (InsList(L, pos, e) == OK) {
                    printf("插入成功，当前链表: ");
                    PrintList(L);
                }
                break;

            case 3:
                printf("请输入删除位置: ");
                scanf("%d", &pos);
                if (DelList(L, pos, &e) == OK) {
                    printf("删除成功，删除的值为: %d\n", e);
                    printf("当前链表: ");
                    PrintList(L);
                }
                break;

            case 4:
                printf("当前链表: ");
                PrintList(L);
                break;

            case 5:
                printf("链表长度为: %d\n", ListLength(L));
                break;

            case 6:
                SortList(&L);
                printf("排序后链表: ");
                PrintList(L);
                break;

            case 7:
                ReverseList(L);
                printf("逆置后链表: ");
                PrintList(L);
                break;

            case 8:
                L = DelMax(L);
                printf("删除最大值后链表: ");
                PrintList(L);
                break;

            case 9:
                L = DelMin(L);
                printf("删除最小值后链表: ");
                PrintList(L);
                break;

            case 10:
                printf("请输入要查找的位置: ");
                scanf("%d", &pos);
                p = GetData(L, pos);
                if (p) {
                    printf("第%d个元素为: %d\n", pos, p->data);
                } else {
                    printf("没有找到该位置的元素。\n");
                }
                break;

            case 11:
                printf("请输入要查找的值: ");
                scanf("%d", &key);
                p = LocateData(L, key);
                if (p) {
                    printf("找到元素: %d\n", p->data);
                } else {
                    printf("没有找到该元素。\n");
                }
                break;

            case 12: {
                LinkList LA, LB;
                InitList(&LA);
                InitList(&LB);
                printf("请输入有序链表A（从小到大）:\n");
                InputList(LA);
                printf("请输入有序链表B（从小到大）:\n");
                InputList(LB);
                ClearList(L);
                free(L);
                L = MergeLinkList(LA, LB);
                printf("合并后的链表: ");
                PrintList(L);
                break;
            }

            case 13: {
                LinkList LB;
                InitList(&LB);
                printf("请输入拆分界限值，>=该值的结点放入新链表: ");
                scanf("%d", &key);
                SplitListValue(L, LB, key);
                printf("原链表中剩余元素: ");
                PrintList(L);
                printf("新链表中的元素: ");
                PrintList(LB);
                ClearList(LB);
                free(LB);
                break;
            }

            case 14: {
                LinkList LB;
                InitList(&LB);
                SplitListIndex(L, LB);
                printf("奇数位元素链表: ");
                PrintList(L);
                printf("偶数位元素链表: ");
                PrintList(LB);
                ClearList(LB);
                free(LB);
                break;
            }

            case 15:
                PrintListWithIndex(L);
                break;

            case 0:
                printf("程序结束。\n");
                break;

            default:
                printf("输入有误，请重新选择。\n");
        }
    } while (choice != 0);

    ClearList(L);
    free(L);
    return 0;
}