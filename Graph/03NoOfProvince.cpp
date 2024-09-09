#include<iostream>
#include<vector>
using namespace std;

class Solution {
    private:
        void dfs(int node,vector<int> &vis,vector<int> adj[]){
    
                vis[node] = 1;
                
                for(auto it: adj[node]){
                    if(vis[it] != 1)
                        dfs(it,vis,adj);
                }
    
            }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
         vector<int> vis(V,0);
         
         
         int l = adj.size();
         vector<int> adjList[V];
         for(int i = 0; i< l;i++){ // converting adjacency matrix to adjacency list 
             for(int j = 0; j< l;j++){
                 if(adj[i][j] == 1){
                     adjList[i].push_back(j);
                     adjList[j].push_back(i);
                 }
                
             }
         }
            
            int provinceCount = 0;
            for(int i = 0; i< V;i++){
                if(vis[i] == 0){
                    dfs(i,vis,adjList);
                    provinceCount++;
                }
            }
            return provinceCount;
    }
};