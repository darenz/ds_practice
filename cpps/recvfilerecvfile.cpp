#include<iostream>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
#include<string>
#include"recvfile.hpp"
using namespace std;

int serverInitAccept(int port)
{
    int socket_listen = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in s_addr;
    s_addr.sin_family = AF_INET;
    s_addr.sin_port = port;
    s_addr.sin_addr.s_addr = 0;
    int b_flag = bind(socket_listen,(struct sockaddr*)&s_addr,sizeof(sockaddr));
    if(b_flag==0)
        cout<<"connecting"<<endl;
    int l_flag = listen(socket_listen,128);
    if(l_flag!=-1)
        cout<<"connected"<<endl;
    return l_flag;
}

int fileRecv(int socket,const char* path)
{
    char temp[1024];
    int n = 0;
    FILE* file = fopen(path,"wb+");
    while((n=recv(socket,temp,1024,0)))
    {
        fwrite(temp,sizeof(char),n,file);
    }
    fclose(file);
    return 0;
}

int main()
{
    int socket = serverInitAccept(8888);
    if(socket==-1)
    {
        cout<<"disconnected"<<endl;
        exit(0);
    }
    string path = "test.cpp";
    fileRecv(socket,path.c_str());
}
