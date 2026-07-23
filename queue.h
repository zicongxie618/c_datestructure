#ifndef QUEUE_H
#define QUEUE_H

#define Queue_Size 100
#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif
//构建循环队列类型
typedef struct{
	ElementType elem[Queue_Size];
	int front;
	int rear;
}CirQueue;
//循环队列的初始化
void InitQueue(CirQueue *Q){
	Q->front=0;
	Q->rear=0;
}
//循环队列的判空
int QueueEmpty(CirQueue Q){
	if(Q.front==Q.rear){
		return TRUE;
	}
	else{
		return FALSE;
	}
}
//循环队列的判满
int QueueFull(CirQueue Q){
	if((Q.rear+1)%Queue_Size==Q.front){
		return TRUE;
	}
	else{
		return
		return FALSE;
	}
}
//循环队列的入队
int EnQueue(CirQueue *Q,ElementType x){
	if(QueueFull(*Q)){
		return FALSE;
	}
	Q->elem[Q->rear]=x;
	Q->rear=(Q->rear+1)%Queue_Size;
	return TRUE;
}
//循环队列的出队
int DeQueue(CirQueue *Q,ElementType *x){
	if(QueueEmpty(*Q)){
		return FALSE;
	}
	*x=Q->elem[Q->front];
	Q->front=(Q->front+1)%Queue_Size;
	return TRUE;
}
//循环队列的读取队头元素
int GetHead(CirQueue Q,ElementType *x){
	if(QueueEmpty(Q)){
		return FALSE;
	}
	*x=Q.elem[Q.front];
	return TRUE;
}
//循环队列的读取队尾元素
int GetRear(CirQueue Q,ElementType *x){
	if(QueueEmpty(Q)){
		return FALSE;
	}
	*x=Q.elem[(Q.rear-1+Queue_Size)%Queue_Size];
	return TRUE;
}
#endif
