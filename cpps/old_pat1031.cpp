#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    char s[81];
    scanf("%s",s);
    int length = strlen(s);
    int n = (length + 2)/3;
    int l = length - 2*(n-1) ;
    int n_space = l - 2;
    int i=0,j=length - 1;
    for(int k=0;k<n-1;k++)
    {
        printf("%c",s[i++]);
        for(int m=0;m<n_space;m++)
            printf(" ");
        printf("%c\n",s[j--]);
    }
    for(int k=0;k<l;k++)
        printf("%c",s[i++]);
    printf("\n");

    return 0;
}
