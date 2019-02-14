#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int standard_num[7] = {1,5,10,50,100,500,1000};
    string standard_roman[7] = {"I","V","X","L","C","D","M"};

    string intToRoman(int num) {
        if(num == 0)
            return "";

        int i=0;
        int t_num = num;
        while(t_num)
        {
            i++;
            t_num = t_num/10;
        }
        int max_st = mypow(i-1);

        return convert(num/max_st*max_st)+intToRoman(num-num/max_st*max_st);
    }

    string convert(int n)
    {
        int low = standard_num[0];
        int high = standard_num[1];
        int i;
        for(i=0;i<6;i++)
        {
            low = standard_num[i];
            high = standard_num[i+1];
            if(n<=high)
                break;
        }
        if(n>1000)
            return strpow("M",n/1000);
        if(n == high)
                return standard_roman[i+1];
        if(n<=10)
        {
            if(n == high-1)
                return "I"+standard_roman[i+1];
            else
                return standard_roman[i] + strpow("I",n-standard_num[i]);
        }
        else if(n<=100)
        {
            if(n == high-10)
                return "X"+standard_roman[i+1];
            else
                return standard_roman[i] + strpow("X",(n-standard_num[i])/10);
        }
        else if(n<=1000)
        {
            if(n == high-100)
                return "C"+standard_roman[i+1] ;
            else
                return standard_roman[i] + strpow("C",(n-standard_num[i])/100);
        }
        else 
            return "erro";
    }

    string strpow(string s,int n)
    {
        string ret;
        for(int i=0;i<n;i++)
            ret += s;
        return ret;
    }

    int mypow(int n)
    {
        if(n==0)
            return 1;
        return mypow(n-1)*10;
    }
};

int main()
{
    int num;
    cin>>num;
    Solution sol;
    cout<<sol.intToRoman(num)<<endl;
    return 0;
}
