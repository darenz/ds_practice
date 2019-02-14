#include<iostream>
#include<vector>

using namespace std;

vector<vector<vector<bool>>> graph;
vector<vector<vector<bool>>> visited;
int M,N,L,T;

int main()
{
    cin>>M>>N>>L>>T;
    graph.resize(L,vector<vector<bool>>(M,vector<bool>(N,0)));
    visited.resize(L,vector<vector<bool>>(M,vector<bool>(N,0)));

}
