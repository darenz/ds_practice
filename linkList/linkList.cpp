#include "linkList.hpp"
#include <iostream>
using namespace std;

template<typename ElemType>
LinkList<ElemType>::LinkList()
{
    head = new LinkNode;
    head->data = 0;
    head->next = NULL;
    length = 0;
}

template<typename ElemType>
LinkList<ElemType>::~LinkList()
{
    clear();
    delete head;
}

template<typename ElemType>
LinkList<ElemType>::LinkList(LinkList<ElemType> &otherL)
{
    NodePointer pthis = head->next;
    NodePointer pt = head;
    NodePointer pother = otherL.head->next;
    while(pother!=NULL)
    {
        pthis = new ListNode;
        pthis->next= NULL;
        pthis->elem = pother->elem;
        pt->next = pthis;
        pt = pthis;
        pother = pother->next;
        length++;
}

template<typename ElemType>
Status LinkList<ElemType>::insert(int i,ElemType<ElemType> e)
{
    if(i<1 || i>length+1 || length==0)
    {
        cout<<"index erro"<<endl;
        return ERRO;
    }
    int j=0;
    NodePointer p=head;
    while(j!=i-1)
    {
        p = p->next;
        j++;
    }
    NodePointer newp = new ListNode;
    newp->elem = e; 
    newp->next = p->next;
    p->next = newp;
    return OK;
}

template<typename ElemType>
Status LinkList<ElemType>::deleteElem(ElemType<ElemType> e)
{
    NodePionter p = head;
    while(p!=NULL)
    {
        if(p->next->elem == e)
        {
            NodePionter pt = p->next;
            p->next = pt->next;
            delete pt;
            return OK;
        }
        p = p->next;
    }
    return OK;
}

template<typename ElemType>
Status LinkList<ElemType>::clear()
{
    NodePointer p = head->next;
    NodePointer q = p->next;
    while(q->next!=NULL)
    {
        delete p;
        p = q;
        q = q->next;
    }
    delete p;
    delete q;
    length = 0
    head->next = NULL;
    return OK;
}

template<typename ElemType>
int LinkList<ElemType>::getLength()
{
    return length;
}

template<typename ElemType>
NodePointer LinkList<ElemType>::getHead()
{
    return head;
}

template<typename ElemType>
Status LinkList<ElemType>::showList()
{
    NodePointer p = head->next;
    while(p)
    {
        cout<<p->elem<<' ';
        p = p->next;
    }
    return OK;
}

template<typename ElemType>
Status LinkList<ElemType>::append(ElemType<ElemType> e)
{
    NodePointer p = new ListNode;
    p->elem = e;
    p->next = head->next;
    head->next = p;
    return OK;
}
