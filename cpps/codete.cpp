#include<iostream>
#include<stdlib.h>
#include"te.h"
using namespace std;

//头文件中定义，但不实现，不会报错
int afunc()
{
    cout<<endl;
    return 0;
}


// stdlib.h ，调用system执行外部命令,要获得输出只能到文件，再读文件 
// 获得输出可以直接用popen 
int main()
{
   // system("pwd >t.txt");
    FILE* fp;    afunc();
    if((fp = popen("ip addr | grep 192","r"))==NULL)
        return 1;
    char s[100];
    while(fgets(s,100,fp));
    cout<<s<<endl;
}
