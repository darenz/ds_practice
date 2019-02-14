#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>

using namespace std;

void bsf(int start);
vector<int> vhst;

int count;
int hst;
int N;
float P,r;
vector<vector<int>> graph;
vector<int> path;

class Queue
{
    public:
        Queue();
        void InQue(int a);
        int DeQue();
        bool IsEmpty();
        bool IsFull();

    private:
        vector<int> data;
        int len;
        int front,rear;
       
};

Queue::Queue()
{
    len = 0;
    front = 0;
    rear = 0;
}

void Queue::InQue(int a)
{
    if(IsFull()) 
        data.resize(1+len+len/2,0);
    data[rear] = a;
    rear = (rear+1)%n;
    len++;
}

int Queue::DeQue()
{
    int a=-1;
    if(!IsEmpty())
    {
        a = data[front];
        front = (front+1)%n;
        len--;
    }
    return a;
}

bool Queue::IsFull()
{
    if((rear+1)%n == front )
        return true;
    else 
        return false;
}

bool Queue::IsEmpty()
{
    if((front == rear))
        return true;
    else
        return false;
}

int main()
{
    cin>>N>>P>>r;
    graph.resize(N,vector<int>(N,0));
    int start;
    for(int i=0;i<N;i++)
    {
        int n;
        cin>>n;
        if(n==-1)   start = i;
        else 
            graph[n][i] = 1;
    }

    bsf(start);
    float hstPrice = P*pow((1+r/100),hst); //考虑长度是否减一
    cout<<fixed<<setprecision(2)<<hstPrice<<" "; //setprecision 设置有效位数，加上fixed为小数点后有效位数,头文件iomanip
    cout<<count;
     
    return 0;
}

void bsf(int start)
{
    Queue Q();
    vector<int> depth(N,0);
    vector<bool> visited(N,false);
    Q.InQue(start);

    int index;
    int cdeep=0;
    while(!Q.IsEmpty())
    {
        index = Q.DeQue();
        visited[index] = true;
        cdeep = depth[index];
        if(cdeep>hst) 
        {
            hst = cdeep;
            count = 1;
        }
        else if(cdeep==hst)
            count++;
        for(int i=0;i<N;i++)    
        {
            if(graph[index][i] ) 
            {
                if(visited[i])
                {
                    if(depth[i] < cdeep+1)
                    {
                        depth[i] = cdeep+1;
                        Q.InQue(i);
                    }
                }
                else
                {
                    Q.InQue(i);
                    depth[i] = cdeep+1;
                }
            }
        }
    }
    return;
}
