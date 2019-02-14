#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {

        int max = 0;
        int left = 1;
        int right = 2;
        int i=0;
        int j=1;
        int h=0;
        while(j<(int)height.size())
        {
            h = height[i]>height[j]?height[j]:height[i];
            if(h>max)
            {
                max = h;
                left = i;
                right = j;
            }
            i++;
            j++;
        }
        return max; 
    }
};


