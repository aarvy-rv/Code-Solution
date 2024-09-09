#include<iostream>
#include<vector>
using namespace std;

class Solution{

    private:
        void dfs(int node,int vis[],vector<int> adj[],vector<int> &traversal){

            vis[node] = 1;
            traversal.push_back(node);

            for(auto it: adj[node]){
                if(vis[it] != 1)
                    dfs(it,vis,adj,traversal);
            }

        }
    public:
        vector<int> dfsOfGraph(int V,vector<int> adj[]){
            int vis[V] = {0};
            int startNode = 0;
            vector<int> traversal;
            dfs(startNode,vis,adj,traversal);

            return traversal;
        }

};
