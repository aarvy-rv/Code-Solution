#include<iostream>
#include<vector>
#include <climits>
using namespace std;

class Subarray{
public:
    /// @brief 
    /// @param arr 
    /// @param k 
    /// @return 
    int maxSubArraySumKlength(vector<int> &arr,int k){
        int len = arr.size();
        int maxSum = INT_MIN;
        int sum = 0;
        for(int i = 0; i < len; i++){
            sum+=arr[i];
            if(i == k-1)
                maxSum = sum;
            else if(i>=k){
                sum = sum - arr[i-k];
                maxSum= max(sum,maxSum);
            }
        }
        return maxSum;
    }
};
int main(){
    Subarray* fixedSize = new Subarray();
    vector<int> arr={1,2,3,4,5,6,7,8,9,10};
    cout << fixedSize->maxSubArraySumKlength(arr,10);
}