#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        stack<int> warmerTemps;
        int noOfDays = temperatures.size();
        warmerTemps.push(noOfDays-1);

        vector<int> ans(noOfDays,0);
        
        for(int day = noOfDays-2; day > -1; day--){
            while(!warmerTemps.empty() && temperatures[day] >= temperatures[warmerTemps.top()]){
                warmerTemps.pop();
            }

            if(!warmerTemps.empty() && temperatures[day] < temperatures[warmerTemps.top()]){
                ans[day] = warmerTemps.top() - day;
            }
            warmerTemps.push(day);
        }

        return ans;
        
    }
};