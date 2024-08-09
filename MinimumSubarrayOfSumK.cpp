#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
    vector<int> minimumSubArray(vector<int>& nums,int k)
    {
        vector<int> ans;
        int len = nums.size();
        int left = 0;
        int right = 0;
        int sum = 0;
        int startIndex,endIndex;
        int max = 0;
        while(right<len)
        {
            sum += nums[right];
            if(sum<k){
                right++;
            }
            else if(sum==k)
            {
                if(right-left+1 > max)
                {
                    startIndex = left;
                    endIndex = right;
                    max = right-left+1;
                }
            }
            else{
                while( left<=right && sum>k ){
                    sum-=nums[left];
                    left++;
                }
            }

        }
        while(startIndex<=endIndex){
            ans.push_back(nums[startIndex++]);

        }

        return ans;
    }
};
int main(){
    Solution* ob = new Solution();
    vector<int> input({4,1,2,1,1,1,1,1,5,6});
    vector<int> ans = ob->minimumSubArray(input,5);
    for(int el:ans){
        cout<<el<<" ";
    }
}