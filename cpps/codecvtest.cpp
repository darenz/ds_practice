#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string>
#include<strings.h>

#include<opencv2/opencv.hpp>
#include<string>

using namespace std;

int main()
{
    string dir = "img1.jpg";
    cv::Mat img1 = cv::imread(dir,1);
    cv::imshow("image to send",img1);
    cv::waitKey(0);
    cv::destroyWindow("image to send");
/*
    cv::Mat img2(img1.cols,img1.rows,CV_8UC3);
    img2.data = img1.data;
    cv::imshow("imgshow",img2);
    cv::waitKey(0);
 */   
    unsigned int size = img1.cols*img1.rows*3;
    uchar data[size];
    uchar* ps = img1.data;
    uchar* pimg = data;

    for(int h=0;h<img1.rows;h++)
    {
        memcpy(pimg,ps,img1.cols*3);
        pimg += img1.cols*3;
        ps += img1.cols*3;
    }
    /*
    img2.data = data;
    cv::imshow("image0",img1);
    cv::waitKey(0);
    cv::imshow("image",img2);
    cv::waitKey(0);
    */

    unsigned char* p = img1.data;     
    unsigned char buffer[100];

    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in dest_addr;
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(6666);
    dest_addr.sin_addr.s_addr = inet_addr("139.199.2.139");
    int c_flag = connect(sockfd,(struct sockaddr*)&dest_addr,sizeof(struct sockaddr));
    cout<<"connection flag: "<<c_flag<<endl; 
    if(!c_flag)
    {
        send(sockfd,(void*)&img1.cols,sizeof(img1.cols),0);
        send(sockfd,(void*)&img1.rows,sizeof(img1.rows),0);
        
        while(p-img1.data < img1.cols*img1.rows*3 && img1.cols*img1.rows*3-(int)(p-img1.data)>100)
        {   
            for(int i=0;i<100;i++)
                buffer[i] = *p++;
            int w_flag = write(sockfd,(void*)buffer,100);
            if(w_flag == 100)
                continue;
            else if(w_flag<100)
                p = p-(100-w_flag);
        }
        if(p-img1.data<img1.cols*img1.rows*3 
                && img1.cols*img1.rows*3-(int)(p-img1.data)<100)
        {
            int i;
            for(i=0;i<img1.cols*img1.rows*3-(int)(p-img1.data);i++)
                buffer[i] = *p++;
            int w_flag = write(sockfd,(void*)buffer,i+1);
            cout<<"last write flag:"<<w_flag<<endl;
        }
    }
    close(sockfd);
    return 0;
}
