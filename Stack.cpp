#include<stdlib.h>
#include<stdio.h>

/**
ջ��صĴ���,��Ҫ��ɵ�������
1.ջ�ĳ�ʼ��   Init_Stack()
2.��ջ            Push()
3.��ջ            Pop()
4.��ӡջ������
5.��ȡջ�ĳ���
6.���ջ������
**/
#define STACK_INIT_SIZE 100
#define STACK_INCRESEMENT 10
#define OK 1
#define ERROR -1


typedef int ElemType;
typedef int Status;
typedef struct {
    ElemType *base;
    ElemType *top;
    int stacksize;
}SqStack;

// ����������
Status Init_Stack(SqStack &S);
Status Pop(SqStack &S,ElemType &e);
Status Push(SqStack &S,ElemType data);
// ������
int main(){
    SqStack S;


    return 0;
}


//�����Ķ���
Status Init_Stack(SqStack &S){
    S.base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if(!S.base) return ERROR;
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

Status Pop(SqStack &S,ElemType &e)
{

    if(S->top==S->base)return ERROR;
    e = *--S->top;
    return OK;

}

Status Push(SqStack &S,ElemType data)
{
    if(S.top-S.base>=S.stacksize){
        ElemType *newbase = (ElemType *)realloc(S.base,(S.stacksize+STACK_INCRESEMENT)*sizeof(ElemType));
        if(!newbase)return ERROR;
        S.base = newbase;
        S.top = S.base + S.stacksize;
        S.stacksize = S.stacksize + STACK_INCRESEMENT;
    }
    *S.top = data;
    S.top ++;
    return OK;

}


