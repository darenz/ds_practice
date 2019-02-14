/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba"也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
        string longestPalindrome(string s) {
        int i,j,k;
        if(s.length()==0)
            return "";
        else if(s.length()==1)
            return s;
        else if(s.length()==2)
        {
            if(s[0] == s[1])
                return s;
            return s.substr(0,1);
        }
        
        i = 0;
        j = 1;
        k = 2;
        vector<string> v;
        while(k<(int)s.length())
        {
            //问题1：当全串为回文字符串时，访问越界
            //问题2：未考虑同时满足以下两种情况的情况aaa,aaaa
            //  不能只有第一种方式来处理，要分开（奇偶不同）
            //问题3：忽略了只有最右侧两个重复的情况 abb
            //问题4：没有回文字符串（大于一个字符），应返回首字符
            if(s[i] == s[j])
            {
                int ti = i;
                int tj = j;
                while(ti>=0 && tj<=(int)s.length()-1)
                {
                    if(s[ti] == s[tj])
                    {
                        if(ti==0 || tj==(int)s.length()-1)
                        {//防止越界访问
                            v.push_back(s.substr(ti,tj-ti+1));
                            break;
                        }
                        else
                        {
                            ti--;
                            tj++;
                            continue;
                        }
                    }
                    else
                    {
                        v.push_back(s.substr(ti+1,tj-1-ti));
                        break;
                    }
                }
            }
            //else if(s[i] == s[k])
            if(s[i]==s[k]) //重复再按奇情况检测
            {
                int ti = i;
                int tk = k;
                while(ti>=0 && tk<=(int )s.length()-1)
                {
                    if(s[ti] == s[tk])
                    {
                        if(ti == 0 || tk ==(int)s.length()-1)
                        {//防止访问越界
                            v.push_back(s.substr(ti,tk-ti+1));
                            break;
                        }
                        else 
                        {
                            ti--;
                            tk++;
                            continue;
                        }
                    }
                    else
                    {
                        v.push_back(s.substr(ti+1,tk-1-ti));
                        break;
                    }
                }
            }
            else if(k == (int)s.length()-1 && s[j]==s[k])
                v.push_back(s.substr(j,2));
            i++;
            j++;
            k++;
        }
        int l = 0;
        int pos = 0;
        for(int i=0;i<(int)v.size();i++)
        {
            if((int)v[i].length()>l)
            {
                l = v[i].length();
                pos = i;
            }
        }
        // 此i非彼i
        //return v[i];
        if(v.size()==0)
            return s.substr(0,1); 
        return v[pos];
    }
};

int main()
{
    Solution sol;
    string s;
    cin>>s;
    string st = sol.longestPalindrome(s);
    cout<<st<<endl;
    return 0;
}
