#include<iostream>

using namespace std;

#define OK 1
#define ERRO 0
typedef bool Status;

template<typename t>
class Node
{
    public:
        Node()
        {
            Lchild = NULL;
            Rchild = NULL;
        }
        Node(t val)
        {
            this->val = val;
            Lchild = NULL;
            Rchild = NULL;
        }
        ~Node()
        {
            delete this;
        }
        t val;
        Node* Lchild;
        Node* Rchild;
};

template<typename t>
class BiTree
{
        typedef Node<t>* NodePointer;
    public:
        NodePointer search(NodePointer parent,t k);
        Status deleteElem(t k);
        NodePointer insert(t k);

        void read(t array[],int n);
        void showDLR();
        void showLDR();
        void showLRD();
        BiTree();

    private:
        NodePointer root;

        void DLR(Node<t>* p);
        void LDR(Node<t>* p);
        void LRD(Node<t>* p);
};

template<typename t>
BiTree<t>::BiTree()
{
    root = NULL;
}

template<typename t>
Status BiTree<t>::deleteElem(t k)
{
    NodePointer parent = root;
    NodePointer p = locate(parent,k);
    if(p == NULL)
        return 0;
    if(parent->Lchild == p)
    {
        if(p->Rchild == NULL)
        {
            parent->Lchild = p->Lchild;
            delete p;
        }
        else if(p->Lchild == NULL)
        {
            parent->Lchild = p->Rchild;
            delete p;
        }
        else
        {
            NodePointer pLL_parent = p;
            NodePointer pLL = p;
            while(pLL->Rchild) //左子树最右边节点，最大节点(或右子树最左节点)
            {
                pLL_parent = pLL; //parent
                pLL = pLL->Rchild;
            }
            pLL_parent->Rchild = NULL;
            parent->Lchild = pLL;
            pLL->Lchild = p->Lchild;
            pLL->Rchild = p->Rchild;
            delete p;
        }
    }
    else if(parent->Rchild == p)
    {
        if(p->Rchild == NULL)
        {
            parent->Rchild = p->Lchild;
            delete p;
        }
        else if(p->Lchild == NULL)
        {
            parent->Rchild = p->Rchild;
            delete p;
        }
        else 
        {
            NodePointer pLL_parent = p;
            NodePointer pLL = p;
            while(pLL->Rchild) //左子树最右边节点，最大节点(或右子树最左节点)
            {
                pLL_parent = pLL; //parent
                pLL = pLL->Rchild;
            }
            pLL_parent->Rchild = NULL;
            parent->Rchild = pLL;
            pLL->Lchild = p->Lchild;
            pLL->Rchild = p->Rchild;
            delete p;
        }
    }
    return 1;
}

template<typename t>
Node<t>* BiTree<t>::insert(t k)
{
    //普通二叉树插入位置都是叶子节点
    NodePointer parent = root;
    if(root == NULL)
    {
        root = new Node<t>(k);
        return root;
    }
    NodePointer p = search(parent,k);
    if(p)
    {
        cout<<"already exist"<<endl;
        return NULL;
    }
    p = root;
    while(p)
    {
        if(k < p->val) 
        {
            parent = p; 
            p = p->Lchild;
        }
        else if(p->val < k)
        {
            parent = p;
            p = p->Rchild;
        }
    }
    if(k < parent->val) 
    {
        parent->Lchild = new Node<t>(k);
        return parent->Lchild;
    }
    else if(parent->val < k)
    {
        parent->Rchild = new Node<t>(k);
        return parent->Rchild;
    }
    return NULL;
}

template<typename t>
void BiTree<t>::read(t array[],int n)
{
    for(int i=0;i<n;i++)
        insert(array[i]); 
}

template<typename t>
Node<t>* BiTree<t>::search(NodePointer parent,t k)
{
    //三个指针都作为返回值，parent既是输入也是返回
    //非递归
    if(parent == NULL)
        return NULL;
    NodePointer p = parent;
    if(parent->val > k)
        p = parent->Lchild;
    else if(parent->val < k)
        p = parent->Rchild;
    while(p)
    {
        if(p->val==k) //包含根节点为查找节点
            return p;
        else if(k < p->val)
        {
            parent = p;
            p = p->Lchild;
        }
        else if(p->val < k)
        {
            parent = p;
            p = p->Rchild;
        }
    }
    return NULL;
}

template<typename t>
void BiTree<t>::showDLR()
{
    //先序遍历：先输出自己，再输出左，再输出右。（递归定义）
    //非递归用栈储存：储存非叶子节点
    //
    //递归算法：
    DLR(root); 
}

template<typename t>
void BiTree<t>::DLR(Node<t>* p)
{
    if(p == NULL)
        return;
    cout<<p->val<<" ";
    DLR(p->Lchild);
    DLR(p->Rchild);
}

template<typename t>
void BiTree<t>::showLDR()
{
    LDR(root);
}

template<typename t>
void BiTree<t>::LDR(Node<t>* p)
{
    if(p == NULL)
        return;
    LDR(p->Lchild);
    cout<<p->val<<" ";
    LDR(p->Rchild);
}


template<typename t>
void BiTree<t>::showLRD()
{
    LRD(root);
}

template<typename t>
void BiTree<t>::LRD(Node<t>* p)
{
    if(p == NULL)
        return;
    LRD(p->Lchild);
    LRD(p->Rchild);
    cout<<p->val<<" ";
}


