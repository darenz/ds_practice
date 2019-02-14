#include<iostream>

using namespace std;

#define MAXSIZE 10
typedef struct stack
{
    char data[MAXSIZE];
    int top; 
} stack;

void InitStack(stack &s)
{
    s.top = 0;
}

int isEmpty(stack &s)
{
    if(s.top == 0) return 1;
    return 0;
}

int isFull(stack &s)
{
    if(s.top == MAXSIZE) return 1;
    return 0;
}

int push(stack &s,char c)
{
    if(!isFull(s))
    {
        s.data[s.top++] = c;
        return 1;
    }
    return 0;
}

char pop(stack &s)
{
    if(!isEmpty(s))
        return s.data[--s.top];
    return 0;
}

char top(stack &s)
{
    if(isEmpty(s))
        return 0;
    return s.data[s.top-1];
}

int main()
{
    stack s;
    InitStack(s);
    string str;
    cin>>str;
    char eger=0;
    for(int i=0;i<str.size();i++)
    {   
        if(str[i] == top(s))
            pop(s);
        else
        {
            switch(str[i])
            {
                case '(' :
                    eger = ')';
                    break;
                case '[' :
                    eger = ']';
                    break;
                case '{' :
                    eger = '}';
                    break;
                default :
                    break;
            }
            push(s,eger);
        }            
    }
    if(isEmpty(s)) 
        cout<<"OK"<<endl;
    else
        cout<<"BAD"<<endl;
    return 0;
}
