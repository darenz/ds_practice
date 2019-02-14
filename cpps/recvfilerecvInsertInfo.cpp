#include<iostream>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include"recvfile.hpp"
#include<string.h>
using namespace std;

int serverInitAccept(int port)
{
    int socket_listen = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in s_addr;
    s_addr.sin_family = AF_INET;
    s_addr.sin_port = htons(port);
    s_addr.sin_addr.s_addr = 0;
    bind(socket_listen,(struct sockaddr*)&s_addr,sizeof(sockaddr));
    int l_flag = listen(socket_listen,128);
    if(l_flag!=-1)
        cout<<"listen flag:"<<l_flag<<endl;
    struct sockaddr re_addr;
    socklen_t re_len;
    int new_fd = accept(socket_listen,&re_addr,&re_len);
    cout<<"accept socket:"<<new_fd<<endl;
    if(new_fd>0)
        return new_fd;
    else 
        return 0;
}

int fileRecv(int socket,const char* path,string& name,string& id)
{
    char temp[1024];
    int n = 0;
    FILE* file = fopen(path,"wb+");
    while((n=recv(socket,temp,1024,0)))
    {
        fwrite(temp,sizeof(char),n,file);
    }
    fclose(file);
    char name_temp[50];
    char id_temp[50];
    memset(name_temp,0,50);
    memset(id_temp,0,50);
    recv(socket,name_temp,50,0);
    recv(socket,id_temp,50,0);
    name =  name_temp;
    id = id_temp;
    return 0;
}

int main()
{
    int socket_s = serverInitAccept(8000);
    if(socket_s==-1)
    {
        cout<<"disconnected"<<endl;
        exit(0);
    }
    string path = "insert.jpg";
    string name,id;
    fileRecv(socket_s,path.c_str(),name,id);
     
    int socket_info = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in d_addr;
    d_addr.sin_family = AF_INET;
    d_addr.sin_port = htons(8001);
    d_addr.sin_addr.s_addr = 0;
    int c_flag = connect(socket_info,(struct sockaddr*)&d_addr,sizeof(struct sockaddr));
    if(c_flag == 0)
    {
        char path_c[50];
        char name_c[50];
        char id_c[50];
        strcpy(path_c,path.c_str());
        strcpy(name_c,name.c_str());
        strcpy(id_c,id.c_str());

        send(socket_info,path_c,strlen(path_c),0);
        send(socket_info,name_c,strlen(name_c),0);
        send(socket_info,id_c,strlen(id_c),0);
        int status;
        recv(socket_info,&status,sizeof(int),0);
        send(socket_s,&status,sizeof(status),0);
        /*
        if(status == 1)//ok
        {
            send(socket_s,&status,sizeof(status),0);
        }
        else//erro
        {
            send(socket_s,&status,sizeof(status),0);
        }
        */
        close(socket_info);
    }
}
