#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

/**
��˳�����Ҫ��ɵ�����
1.˳���ĳ�ʼ�� InitList(&L)
2.˳�������   ClearList(&L)
3.˳���Ĵ�ӡ   PrintList(&L)
4.˳���Ĳ���    ListInsert(&L,i,e)
5.˳����ɾ��ĳ���� ListDelete(&L,i,&e)
6.����˳���ĺϲ�
7.����˳����λ�÷�������ֵ GetElem(&L,i,&e)
8.˳��������    DestroyList(&L)
9.˳��������    ListReverse_Sq(SqList &L)

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
        printf("������һ�����֣�\n");
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
    printf("˳����ʼ���ɹ���\n");
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
    printf("��ɾ����Ԫ��Ϊ��%d \n",e);
    int i;
    for(i=pos;i<L.length;i++){
        *(L.elem+i-1) = *(L.elem+i);
    }
    --L.length;
    return OK;
}

void ClearList(Sqlist &L){
    L.length = 0;            // ʵ����û�д�������������գ�ֻ��˵���пռ���߼���Ϊ�գ����������������
}

Status DestroyList(Sqlist &L){
    free(L.elem);
    if(L.elem)return ERROR;

    return OK;
}

Status GetElem(Sqlist &L,int pos,ElemType &e){
    if(pos<1 || pos>L.length)return ERROR;
    e = *(L.elem + pos -1);
    printf("��õ�Ԫ��ֵΪ��%d \n",e);
    return OK;
}

Status ListReverse_Sq(Sqlist &L){
    int i,t;
    t = L.length/2;       //��ż����ν
    for(i=0;i<=t;i++){
        int tmp = *(L.elem + i);
        *(L.elem+i) = *(L.elem + L.length-1-i);
        *(L.elem + L.length-1-i) = tmp;
    }

    return OK;

}




