//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    bool isCycleDFS(int startNode,int parent,bool vis[],vector<int> adj[]){

        vis[startNode] =1;

        for(auto adjacentNode: adj[startNode]){
            if(vis[adjacentNode]!=1){
                 if(isCycleDFS(adjacentNode,startNode,vis,adj)==true)
                    return true;
            }
            else if(adjacentNode != parent)
                return true;
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
        // Code here
         bool vis[V] = {0};
        for(int i =0 ;i< V;i++){
            if(vis[i]!=1){
                if(isCycleDFS(i,-1,vis,adj)==true)
                    return true;
            }
        }
        return false;
       
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends