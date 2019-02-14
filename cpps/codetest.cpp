#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string>
#include<strings.h>
#include<string.h>
using namespace std;
int main()
{
//    int sockfd1 = socket(AF_INET,SOCK_STREAM,0);
//    cout<<sockfd1<<endl;
//    int sockfd2 = socket(AF_INET,SOCK_STREAM,0);
//    cout<<sockfd2<<endl;
//    return 0; 

    struct{
          int len;
          int p[];
    } a;
    a.len=0;
    for(int i=0;i<10;i++)
    {
        a.p[i]=i;
        a.len++;
    }
    cout<<a.len<<endl;
    return 0;
}
