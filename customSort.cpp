#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<char,int> customOrder;
public:
    int partition(int l,int h,string &s){
 //       for(auto e : customOrder){
 //           cout << e.first <<" " << e.second;
 //           cout<< "\n";
 //       }
        int pivot = l;
        int i =l+1,j=h;
 //       cout<< i<<"^^"<<j<<"\n";
        while(i<j){
            
            while(i < s.size() && customOrder[s[i]] <= customOrder[s[pivot]]){
               // cout<< i<<"^^";
                i++;
            }
                 

            while(j>=0 && customOrder[s[j]] > customOrder[s[pivot]]){
                j--;}
   //         cout<< i<<"^^"<<j<<"\n";
            if(i<j)
            {
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
        char t = s[pivot];
        s[pivot] = s[j];
        s[j] = t;
  //      cout << j;
        return j;
        

    }
    void customQuickSort(string &s,int l,int h){
    //    cout << l << h<< "\n";
        if(l<h){
            int pindex = partition(l,h,s);
            customQuickSort(s,l,pindex-1);
            customQuickSort(s,pindex+1,h);
        }
    
    }
    string customSortString(string order, string s) {

        
        for(int i =0; i < order.size();i++){
            customOrder.insert({order[i],i});
        }

         customQuickSort(s,0,s.size()-1);
         return s;
    }
};
int main(){
    Solution ob;
    cout << ob.customSortString("bcafg","abcd");
}