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

in_addr_t convert(string s);

int main()
{
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    //struct sockaddr_in myaddr;
    //myaddr.sin_family = AF_INET;
    //myaddr.sin_port = htons(0);
    //myaddr.sin_addr.s_addr = 0;//inet_addr("139.199.2.139");
    //int flag = bind(sockfd,(struct sockaddr*)&myaddr,sizeof(struct sockaddr));
    //cout<<flag<<endl;

    struct sockaddr_in dest_addr;
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(8888);
    dest_addr.sin_addr.s_addr = inet_addr("139.199.2.139");
    int c_flag = connect(sockfd,(struct sockaddr*)&dest_addr,sizeof(struct sockaddr));
    cout<<"connection flag: "<<c_flag<<endl; 
    if(!c_flag)
    {
        char s[] = "that's weried";
        int s_flag = send(sockfd,s,strlen(s),0);
        cout<<"strlen:"<<strlen(s)<<endl;
        cout<<"send flag:"<<s_flag<<endl;
        unsigned char buffer[10]={'1','2','3','4'};
        int w_flag = write(sockfd,(void*)buffer,10);
        cout<<w_flag<<endl;
    }
    close(sockfd);
    return 0;
}

in_addr_t convert(string s)
{
    int t=0;
    uint32_t addr=0; 
    cout<<addr<<endl;
    for(uint i=0;i<s.length();i++)
    {
        if(s[i]!='.')
        {
            t = t*10 + s[i]-'0';
        }
        else
        {
            addr = addr<<8; ///attention!!!
            addr |= t;
            t=0;  ///attention!!!
        }
    }
    addr = addr<<8;
    addr |= t;
    cout<<hex<<addr<<endl;
    return addr;
}
