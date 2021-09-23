#include<stdio.h>
#include<stdlib.h>

#define ERROR -1
#define OK 1
/**
��̬������Ҫ��ɵ�����
1.������̬����
2.����ĳ��Ԫ��
3.����ĳ���ڵ�
4.ɾ��ĳ���ڵ�
5.��������е�����Ԫ��
**/

typedef int ElemType;
typedef int Status;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
} LNode,*LinkList;

// ��������

Status Creat_Llist(LinkList &L);
Status Insert_Llist(LinkList &L,int pos,ElemType e);
void print_Llist(LinkList &L);
int main(){

    LinkList L;
    Creat_Llist(L);

    int i,tmp;
    for(i=0;i<3;i++){
        scanf("%d",&tmp);
        Insert_Llist(L,i+1,tmp);
    }
    print_Llist(L);

    return 0;
}

Status Creat_Llist(LinkList &L)
{
    LinkList newbase = (LinkList)malloc(sizeof(LNode));
    if(!newbase) return ERROR;
    L = newbase;
    L->next = NULL;
    return OK;
}

Status Insert_Llist(LinkList &L,int pos,ElemType e)
{
    LinkList p = L;
    int i=0;
    //Ѱ�ҵ�pos-1���ڵ��Ƿ����
    while(p && i<pos-1){
        p = p->next;
        i++;
    }
    if(!p) return ERROR;

    LinkList node = (LinkList)malloc(sizeof(LNode));
    node->data = e;
    node->next = p->next;
    p->next = node;

    return OK;
}

void print_Llist(LinkList &L)
{
    LinkList p = L->next;
    while(p){
        printf("%d ",p->data);
        p = p->next;
    }
}



