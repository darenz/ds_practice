#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int* BuildNext(char* P)
{
    int *next = (int*)malloc(sizeof(int)*strlen(P));
    if(next==NULL)
        return 0;
    next[0] = -1;
    int i = 0; 
    int j = -1;
    while(i<strlen(P))
    {
        if(0>j || P[i]==P[j])
            next[++i] = ++j; //i必须从0开始，否则无法计算next[1] 
    }
        else
            j = next[j];
    }
    return next;
}

int main()
{
    char s[10];
    scanf("%s",s);
    int* next = BuildNext(s);
    if(next == 0)
        return 1;
    int i;
    for(i=0;i<strlen(s);i++)
    {
        printf("%d ",next[i]);
    }
    free(next);
    return 0;
}
