#include<iostream>
#include<string>

//分析:
//找到与当前点关于下一个节点对称的点
//1.当前点i
//2.下一个节点inode。节点计数
//3.对称点。对称距离d
//注意：numRows=1时的处理。在while中会出现死循环。

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string result;
        if(numRows == 1)
            return s;
        for(int r=0;r<numRows;r++)
        {
            int i=r;
            int nnode = 1;
            int inode; 
            result += s[i];
            while(i<(int)s.length())
            {
                inode = nnode*(numRows-1);
                int d = inode-i;
                if(d!=0)
                {
                    i = inode+d;
                    if(i<(int)s.length())
                        result += s[i];
                }
                nnode++;
            }
        }
        return result;
    }
};

int main()
{
    string s;
    cin>>s;
    int n;
    cin>>n;
    Solution sol;
    string result = sol.convert(s,n);
    cout<<result<<endl;
}
