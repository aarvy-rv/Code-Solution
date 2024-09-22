//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    
    bool dfs(int node,int color,int colors[],vector<int> adj[]){
        colors[node] = color;
        
        for(auto adjNode : adj[node]){
            if(colors[adjNode] == -1){
                if(!dfs(adjNode, !color, colors, adj))  
                    return false;
            }
            else if(colors[adjNode] == color)
                return false;
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    int colors[V];
	    for(int i = 0;i<V;i++)
	        colors[i]=-1;
	      
	   for(int i = 0;i < V;i++){
	       if(colors[i] == -1)
	       {
	           if(!dfs(i,0,colors,adj))
	            return false;
	       }
	   }
	   return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends