#include<iostream>
#include<limits.h>
using namespace std;

typedef struct node
{
    int elem;
    struct node * next;
    struct node * before;
} * Node;

Node add(Node pa,int a,Node pb,int b);

int main()
{
    Node pa = new node;
    pa->next = NULL;
    pa->before = NULL;
    Node pb = new node;
    pb->next = NULL;
    pb->before = NULL;

    Node pal=pa;
    Node pbl=pb;

    string sa,sb;
    cin>>sa>>sb;

    if(sa[0] == '-')
        pal->elem = -1;
    else
        pal->elem = sa[0] - '0';
    for(int i=1;i<sa.size();i++)
    {
        pal->next = new node;
        pal->next->before = pal;
        pal = pal->next;
        pal->elem = (int)sa[i]-(int)'0';
        pal->next = NULL;
    }

    if(sb[0] == '-')
        pbl->elem = -1;
    else
        pbl->elem = sb[0] - '0';
    for(int i=1;i<sb.size();i++)
    {
        pbl->next = new node;
        pbl->next->before = pbl;
        pbl = pbl->next;
        pbl->elem = (int)sb[i]-(int)'0';
    }
     
    for(Node p = pa;p;p=p->next)
        cout<<p->elem;
    cout<<endl;
    for(Node p = pb;p;p=p->next)
        cout<<p->elem;

    Node rp = add(pal,pa->elem,pbl,pb->elem);

    for(Node p=rp;p->next;p=p->next)
    {
        if(p->elem >= 10)
            cout<<'-';
        else 
            cout<<p->elem;
    }
    return 0;
}

Node add(Node pal,int a,Node pbl,int b)
{
    int c=0;
    Node rp = new node;
    rp->next = NULL;
    rp->before = NULL;

    Node pt = rp;
    if(a>=0 && b>=0)
    {
        while(pal->before && pbl->before)
        {
            pt->next = new node;
            pt->next->before = pt;
            pt->next->next = NULL;
            pt = pt->next;
            pt->elem = (c + pal->elem+pbl->elem)%10;
            c = (pal->elem+pbl->elem)/10;
        }
        if(pal->before)
        {
            while(pal->before)
            {
                pt->next = new node;
                pt->next->before = pt;
                pt->next->next = NULL;
                pt=pt->next;

                pt->elem = (c + pal->elem)%10;
                c = (c + pal->elem)/10;
            }
            if(c)
            {
                pt->next = new node;
                pt->next->before = pt;
                pt->next->next = NULL;
                pt=pt->next;

                pt->elem = c;
            }
        }
        if(pbl->before)
        {
            while(pbl->before)
            {
                pt->next = new node;
                pt->next->before = pt;
                pt->next->next = NULL;
                pt=pt->next;

                pt->elem = (c + pbl->elem)%10;
                c = (c + pbl->elem)/10;
            }
            if(c)
            {
                pt->next = new node;
                pt->next->before = pt;
                pt->next->next = NULL;
                pt=pt->next;

                pt->elem = c;
            }
        }

    }
    return pt;
}
