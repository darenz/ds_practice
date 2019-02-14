#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void dfs(int start,int end,int index);

int cmax,N,sp,M;
vector<vector<int>> graph;
vector<int> path;
vector<int> resultpath;
vector<bool> visited;
vector<int> current;

int costTimes;
int resultCost = INT_MAX;
int outBikes,resultOutBikes;
int inBikes,resultInBikes;

int main()
{
    cin>>cmax>>N>>sp>>M;
    current.resize(N+1,0);
    graph.resize(N+1,vector<int>(N+1,0));
    visited.resize(N+1,false);
    
    for(int i=1;i<N+1;i++)
        cin>>current[i];
    for(int i=0;i<M;i++)
    {
        int n,m,cost;
        cin>>n>>m>>cost;
        graph[n][m] = cost;
        graph[m][n] = cost;
    }

    dfs(0,sp,0);
    
    cout<<resultOutBikes<<' ';
    cout<<'0';
    for(int i=1;i<resultpath.size();i++)
        cout<<"->"<<resultpath[i];
    cout<<" "<<resultInBikes;
    return 0;
}

void dfs(int start,int end,int index)
{
    visited[index] = true;
    path.push_back(index);
    costTimes += graph[start][index];

    if(index == end) 
    {
        inBikes = 0 ;
        outBikes = 0;
        for(int i=1;i<path.size();i++) //需要使用序号，从1开始.
        {
            if(current[path[i]]>cmax/2)
                inBikes += current[path[i]] - cmax/2;
            else if(inBikes < (cmax/2-current[path[i]]))
            {//重要思想
                outBikes += cmax/2-current[path[i]]-inBikes; //开始忘了减inBikes;
                inBikes = 0 ; 
            }
            else 
            {
               inBikes -= cmax/2-current[path[i]]; 
            }
        }

        if(costTimes<resultCost) //#
        {
            resultCost = costTimes;
            resultInBikes = inBikes;
            resultOutBikes = outBikes;
            resultpath = path;
        }
        else if( costTimes == resultCost )   
        {
            if(outBikes<resultOutBikes)
            {
                resultInBikes = inBikes;
                resultOutBikes = outBikes;
                resultpath = path;
            }
            else if(outBikes==resultOutBikes && inBikes<resultInBikes)
            {
                resultInBikes = inBikes;
                resultOutBikes = outBikes;
                resultpath = path;
            }
        }
    }
    else
    {
        for(int i=1;i<N+1;i++)
        {
            if(graph[index][i] && !visited[i])
            {
                dfs(index,end,i);
            }
        }
    }
    
    visited[index] = false;
    path.pop_back();
    costTimes -= graph[start][index];
}
