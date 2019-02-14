#include<iostream>
#include<unistd.h>
#include<stdlib.h>

using namespace std;
int main()
{
    int father_pid = getpid();
    pid_t new_flag = fork();
    if(new_flag==0)
        cout<<"子进程创建成功"<<endl;
    else if(new_flag<0)
        cout<<"创建失败"<<endl;
    {
        if(getpid()==father_pid)
            cout<<"father"<<endl;
        else 
            cout<<"child "<<getpid()<<endl;
    }
}
