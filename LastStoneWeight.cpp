#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        int l = stones.size();
        if(l==1)
            return stones[0];

        int lastStoneLeft = 0; 
        multiset<int,greater<int>> stonesWeightOrdered(stones.begin(),stones.end());


        while(stonesWeightOrdered.size() > 1 ){
            int firstHeavy = *(stonesWeightOrdered.begin());
            int secondHeavy = *(++stonesWeightOrdered.begin());
            int diff = firstHeavy-secondHeavy;
            
            stonesWeightOrdered.erase(stonesWeightOrdered.begin());
            stonesWeightOrdered.erase(stonesWeightOrdered.begin());
            
            if(diff != 0){
                stonesWeightOrdered.insert(diff);
            }
           
        }
         if(stonesWeightOrdered.size() == 1)
                lastStoneLeft = *(stonesWeightOrdered.begin());

        return lastStoneLeft;
        
    }
};