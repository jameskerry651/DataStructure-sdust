#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

/**
（顺序表）需要完成的任务：
1.顺序表的初始化 InitList(&L)
2.顺序表的清空   ClearList(&L)
3.顺序表的打印   PrintList(&L)
4.顺序表的插入    ListInsert(&L,i,e)
5.顺序表的删除某个点 ListDelete(&L,i,&e)
6.两个顺序表的合并
7.根据顺序表的位置返回其数值 GetElem(&L,i,&e)
8.顺序表的销毁    DestroyList(&L)
9.顺序表的逆序    ListReverse_Sq(SqList &L)

**/
#define ERROR -1
#define OK 1
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int Status;
typedef int ElemType;
typedef struct{
    ElemType *elem;
    int length;
    int listsize;
}Sqlist;


Status InitList(Sqlist &L);
Status ListInsert(Sqlist &L,int i,ElemType e);
void PrintList(Sqlist &L);
Status ListDelete(Sqlist &L,int pos,ElemType &e);
void ClearList(Sqlist &L);
Status DestroyList(Sqlist &L);
Status GetElem(Sqlist &L,int pos,ElemType &e);
Status ListReverse_Sq(Sqlist &L);
int main()
{
    Sqlist list;
    InitList(list);
    int i,num;
    for(i=1;i<5;i++){
        printf("请输入一个数字：\n");
        scanf("%d",&num);
        ListInsert(list,i,num);
    }
    //int a;
    ListInsert(list,3,22);
    PrintList(list);
    ListReverse_Sq(list);
    PrintList(list);
    return 0;
}

Status InitList(Sqlist &L){
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!L.elem) return ERROR;
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    printf("顺序表初始化成功！\n");
    return OK;
}


Status ListInsert(Sqlist &L,int pos,ElemType e)
{
    if(pos<1||pos>L.length+1)return ERROR;
    if(L.length>=L.listsize){
        ElemType *newbase;
        newbase = (ElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
        if(!newbase)return ERROR;
        L.elem = newbase;

    }

    L.listsize = L.listsize + LISTINCREMENT;
    int i = L.length;
    while(i>=pos){
        *(L.elem+ i) = *(L.elem + i-1);
        --i;
    }
    *(L.elem + pos- 1) = e;
    L.length ++;
    return OK;
}

void PrintList(Sqlist &L)
{
    int i;
    for(i=0;i<L.length;i++){
        printf("%d ",*(L.elem+i));
    }
    printf("\n");

}

Status ListDelete(Sqlist &L,int pos,ElemType &e){
    if(pos<1 ||pos>L.length) return ERROR;
    e = *(L.elem + pos -1);
    printf("被删除的元素为：%d \n",e);
    int i;
    for(i=pos;i<L.length;i++){
        *(L.elem+i-1) = *(L.elem+i);
    }
    --L.length;
    return OK;
}

void ClearList(Sqlist &L){
    L.length = 0;            // 实际上没有从物理意义上清空，只是说所有空间从逻辑上为空，可以随意填充数据
}

Status DestroyList(Sqlist &L){
    free(L.elem);
    if(L.elem)return ERROR;

    return OK;
}

Status GetElem(Sqlist &L,int pos,ElemType &e){
    if(pos<1 || pos>L.length)return ERROR;
    e = *(L.elem + pos -1);
    printf("获得的元素值为：%d \n",e);
    return OK;
}

Status ListReverse_Sq(Sqlist &L){
    int i,t;
    t = L.length/2;       //奇偶无所谓
    for(i=0;i<=t;i++){
        int tmp = *(L.elem + i);
        *(L.elem+i) = *(L.elem + L.length-1-i);
        *(L.elem + L.length-1-i) = tmp;
    }

    return OK;

}




