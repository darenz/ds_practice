#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        int n=strs.size();
        if(n==0)
            return "";
        int l_min=strs[0].length();
        for(int i=0;i<n;i++)
        {
            if(l_min>strs[i].length())
            {
                l_min = strs[i].length();
            }
        }
        for(int i=0;i<l_min;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(strs[j][i]!=strs[0][i])
                    return strs[0].substr(0,i);
            }
        }
        // 想当然以为str[0]就是最短的
        // return strs[0];
        return strs[0].substr(0,l_min);
    }
};

int main()
{
    string strs[]={
        "fflight","ffl","fflower"
    };
    vector<string> v(strs,strs+3);
    Solution sol;
    string s = sol.longestCommonPrefix(v);
    cout<<s<<endl;
}
