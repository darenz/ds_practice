#include<iostream>
using namespace std;

typedef struct TreeNode
{
    int data;
    TreeNode *lchild,*rchild;
} TreeNode,*Tree;

int PreOrder[7] = {1,2,4,4,6,7,3};
int InOrder[7] = {4,2,6,4,7,1,3};
#define SIZE 7

Tree BiTree(int a,int b,int pi)
{
    if(a<b)
        return NULL;
    Tree p = new TreeNode();
    p->data = PreOrder[pi];
    int i;
    for(i=a;i<=b;i++)
    {
        if(InOrder[i]==PreOrder[pi]) break;
    }
    p->lchild = BiTree(a,i-1,++pi);
    //if(*pi!=InOrder+SIZE-1)
    p->rchild = BiTree(i+1,b,++pi);
    return p;
}

void Pre(Tree T)
{
    if(T)
    {
        cout<<T->data;
        Pre(T->lchild);
        Pre(T->rchild);
    }
}

int main()
{
    Tree T;
    T = BiTree(0,SIZE-1,0);
    Pre(T);
}


