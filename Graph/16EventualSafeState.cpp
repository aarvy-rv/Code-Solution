//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool dfs(int node,int vis[],int path[],vector<int> adj[],int safe[]){
        
        vis[node] = 1;
        path[node] = 1;
            
        for(auto adjNode:adj[node]){
            if(safe[adjNode] == 1)
                return true;
            if(vis[adjNode] == 0){
                if(dfs(adjNode,vis,path,adj,safe) == true){
                    safe[adjNode] = 1;
                    return true;
                }
            }
            else if(path[adjNode] == 1){
                safe[adjNode] = 1;
                return true;
            }
                
        }
        path[node] = 0;
        return false;
        
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        int vis[V] = {0};
        int path[V] = {0};
        int safe[V] = {0};
        for(int i = 0; i < V;i++){
            if(vis[i] == 0){
                if(dfs(i,vis,path,adj,safe) == true){
                    safe[i] = 1;
                };
            }
        }
        vector<int> safeNodes;
        for(int i = 0;i<V;i++){
            if(safe[i] == 0)
                safeNodes.push_back(i);
        }
        return safeNodes;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends    