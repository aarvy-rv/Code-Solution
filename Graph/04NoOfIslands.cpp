#include<iostream>
#include<vector>
using namespace std;
class Solution {
private:
    void dfs(int r, int c,vector<vector<bool>> &vis,vector<vector<char>>& grid){

        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || vis[r][c] == 1 || grid[r][c] == '0')
            return;
        
        vis[r][c] = 1;
        dfs(r-1,c,vis,grid);
        dfs(r-1,c-1,vis,grid);
        dfs(r,c-1,vis,grid);
        dfs(r+1,c-1,vis,grid);
        dfs(r+1,c,vis,grid);
        dfs(r+1,c+1,vis,grid);
        dfs(r,c+1,vis,grid);
        dfs(r-1,c+1,vis,grid);
    }
public:
    int numIslands(vector<vector<char>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> vis(rows,vector<bool>(cols,0));
        int islandCount = 0;
        for(int i = 0 ; i < rows; i ++)
        {
            for(int j = 0; j < cols; j++){

                if(grid[i][j] == '1' && vis[i][j] != 1){
                    dfs(i,j,vis,grid);
                    islandCount++;
                }
            }
        }
        return islandCount;
    }
};