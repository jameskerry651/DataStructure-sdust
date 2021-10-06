#include<stdio.h>
#include<stdlib.h>

#define ERROR -1
#define OK 1
/**
动态链表需要完成的任务：
1.创建动态链表   Creat_Llist
2.查找某个元素    Locate_elem
3.根据位置插入一个节点  Insert_Llist
4.删除某个节点            delet_Llist
5.输出链表中的所有元素  print_Llist
6.按照不递减的顺序插入元素到链表中去 insert_sort_list
7.获取链表长度  getLength
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
int getLength(LinkList &L);
Status delet_Llist(LinkList &L,int pos);
int Locate_elem(LinkList &L,ElemType elem);      //如果存在则返回位置，不存在则返回-1


//主函数
int main(){

    LinkList L;
    Creat_Llist(L);

    int i,tmp;
    int count = 0;
    scanf("%d",&count);

    for(i=0;i<count;i++){
        scanf("%d",&tmp);
        insert_sort_list(L,tmp);
    }
    delet_Llist(L,2);
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
    //此时如果p存在，那么一定指向插入位置的前一个
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

    LinkList cur = L;
    //考虑一开始的链表为空的特殊情况
    if(L->next == NULL){
        LinkList tmp = (LinkList) malloc(sizeof(LNode));
        tmp->data = num;
        cur->next = tmp;
        tmp->next = NULL;
        return OK;
    }
    while(cur->next){
        LinkList prior = cur;
        cur = cur->next ;

        if(num<=cur->data){
        LinkList tmp = (LinkList) malloc(sizeof(LNode));
        tmp->data = num;
        tmp->next = prior->next;
        prior->next = tmp;
        return OK;
        }
    }

    // 比所有的数字都大就尾插最后一个
    LinkList tmp = (LinkList) malloc(sizeof(LNode));
    tmp->data = num;
    cur->next = tmp;
    tmp->next = NULL;
    return OK;


}

int getLength(LinkList &L)
{
    LinkList cur = L;
    int count;
    while(cur->next){
        cur = cur->next;
        count++;
    }

    return count;
}


Status delet_Llist(LinkList &L,int pos)
{
    LinkList p = L;
    int i = 0;
    while(p &&i<pos-1){
        p = p->next;
        i++;
    }

    if(!p)return ERROR;
    // 注意单个删除简单，如果是连续删除，前驱节点的位置不会更新，直到没有删除向前移动
    p->next = p->next->next;
    return OK;
}

int Locate_elem(LinkList &L,ElemType elem)
{
    LinkList cur = L->next;
    int count = 1;
    while(cur){
        if(cur->data == elem){
            return count;
        }
        cur = cur->next;
        count ++;
    }

    return -1;
}
