#include<stdlib.h>
#include<stdio.h>

/**
ջ��صĴ���,��Ҫ��ɵ�������
1.ջ�ĳ�ʼ��
2.��ջ Push
3.��ջ Pop
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
Status Init_Stack(SqStack &S){
    S.base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(SqStack));
    if(!S.base) return ERROR;
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

int main(){
    SqStack S;


    return 0;
}
