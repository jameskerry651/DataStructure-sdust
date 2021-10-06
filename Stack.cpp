#include<stdlib.h>
#include<stdio.h>

/**
栈相关的代码,需要完成的任务有
1.栈的初始化   Init_Stack()
2.入栈            Push()
3.出栈            Pop()
4.打印栈的内容
5.获取栈的长度
6.清空栈的内容
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

// 函数的声明
Status Init_Stack(SqStack &S);
Status Pop(SqStack &S,ElemType &e);
Status Push(SqStack &S,ElemType data);
// 主函数
int main(){
    SqStack S;


    return 0;
}


//函数的定义
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


