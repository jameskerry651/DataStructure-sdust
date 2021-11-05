#include<stdio.h>
#include<stdlib.h>
#define Status int
#define MAXQSIZE 100
#define OK 1
#define ERROR -1
/*
 * 循环队列
 * 需要完成的函数有：
 * 1.循环队列初始化
 * 2.获取队列长度
 * 3.入队操作
 * 4.出队操作
 */
typedef struct{
    int *base;
    int prior;
    int rear;
} SqQueue;

// initial a Queue
Status initSqQueue(SqQueue &S )
{
    S.base =(int*) malloc(sizeof(int)*MAXQSIZE);
    if(!S.base) return ERROR;
    S.prior = 0;
    S.rear = 0;
    return OK;

}
// if rear==prior , queue's size equals 0
int getLength(SqQueue &S)
{
    return (S.rear-S.prior+MAXQSIZE)%MAXQSIZE;
}

// the real size is only MAXQSIZE -1
Status insertSqQueue(SqQueue &S,int x)
{
    if((S.rear+1)%MAXQSIZE ==S.prior) return ERROR;
    *(S.base+S.rear) = x;
    S.rear  = (S.rear+1)%MAXQSIZE;
    return OK;
}

Status deSqQueue(SqQueue &S,int &e)
{
    if(S.rear == S.prior) return ERROR;
    e = *(S.base+S.prior);
    S.prior = (S.prior+1)%MAXQSIZE;
    return OK;
}