//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    void bfs(queue<int> &q,int indegree[],vector<int> &topoSortOrder,vector<int> adj[]){
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topoSortOrder.push_back(node);
            
            for(auto adjNode:adj[node]){
                indegree[adjNode]--;
                if(indegree[adjNode] == 0)
                    q.push(adjNode);
            }
        }
    } 
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    int indegree[V]={0};
	    
	    for(int i = 0;i< V;i++){
	        for(auto adjNode: adj[i]){
	            indegree[adjNode]++;
	        }
	    }
	    
	    vector<int> topoSortOrder;
	    
	    queue<int> q;
	    
	    for(int i = 0; i < V;i++){
	        if(indegree[i] == 0)
	            q.push(i);
	    }
	    
	    bfs(q,indegree,topoSortOrder,adj);
	    
	    return topoSortOrder;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends