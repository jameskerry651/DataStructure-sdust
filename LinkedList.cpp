#include<stdio.h>
#include<stdlib.h>

#define ERROR -1
#define OK 1
/**
��̬������Ҫ��ɵ�����
1.������̬����   Creat_Llist
2.����ĳ��Ԫ��    Locate_elem
3.����λ�ò���һ���ڵ�  Insert_Llist
4.ɾ��ĳ���ڵ�            delet_Llist
5.��������е�����Ԫ��  print_Llist
6.���ղ��ݼ���˳�����Ԫ�ص�������ȥ insert_sort_list
7.��ȡ������  getLength
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
Status insert_sort_list(LinkList &L,int num);
int getLength(LinkList &L);
Status delet_Llist(LinkList &L,int pos);
int Locate_elem(LinkList &L,ElemType elem);      //��������򷵻�λ�ã��������򷵻�-1


//������
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
    //Ѱ�ҵ�pos-1���ڵ��Ƿ����
    while(p && i<pos-1){
        p = p->next;
        i++;
    }
    if(!p) return ERROR;
    //��ʱ���p���ڣ���ôһ��ָ�����λ�õ�ǰһ��
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
    //����һ��ʼ������Ϊ�յ��������
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

    // �����е����ֶ����β�����һ��
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
    // ע�ⵥ��ɾ���򵥣����������ɾ����ǰ���ڵ��λ�ò�����£�ֱ��û��ɾ����ǰ�ƶ�
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
