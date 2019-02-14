#include<iostream>
#include<cmath>
#include<climits>
using namespace std;

//给定一个 32 位有符号整数，将整数中的数字进行反转。
class Solution {
public:
    int reverse(int x) {
        long y = 0;
        int t = 0;

        while(x)
        {
            t = x%10;
            if(y*10+t>INT_MAX || y*10+t<0-INT_MAX)
                return 0;
            y = y*10 + t;
            x = (x-t)/10;
        }
        return (int)y; 
    }
};

int main()
{
    int x;
    cin>>x;
    Solution sol;
    int y = sol.reverse(x);
    cout<<y<<endl;
}

//解答记录
//主要问题：
//  判断溢出
//  a.加法溢出可以通过正负号变化来判断，因为最多只进一位。
//  b.乘法溢出，可进多位，无法通过符号变化来判度溢出。溢出后结果可正可负，无法确定。
//  乘法溢出要通过溢出的定义判断：结果大于最大存储允许
//1.首先想到的是用汇编溢出标志位判断溢出,汇编格式繁杂，选择逻辑判断
//2.通过先判断计算结果是否大于int最大值判断,再决定是否直接返回0.
//  a.不能使用(unsigned int)来对计算结果进行转换与INT_MAX比较，因为也会丢失unsigned int更高位的值。该方法只能判断正数的加法（最多进一位）(减法不存在溢出)
//  不过这种方法相当愚蠢,因为如果通过只进一位来判断溢出，可以直接看符号变化。
//  b.本质就是判断计算结果是否大于INT_MAX(或小于-INT_MAX)，所以只需要能够获得完整的计算结果再进行比较即可。使用Long存储计算结果，再比较
//  c.long强制转换为int时会自动带符号
//
//总结：
//  溢出判断：
//  1.带符号加法：直接判断符号变化
//  2.带符号乘法：通过更长的类型存储结果，再与范围值比较
//  3.无符号加法：溢出则结果小于最小加数
//  4.无符号乘法：同2
