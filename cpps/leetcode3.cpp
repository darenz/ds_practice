#include<iostream>
#include<string>
#include<cstring>
using namespace std;
/*
给定一个字符串，找出不含有重复字符的最长子串的长度。

示例：

给定 "abcabcbb" ，没有重复字符的最长子串是 "abc" ，那么长度就是3。

给定 "bbbbb" ，最长的子串就是 "b" ，长度是1。

给定 "pwwkew" ，最长子串是 "wke" ，长度是3。请注意答案必须是一个子串，"pwke" 是 子序列  而不是子串
*/
class Solution {
    private:
        int max_length;
        unsigned char table[150];
public:
        Solution()
        {
            memset(table,0,150);
            max_length = 0;
        }

        int lengthOfLongestSubstring(string s) 
        {
            char* str; 
            if(s.length()>0)
                str = (char*)malloc(s.length()) ;
            else
                return 0;
            memcpy(str,s.data(),s.length());
            char* p_str = str;
            unsigned char* p_table=NULL; 
            int now_start_index = 0; 
            
            for(uint i=0;i<s.size();i++)
            {
                p_table = table + *p_str;
                (*p_table)++;
                if(*p_table>1)
                {
                    while(*p_table>1)
                    {
                        table[(int)str[now_start_index]]--;
                        now_start_index++; 
                    }
              //      int length = p_str - str - now_start_index + 1;
              //      if(length>max_length)
              //           max_length = length;
                }
                              p_str++;
                int length = p_str - str - now_start_index;
                if(length>max_length)
                    max_length = length;
            }
          //  int n = s.length() - now_start_index;
            free(str);
            //return (max_length>n)?max_length:n; 
            return max_length;
       }
};

int main()
{
    cout<<"string:"<<endl;
    string s;
    cin>>s;
    Solution sol;
    int n = sol.lengthOfLongestSubstring(s);
    cout<<n<<endl;
}
