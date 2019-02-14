/*
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:

输入: 121
输出: true
示例 2:

输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3:

输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x<0)
            return 0;
        int n=0;
        int last=0;
        int t = x;
        while(t)
        {
            last = t%10; 
            t = (t-last)/10;
            n++;
        }
        char s[n];
        t = x;
        for(int i=0;i<n;i++)
        {
            last = t%10; 
            s[i] = last + '0'; 
            t = (t-last)/10;
        }
        char* p = s;
        char* q = &s[n-1];
        while(q>p)
        {
            if(*p == *q)
            {
                p++;
                q--;
            }
            else
                return 0;
        }
        return 1;
    }
};

int main()
{
    Solution sol;
    int x;
    cin>>x;
    int f = sol.isPalindrome(x);
    cout<<f<<endl;
}
