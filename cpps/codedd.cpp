#include<iostream>
using namespace std;

int main()
{
    int a = 0x11223344;
    int* pa = &a;
    char* pc;
    pc = (char*)pa;
    for(int i=0;i<4;i++)
        cout<<hex<<(int)*(pc++)<<endl;
}
