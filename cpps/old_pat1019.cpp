#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main()
{
    int N,b;
    scanf("%d %d",&N,&b);
    vector<int> num_b;
    int t;
    while(N)
    {
        t = N%b;
        num_b.push_back(t);
        N = N/b;
    }
//    for(int i=0;i<num_b.size();i++)
//        printf("%d ",num_b[i]);
//


    int count_space = num_b.size()-1;
    int i=0,j=num_b.size()-1;
    while(i<j)
    {
        if(num_b[i] != num_b[j])
            break;
        i++;
        j--;
    }
    if(i<j)
        printf("No\n");
    else
        printf("Yes\n");
    for(int k=num_b.size()-1;k>=0;k--)
    {
        printf("%d",num_b[k]);
        if(count_space--)
        printf(" ");
    }
    return 0;
}
