//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
 private:
 void dfs(int node,int vis[],vector<pair<int,int>> adj[],stack<int> &st){
     vis[node] = 1;
     for(auto adjNode:adj[node]){
         int vertex = adjNode.first;
         if(vis[vertex] == 0)
            dfs(vertex,vis,adj,st);
     }
     st.push(node);
 }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        
        vector<pair<int,int>> adj[N];
        
        for(int i = 0;i<M;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        
        stack<int> st;
        int vis[N] = {0};
        for(int i = 0; i < N; i++){
            if(vis[i] == 0)
                dfs(i,vis,adj,st);
        }
        
        vector<int> distances(N,INT_MAX);
        distances[0] = 0;

        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(distances[node] != INT_MAX){
            for(auto adjNode:adj[node]){
                
                int vertex = adjNode.first;
                int weight = adjNode.second;
                if(distances[node] != INT_MAX && distances[node] + weight < distances[vertex])
                    distances[vertex] = distances[node] + weight;
            }
            }
        }
        for(int i = 0;i<N;i++){
            if(distances[i] == INT_MAX)
                distances[i] = -1;
        }
        return distances;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends