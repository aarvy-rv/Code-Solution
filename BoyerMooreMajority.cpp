#include <iostream>
#include <vector>
using namespace std;

class BoyerMooreMajority{
public:
    int majorityElement(vector<int>& nums) {

        int count =0;
        int el = nums[0];
        int l =nums.size();
        
        for(int i=0;i<l;i++){
            if(count == 0){
                count++;
                el = nums[i];
            }
            else if(nums[i] == el)
                count++;
            else
                count--;
        }
        int elFrequency=0;
        for(int i=0;i<l;i++){
            if(el==nums[i])
                elFrequency++;
        }
        if(elFrequency>(l/2))
            return el;
        else
         return -1;
        
    }
};
int main(){
  vector<int> myVector{2,2,2,2,2,11,12,13,14};
  BoyerMooreMajority algo;
  cout << algo.majorityElement(myVector);
}