#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string sentence[n];
    for(int i=0;i<n;i++)
        getline(cin,sentence[i]);

    int index[n];
    int shortest_i=0;
    int shortest=300;
    for(int i=0;i<n;i++)
    {
        int len = sentence[i].size();
        index[i] =  len - 1;
        if(len<shortest)
        {
            shortest = len;
            shortest_i = i;
        }
    }

    char suffix[257];
    
    int j=0;
    while(j++<shortest_i)
    {
        char c = sentence[0][index[0]--];
        for(int i=1;i<n;i++)
        {
            if(sentence[i][index[i]--] != c)
                break;
        }
    }

    strcpy(suffix , &(sentence[0][index[0]+1]));
    if(strlen(suffix) == 0)
        printf("nai");
    else
        printf("%s",suffix);

    return 0;
}
