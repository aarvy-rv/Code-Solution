#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {

        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());

        int i0=0,i1=1,i2=2;

        while(i2 < nums.size()){
    
            if (nums[i2] - nums[i0] > k )
                return (vector<vector<int>>() );
            
            ans.push_back({nums[i0],nums[i1],nums[i2]});

            i0 = i2+1;
            i1 = i0+1;
            i2 = i0+2;
        }
        return ans;
    }
};