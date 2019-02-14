#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class Solution {
public:
	void replaceSpace(char *str,int length) {
        char* p = str;
        int n=0;
        for(int i=0;i<length;p++,i++)
        {
            if(*p == ' ')
                n++;
        }
        int l = length+n*2+1;
        char* ns = new char[l];
        for(int i=0;i<l;i++)
            ns[i] = 0;
        char* np1 = &str[length-1];
        char* np2 = &ns[l-2];
        *(np2+1) = '\0';
        while(np1>=str)
        {
            if(*np1 == ' ')
            {
                *(np2--)= '0';
                *(np2--)= '2';
                *(np2) = '%';
            }
            else
                *np2 = *np1;
            np1--;
            np2--;
        }
        np1 = NULL;
        np2 = NULL;
        str = ns;
	}
};

int main()
{
    string s = "abc dd e ffgk";
   // cin>>s;
    Solution sol;
    char* cs = new char[s.size()+1];
    strcpy(cs,s.c_str());
    cout<<"cs:"<<cs<<endl;
    sol.replaceSpace(cs,s.size());
    cout<<cs<<endl;
}
