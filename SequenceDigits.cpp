#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(int num,int low,int high){
        if(num>=low && num<=high)
            return true;

        return false;
    }
    int sequenceNumber(int indexLow,int indexHigh){
        vector<int> digit{ 1,2,3,4,5,6,7,8,9 };
        int num=0;
        for(int i = indexLow;i<=indexHigh;i++){
            num= num*10+digit[i];
        }
        return (num);
    }
    vector<int> sequentialDigits(int low, int high) {
       
        int lowLength =(int)log10(low)+1;
        int highLength =(int)log10(high)+1;
        vector<int> ans;
        int i = lowLength;
        while(i<=highLength){
            int start=0;
            while(start <= 9-i){
                int seqnumber = sequenceNumber(start,start+i-1);
                if(check(seqnumber,low,high)){
                ans.push_back(seqnumber);
                }
                start++;
            }
            i++;
        }
        return ans;
    }
};
int main()
{
    Solution* ob = new Solution();
    vector<int> ans =ob->sequentialDigits(1000,13000);
    for(int e:ans){
        cout<<e<<" ";
    }
}