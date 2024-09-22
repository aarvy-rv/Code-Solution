//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private: 
    bool topoBFS(queue<int> &q,int indegree[],vector<int> adj[],int N){
        int topoLength = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topoLength++;
            for(auto adjNode: adj[node]){
                indegree[adjNode]--;
                if(indegree[adjNode] == 0)
                    q.push(adjNode);
            }
        }
        
        if(topoLength == N)
            return true;
        return false;
    }
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    
	    int indegree[N] = {0};
	    
	    int E = prerequisites.size();
	    
	    vector<int> adj[N];
	    
	    for(int i = 0; i < E; i++){
	        adj[prerequisites[i].second].push_back(prerequisites[i].first); 
	    }
	    
	    for(int i = 0; i < E; i++){
	        indegree[prerequisites[i].first]++;
	    }
	    
	    queue<int> q;
	    for(int i = 0; i < N;i++){
	        if(indegree[i] == 0)
	            q.push(i);
	    }
	    
	    if(topoBFS(q,indegree,adj,N))
	        return true;
	        
	   return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends