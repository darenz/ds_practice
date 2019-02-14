#include<iostream>
#include<vector>
#include<queue>
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
    queue<int> q;
    vector<int> depth(N,0);
    vector<bool> visited(N,false);
    q.push(start);

    int index;
    int cdeep=0;
    while(!q.empty())
    {
        index = q.front();
        q.pop();
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
                        q.push(i);
                    }
                    
                }
                else
                {
                    q.push(i);
                    depth[i] = cdeep+1;
                }
            }
        }
    }
    return;
}

