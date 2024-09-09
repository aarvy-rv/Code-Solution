#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{

    public:

    vector<int> bfsOfGraph(int V,vector<int> adj[]){ // V-> No. of nodes in the graph, adj[] -> array of vectors(adjacency list)

        vector<int> bfs;
        int vis[V] = {0};
        
        int startNode = 0;
        queue<int> q;
        
        vis[startNode] = 1;
        q.push(startNode);

        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for(auto it:adj[node]){
                if(vis[it] != 1){
                    vis[it] =1;
                    q.push(it);
                }
            }
        }
        return bfs;    
    }

};