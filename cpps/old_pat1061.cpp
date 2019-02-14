#include<iostream>
#include<string>
#include<cstring>
using namespace std;

bool isLowcase(char c);
bool isLargecase(char c);

int main()
{
    char s[4][61];
    scanf("%s %s %s %s",&s[0],&s[1],&s[2],&s[3]);

    int length[4];
    for(int i=0;i<4;i++)
        length[i] = strlen(s[i]);

    char* Days[7] = 
    {
        "MON","TUE","WED","THU","FRI","SAT","SUN"
    };

    char dd[4]={};
    int hh,mm;
    int i;
    i=0;

    while(i<length[0] && i<length[1])
    {
        if(s[0][i] == s[1][i])
        {
            if(s[0][i]>='A' && s[0][i]<='G')//不是A～Z
            {
                strcpy(dd,Days[(s[0][i] - 'A')]); 
                    break;
            }
        }
        i++;
    }
    i++;//important
    while(i<length[0] && i<length[1])
    {
        if(s[0][i] == s[1][i])
        {
            if(s[0][i]>='0' && s[0][i]<='9')
            {
                hh = s[0][i] - '0';
                break;
            } 
            else if(s[0][i]>='A' && s[0][i]<='N') //不是A～Z。限定A～N
            {
                hh = s[0][i] - 'A' + 10;
                break;
            }
        } 
        i++;
    }
        
    i=0; 
    while(i<length[2] )
    {
        if(s[2][i] == s[3][i])
        {
            if(isLowcase(s[2][i]) || isLargecase(s[2][i]))
            {
                mm = i;
                break;
            }
        }
        i++;
    }
    printf("%s %02d:%02d",dd,hh,mm);

    return 0;
}

bool isLowcase(char c)
{
    if(c>='a' && c<='z')
        return true;
    else
        return false;
}

bool isLargecase(char c)
{
    if(c>='A' && c<='Z')
        return true;
    else
        return false;
}
