#include<iostream>
using namespace std;
//请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
class Solution {
public:
	void replaceSpace(char *str,int length) {

        char* ps = str;
        char* p0 = str;
        int n=0;
        while(*ps != '\0')
        {
            if(*ps == ' ')
                getString(p0,ps);
        }
         
	}

    char* getString(char* p0,char* p1)
    {
        int n = p1-p0;
        char* news = new char[p1-p0+3+1];
        for(int i=0;i<n;i++)
            news[i] = p0[i];
        news[n] = '%';
        news[n+1] = '2';
        news[n+2] = '0';
        news[n+3] = '\0';
        return news;
    }

    int strlen(char* s)
    {
        char* sp = s;
        while(*sp != '\0')
            sp++;
        return sp-s;
    }

    char* newString(char** ss,int n)
    {
        int l=0;
        for(int i=0;i<n;i++)
            l = l+strlen(ss[i]);
        char* ns = new char[l+1];
        ns[l] = '\0';
        return ns;
    }
};
