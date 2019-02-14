#include<iostream>
#include<mysql/mysql.h>
using namespace std;

int main()
{
    MYSQL* mysql = mysql_init(NULL);
    //string host = "139.199.2.139";
    string host = "localhost";
    string user = "studentbase";
    string  passwd = "student";
    string db = "student";
    //int sockfd = socket(AF_INET,SOCK_STREAM,0);
    
//    if(!mysql_real_connect(mysql,host.c_str(),c_str(),passwd.c_str(),db.c_str(),3306,NULL,0))

    if(!mysql_real_connect(mysql,"localhost","root","coding","students",0,NULL,0))
    {
        cout<<"connect failed!"<<endl;
        return 0;
    }
    else
        cout<<"connected~!"<<endl;
    
    string query = "insert into student2 (name,id) values (\"zhujian\",\"12345678\") ";
//    int q_flag = mysql_query(mysql,"select * from students1");
    int q_flag = mysql_query(mysql,query.c_str());
    if(q_flag)
    {
        cout<<"query failed"<<endl;
        return 0;
    }
    
    q_flag = mysql_query(mysql,"select * from student2");

    MYSQL_RES* res = NULL;
    res = mysql_use_result(mysql);
    if(res == NULL)
    {
        cout<<"use failed"<<endl;
        return 0;
    }

    MYSQL_ROW row;
    uint num_fields = mysql_num_fields(res);
    while((row = mysql_fetch_row(res)))
    {
        unsigned long *lengths;
        lengths = mysql_fetch_lengths(res);
        for(uint i = 0; i < num_fields; i++)
        {
            printf("[%.*s] ", (int) lengths[i],
                    row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }
}


