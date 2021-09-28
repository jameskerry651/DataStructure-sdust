#include<stdio.h>
#include<stdlib.h>

#define ERROR -1
#define OK 1
/**
动态链表需要完成的任务：
1.创建动态链表   Creat_Llist
2.查找某个元素
3.根据位置插入一个节点  Insert_Llist
4.删除某个节点
5.输出链表中的所有元素  print_Llist
6.按照不递减的顺序插入元素到链表中去
**/

typedef int ElemType;
typedef int Status;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
} LNode,*LinkList;

// 函数声明

Status Creat_Llist(LinkList &L);
Status Insert_Llist(LinkList &L,int pos,ElemType e);
void print_Llist(LinkList &L);
Status insert_sort_list(LinkList &L,int num);

//主函数
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
    //寻找第pos-1个节点是否存在
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

Status insert_sort_list(LinkList &L,int num){
    //考虑一开始的链表为空的特殊情况

    LinkList cur = L;
    if(cur->next == NULL){
        LinkList tmp = (LinkList) malloc(sizeof(LNode));
        tmp->data = num;
        cur->next = tmp;
        tmp->next = NULL;
        return OK;
    }
    // 一开始链表不为空或者只有一个的时候

    while (cur->next!=NULL){
        LinkList prior = cur;
        cur = cur->next;         //目前的指针
        LinkList rear = cur->next;  //目前指针的后一个指针

        if(rear==NULL){
            LinkList tmp = (LinkList) malloc(sizeof(LNode));
            tmp->data = num;
            cur->next = tmp;
            tmp->next = NULL;
            return OK;
        }

        if(num>= cur->data && num<=rear->data){
            LinkList tmp = (LinkList) malloc(sizeof(LNode));
            tmp->data = num;
            tmp->next = rear;
            cur->next = tmp;
            return OK;
        }

    }


}

