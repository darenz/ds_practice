#include<iostream>
using namespace std;

#define MaxSize 5 

typedef struct queue
{
    int data[MaxSize];
    int front,rear;
} Queue;

bool InitQueue(queue &Q)
{
    Q.front = 0;
    Q.rear = 0;
    for(int i=0;i<MaxSize;i++)
        Q.data[i] = -1;
    return true;
}

bool IsEmpty(queue &Q)
{
    if(Q.front == Q.rear)
        return true;
    return false;
}

bool IsFull(queue &Q)
{
    if((Q.rear+1)%MaxSize==Q.front)
        return true;
    return false;
}

bool EnQueue(queue &Q,int e) 
{
    if(IsFull(Q))
        return false;
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear+1)%MaxSize;
    return true;
}

bool DeQueue(queue &Q,int &e)
{
    if(IsEmpty(Q))
        return false;
    e = Q.data[Q.front];
    Q.data[Q.front] = 0;
    Q.front = (Q.front+1)%MaxSize;
    return true;
}

int GetHead(queue &Q)
{
    return Q.data[Q.front];
}

int main()
{
    Queue Q;
    InitQueue(Q);
    while(1)
    {
        
        for(int i=0;i<MaxSize;i++)
            cout<<Q.data[i];
        cout<<endl;
        cout<<"1.enqueue 2.dequeue"<<endl;
        int choice;
        cin>>choice;
        if(choice == 1)
        {
            int n;
            cin>>n;
            EnQueue(Q,n);
        }
        else if(choice == 2)
        {
            int e;
            DeQueue(Q,e);
        }
        else return 0;
    }
}
