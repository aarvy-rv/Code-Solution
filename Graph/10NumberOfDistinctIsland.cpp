//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  
  private:
  
  vector<pair<int,int>> directions = {{-1,0},{0,1},{1,0},{0,-1}};
  
  void dfs(int r,int c,vector<vector<bool>> &vis,vector<vector<int>>& grid,
            int baseRow,int baseCol,vector<pair<int,int>> &cells)
  {
    if( r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || vis[r][c] == 1 || grid[r][c] == 0)
          return;
          
    vis[r][c] = 1;
    cells.push_back({r-baseRow,c-baseCol});
    
    for(auto d:directions){
        int newRow = r + d.first;
        int newCol = c + d.second;
        dfs(newRow,newCol,vis,grid,baseRow,baseCol,cells);
    }
      
}
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<bool>> vis(rows,vector<bool>(cols,0));
        
        set<vector<pair<int,int>>> st;
        
        for(int i = 0; i < rows; i++){
            for(int j = 0;j < cols; j++){
                vector<pair<int,int>> cells;
                if(vis[i][j] == 0 && grid[i][j] == 1){
                    dfs(i,j,vis,grid,i,j,cells);
                    st.insert(cells);
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends