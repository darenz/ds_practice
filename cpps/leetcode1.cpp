#include<iostream>
#include<vector>
using namespace std;

class solution
{
    public:
        vector<int> twoSum(vector<int>& nums,int target);
};

vector<int> solution::twoSum(vector<int>& nums,int target)
{
    vector<int> result;
    for(int i=0;i<nums.size()-1;i++)
    {
        for(int j=i+1;j<nums.size();j++)
        {
            if(nums[i] + nums[j] == target)
            {
                result.push_back(i); 
                result.push_back(j);
            }
        }
    }
    return result;
}

int main()
{
    solution sl;

    vector<int> input = {
        1,2,3,4,5
    };
    for(int i=0;i<input.size();i++)
        cout<<input[i];
    cout<<endl;
    vector<int> output = sl.twoSum(input,9);
    cout<<output[0]<<output[1]<<endl;
}
