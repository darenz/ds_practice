#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

class A
{
    public:

        int a,b;
        string name;

    void func()
    {
        cout<<"hello~!"<<endl;
        cout<<name<<endl;
        cout<<a<<' '<<b<<endl;

    }

};

int main()
{
    A a;
    a.a = 1;
    a.b = 2;
    a.name = "lalaldemaxiya";
    char buf[100];
    memset(buf,0,100);
     
    memcpy(buf,&a,sizeof(a));
    for(int i=0;i<100;i++) 
    {
        printf("%c ",buf[i]);
    }
    cout<<endl;
    A b;
    memcpy(&b,&a,sizeof(a));
    b.func();
}
