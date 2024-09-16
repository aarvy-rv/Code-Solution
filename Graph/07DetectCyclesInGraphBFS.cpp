#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution{
    private:
    bool bfsToDetectCycle(int startNode,int vis[],vector<int> adj[]){
        vis[startNode] = 1;
        queue<pair<int,int>> q;
        q.push({startNode,-1});

        while(!q.empty()){ 

            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(auto it:adj[node]){
                if(vis[it] != 1){
                    vis[it] = 1;
                    q.push({it,node});
                }
                else{
                    if(it != parent)
                        return true;
                }
            }

        }
        return false;

    }
    public:
    bool detectCycle(int V,vector<int> adj[]){
        int vis[V] = {0};

        for(int i = 0; i < V;i++){
            if(vis[i] != 1){
                if(bfsToDetectCycle(i,vis,adj))
                    return true;
            }
        }
        return false;
    }

};

// 2nd Approach : if while iterating the adjacent nodes of a given node, if more than one adjacent node
// is aready visited then this implies that the any previous traversed node  have already visited it
// hence creating a cycle 

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(int node,vector<int> &vis, vector<int> adj[]){
        queue<int> q;
        q.push(node);
        vis[node]=1;
       while(!q.empty()){
          int frnt= q.front();
          q.pop();
          int cnt=0;
          for(auto it:adj[frnt]){
              if(!vis[it]){
                  q.push(it);
                  vis[it]=1;
              }
              else {
                  cnt++;
              }
          }
          if(cnt>1) return true;
       }
       return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(bfs(i,vis,adj)) return true;
            }
        }
        return false;
    }
};