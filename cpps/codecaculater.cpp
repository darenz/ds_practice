#include<iostream>
#include<sstream>
#include<iomanip>
using namespace std;
void spilt(float* a,char* op,char* input);

void spilt(float* a,char* op,char* input)
{
    char* p = input;
    string st[2];
    char s[2] = {};
    for(int i=0;i<2;i++)
    {
        while(1)
        {
            if((*p)!='+' && (*p)!='-' &&  (*p)!='*' && (*p)!='/' && (*p)!='\0')
            {
                s[0] = *p;
                st[i].append(s);
                p++;
            }
            else
            {
                stringstream ss;
                ss.str(st[i]);
                ss>>a[i]; 
                if(*p!='\0')
                    *op = *p;
                p++;
                break;
            }
        }
    }
    return;
}

int main()
{
    char input[20] = {};
    float a[2];
    char op;
    float r;

    while(1)
    {
    cout<<"input a expression"<<endl;
    cin>>input;
    spilt(a,&op,input);
    switch(op)
    {
        case '+':
            r = a[0]+a[1];
            break;
        case '-':
            r = a[0]-a[1];
            break;
        case '*':
            r = a[0]*a[1];
            break;
        case '/':
            r = a[0]/a[1];
            break;
        default:
            cout<<"input erro"<<endl;
            break;
    }
    cout.setf(ios::fixed);
    cout<<setprecision(4)<<r<<endl;
    }
    
}
