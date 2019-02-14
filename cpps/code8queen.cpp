#include<iostream>
using namespace std;

//8皇后

class Solution
{
public:

    int location[8]={0};
    int tatal = 0;

    bool checkValid(int deepth,int i)
    {//只用考虑新加入点的有效性
        for(int j=0;j<deepth;j++)
        {
            if(location[j]==i)
                return false;
            if(location[j]+j == deepth+i)
                return false;
            if(7-location[j]+j == deepth + 7-i)
                return false;
        }
        return true;
    }
  
    void EightQueen(int deepth)
    {
        for(int i=0;i<8;i++)
        {
            location[deepth] = i;
            if(checkValid(deepth,i))
            {
                if(deepth==7)
                {
                    tatal++;
                    return;
                }
                EightQueen(deepth+1);
            }
        }
    }
};

int main()
{
    Solution sol;
    sol.EightQueen(0);
    cout<<sol.tatal<<endl;
}
