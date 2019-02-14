#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        for(int i=array.size()-1;i>=0;i--)
        {
            if(array[i][0]<=target)
            {
                for(uint j=0;j<array[i].size();j++)
                {
                    if(array[i][j] == target)
                        return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    int a1[10] = {
        2,3,3,4,5,6,6,7,8,9
    };
    int a2[3] = {
        2,3,4
    };
    int a3[3] = {
        3,4,5
    };
    vector<int> a(a1,a1+10);
    vector<int> b(a2,a2+3);
    vector<int> c(a3,a3+3);
    vector<vector<int>> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);

  //  for(int i=0;i<3;i++)
  //  {
  //      for(int j=0;j<3;j++)
  //          cout<<v[i][j]<<" ";
  //  }
    Solution sol;
    int x;
    cin>>x;
    bool f = sol.Find(x,v);
    cout<<f<<endl;  
}
