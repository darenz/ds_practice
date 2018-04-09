#include<iostream>
#include"SqStack.hpp"
#include<string.h>
using namespace std;

#define IS_NUMBER 1
#define IS_OPERATOR 2
#define ERRO 0

int judgeExpress(char c,int* p);
int doCaculation(int a,int b,int get);


int judgeExpress(char c,int* p)
{
    if(c>='0' && c<='9')
    {
        *p = c-'0';
        return IS_NUMBER;
    }
    else if(c=='+' || c=='-' || c=='*' || c=='/')
    {
        *p = c;
        return IS_OPERATOR;
    }
    else return ERRO;
}

int doCaculation(int a,int b,int get)
{
    switch(get) 
    {
            case '+': 
                return a+b;
            case '-':
                return a-b;
            case '*':
                return a*b;
            case '/':
                if(b==0)
                {
                    cout<<"/0 is input!"<<endl;
                    exit(0);
                }
                return a/b;
    }
}

int main()
{
    SqStack<int> stack(20);
    char s[20]={};
    cin>>s;
    char* pc = s;
    int flag;
    int get;
    int n = strlen(s);
    for(int i=0;i<n;i++)
    {
        flag = judgeExpress(*pc,&get);
        if(flag == IS_NUMBER)
            stack.push(get);
        else if(flag == IS_OPERATOR)
        {
            if(stack.getLength()<2)
            {
                cout<<"expression erro"<<endl;
                return ERRO;
            }
            int a,b;
            stack.pop(b);
            stack.pop(a);
            int c = doCaculation(a,b,get);
            if(stack.isEmpty())
            {
                cout<<c;
                return 0;
            }
            stack.push(c);
        }
        else
        {
            cout<<"expression erro"<<endl;
            return ERRO;
        }
    }

}
