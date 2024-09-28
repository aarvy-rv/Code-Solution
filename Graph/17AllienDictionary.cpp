//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 private:
  void topo(int node,int vis[],vector<int> adj[],stack<int>&st){
      vis[node] = 1;
      for(auto adjNode:adj[node]){
          if(vis[adjNode] == 0){
              topo(adjNode,vis,adj,st);
          }
      }
      st.push(node);
  }   
  public:
    string findOrder(string dict[], int n, int k) {
        // code here
        
        
        int vis[k] = {0};
        stack<int> st;
        vector<int> adj[k]; 
        for(int i = 0;i < n-1;i++){
            
            string word1 = dict[i];
            string word2 = dict[i+1];
            
            int j = 0;
            
            while(j < word1.length() && j < word2.length()){
                if(word1[j] != word2[j] ){
                    adj[word1[j]-97].push_back(word2[j]-97);
                    break;
                }
                j++;
            }
        }
        
        for(int i = 0;i <k;i++){
            if(vis[i] == 0)
                topo(i,vis,adj,st);
        }
        
        string order;
        while(!st.empty()){
            order+=(st.top()+97);
            st.pop();
        }
        return order;
    }
};

//{ Driver Code Starts.
string order;

bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i])
                f = false;

        if (f)
            cout << 1;
        else
            cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends