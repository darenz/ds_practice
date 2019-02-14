#include<iostream>
#include<string>
using namespace std;

// 问题：
// 1.未考虑全为左括号，不会因为不匹配而推出（根本没有判断是否匹配）
//  解决：增加左括号计数，最终为0才为true
class Solution
{
    public:
        bool isValid(string s)
        {
            if(s.size()%2 != 0)
                return false;
            int l = s.size()/2;
            int n = 0;
            char stack[l+1];
            char* p = &stack[l];
            char expect;
            
            for(int i=0;i<(int)s.size();i++)
            {
                if(p<stack || p>(stack+l))
                    return false;
                switch(s[i])
                {
                    case '(':
                        *p = '(';
                        n++;
                        p--;
                        break;
                    case '[':
                        *p = '[';
                        n++;
                        p--;
                        break;
                    case '{':
                        *p = '{';
                        n++;
                        p--;
                        break;
                    case ')':
                        expect = getExpect(p+1);
                        if(expect == ')')
                        {
                            n--;
                            p++;
                        }
                        else 
                            return false;
                        break;
                    case ']':
                        expect = getExpect(p+1);
                        if(expect == ']')
                        {
                            n--;
                            p++;
                        }
                        else
                            return false;
                        break;
                    case '}':
                        expect = getExpect(p+1);
                        if(expect == '}')
                        {
                            n--;
                            p++;
                        }
                        else
                            return false;
                        break;

                    default:
                        return false;
                }
            }
            if(n == 0)
                return true;
            else 
                return false;
        }

        char getExpect(char* p )
        {
            switch(*p)
            {
                case '{':
                    return '}';
                case '[':
                    return ']';
                case '(':
                    return ')';
                default:
                    return 0;
            }
        }
};

int main()
{
    Solution sol;
    string s;
    cin>>s;

    bool f = sol.isValid(s);
    cout<<f<<endl;
    return 0;
}
