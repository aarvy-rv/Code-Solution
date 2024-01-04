#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums) {

        unordered_map<int,int> freq;

        for(int i = 0; i < nums.size();i++){
            if(freq.find(nums[i]) != freq.end()){
                freq[nums[i]]++;
            }
            else{
                freq.insert({nums[i],1});
            }
        }
        int minOps = 0;
        for(auto element: freq){
            int frequency = element.second;
            if(frequency == 1){
                minOps=-1;
                break;
            }

            if(frequency % 3 == 0)
             minOps+=(frequency/3);
            else
            minOps+=(frequency/3)+1;
        }
        return minOps;
    }
};