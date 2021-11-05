#include<stdio.h>
#include<stdlib.h>

#define TElemType char
#define Status int
#define ERROR -1

/*
二叉树的链表存储

需要实现的函数有
1.构造
2.先序遍历
3.中序遍历
4.后序遍历
5.层序遍历
*/

typedef struct BiTNode{
    TElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

Status CreatBiTree(BiTree &T);
Status PreOrderTraverse(BiTree &T);
int main()
{
    BiTree tr;
    CreatBiTree(tr);
    PreOrderTraverse(tr);

    return 0;
}


Status CreatBiTree(BiTree &T)
{
    TElemType tmp;
    scanf("%c",&tmp);
    if(tmp=='#'){
        T=NULL;
        return -1;
    }else{
        T = (BiTree)malloc(sizeof(BiTNode));
        T->data = tmp;

        CreatBiTree(T->lchild);
        CreatBiTree(T->rchild);

    }

    return 1;


}

Status PreOrderTraverse(BiTree &T)
{
    if(T==NULL) return ERROR;
    printf("%c",T->data);

    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);

    return 1;
}

