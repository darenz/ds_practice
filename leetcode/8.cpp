#include<iostream>
#include<string>

using namespace std;

//问题
//1.未考虑完整情况。应为：数字已转的长度不为0时，如果当前字符不为数字，则终止转换。
//  题目条件不合理的例子：+-20 应为 -20 ,而不应该为0
//2.输入数字可能也对Long溢出，不能只在返回前判断，要在累加过程中判断。同时要注意最后一次累加没有在循环内进行判断。
class Solution {
public:
    #include<limits.h>
    int myAtoi(string str) {
        long result = 0;
        int flag = 0;
        int len = 0;
        for(int i=0;i<(int)str.size();i++)
        {
            if(result > INT_MAX)
                return INT_MAX;
            else if(result < INT_MIN)
                return INT_MIN;

            //已转部分数字
            if(len!=0 && (str[i] < '0' && str[i] > '9'))
                break;

            //还未转有数字
            if(str[i] == ' ') 
                continue;
            else if(str[i] == '+' || str[i] == '-')
            {
                if(i<(int)str.size()-1)
                {
                    if(str[i+1] < '0' || str[i+1]>'9')
                        return 0;
                }
                if(str[i] == '-')
                    flag = 1;
                else
                    flag = 0;
            }
            else if(str[i] >= '0' && str[i] <= '9')
            {
                switch(flag)
                {
                    case 0:
                        len++;
                        result = result*10 + str[i] - '0';
                        break;
                    case 1:
                        len++;
                        result = result*10 - str[i] + '0';
                        break;
                    default :
                        return 0;
                }
            }
            else
                break;
        }
        if(result > INT_MAX)
            return INT_MAX;
        else if(result < INT_MIN)
            return INT_MIN;
        else  
            return result;
    }
};

int main()
{
    Solution sol;
    string str;
    cin>>str;
    int result = sol.myAtoi(str);
    cout<<result<<endl;
    return 0;
}
