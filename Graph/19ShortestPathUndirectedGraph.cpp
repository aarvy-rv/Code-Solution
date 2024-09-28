//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        
        vector<int> adj[N];
        
        //creating adjacency list
        for(int i = 0; i < M;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> distances(N,INT_MAX);
        distances[src] = 0;
        
        int vis[N] = {0};
        
        queue<pair<int,int>> q;
        q.push({src,0});
        vis[src] = 1;
        
        while(!q.empty()){
            int node = q.front().first;
            int dis = q.front().second;
            q.pop();
            
            for(auto adjNode: adj[node]){
                if(vis[adjNode] == 0){
                    vis[adjNode] = 1;
                    if(dis+1 < distances[adjNode])
                        distances[adjNode] = dis + 1;
                    q.push({adjNode,distances[adjNode]});
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
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends