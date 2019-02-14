#include<iostream>

using namespace std;

//结构体的定义和使用
typedef struct lnode
{
    int data;
    lnode* next;
} *LinkList;

void ListInit(LinkList &L) //正确
{
    L = new lnode();
    L->data = 0;
    L->next = NULL;
    return ;
}

LinkList ListInit()
{
    LinkList L = new lnode();
    L->data = 0;
    L->next = NULL;
    return L;  //new之后得到的地址要专门返回。
                // LinstInit(LinkList L)
                // {
                //      L = new lnode();
                // }
                // 这样函数外的L仍未被赋值。
                // 原因：参数L传进来的只是L的副本，二者值相等。
                // 要返回改变的参数的值需要传递参数*本身*的引用或指针。
                // LinkList(LinkList &L);
}

void ListAdd(LinkList L,int e)
{
    LinkList p = new lnode();
    p->data = e;
    p->next = L->next;
    L->next = p;
}

int main()
{
    LinkList L;
//    L = ListInit();
    ListInit(L);
    ListAdd(L,1);
    cout<<L->next->data<<endl;
    return 0;
}

