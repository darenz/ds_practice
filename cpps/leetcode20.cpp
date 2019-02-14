#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.length() == 0)
            return false;
        int l = s.length();
        if(l%2 != 0)
            return false;
        char left[l/2],right[l/2];
        char* pleft = left;
        char* pright = right;
        for(int i=0;i<l;i++)
        {
            switch(s[i])
            {
                case '{' :
                        *pleft++= '{';
                        break;
                case '(':
                        *pleft++ = '(';
                        break;
                case '[' :
                        *pleft++ = '[';
                        break;
                case '}' :
                        *pright++ = '}';
                        break;
                case ')' :
                        *pright++ = ')';
                        break;
                case ']' :
                        *pright++ = ']';
                        break;
                default:
                    return false;
            }
        }
        if(pleft-left != pright-right)
            return false;
        while(pleft != left && pright != right)
        {
            pleft--;
            pright--;
            if(*pleft == '{' && *pright== '}')
                continue;
            else if(*pleft == '(' && *pright==')')
                continue;
            else if(*pleft == '[' && *pright==']')
                continue;
            else 
                return false;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    string s;
    cin>>s;
    bool b = sol.isValid(s);
    cout<<b<<endl;
    return 0;
}
