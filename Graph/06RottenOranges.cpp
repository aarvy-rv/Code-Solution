#include<bits/stdc++.h>
using namespace std;

/*class Solution {
private:
    bool check(int r,int c,vector<vector<int>> &grid){
        if(r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size())
            return true;
        return false;
    }
    void customBfs(queue<pair<int,int>> &q,vector<vector<int>> &vis,vector<vector<int>> &grid,int *min){
        
        while(!q.empty()){
            (*min)++;
            int len = q.size();
            for(int i = 0;i<len;i++){
                pair<int,int> cell = q.front();
                int row = cell.first;
                int col = cell.second;
            
                if(check(row-1,col,grid) && vis[cell.first - 1][cell.second] != 1 && grid[row-1][col] == 1){
                    q.push({row-1,col});
                    vis[row-1][col] = 1;
                    grid[row-1][col] = 2;
                }
                if(check(row,col+1,grid) && vis[cell.first][cell.second+1] != 1 && grid[row][col+1] == 1){
                    vis[row][col+1] = 1;
                    q.push({row,col+1});
                    grid[row][col+1] = 2;
                }
                if(check(row+1,col,grid) && vis[cell.first + 1][cell.second] != 1 && grid[row+1][col] == 1){
                    vis[row+1][col] = 1;
                    q.push({row+1,col});
                    grid[row+1][col] = 2;
                }
                if(check(row,col-1,grid) && vis[cell.first][cell.second-1] != 1 && grid[row][col-1] == 1){
                    vis[row][col-1] = 1;
                    q.push({row,col-1});
                    grid[row][col-1] = 2;
                }

        }
        
        }
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {

        queue<pair<int,int>> q;
        int mins = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for(int i = 0;i<rows;i++){
            for(int j = 0;j<cols;j++){
                if(grid[i][j] == 2)
                    q.push({i,j});
            }
        }
        vector<vector<int>> vis(rows,vector<int>(cols,0));
        customBfs(q,vis,grid,&mins);
       /* for(int i = 0;i<rows;i++){
            for(int j = 0;j<cols;j++){
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        return mins;
    }
};*/

class Solution {
private:
    bool check(int r, int c, vector<vector<int>> &grid) {
        return r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size();
    }

    void customBfs(queue<pair<int,int>> &q, vector<vector<int>> &vis, vector<vector<int>> &grid, int *minTime) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Up, Down, Right, Left
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}}; 
        
        while (!q.empty()) {
            (*minTime)++;
            int len = q.size();
            for (int i = 0; i < len; i++) {
                pair<int,int> cell = q.front();
                q.pop();
                int row = cell.first;
                int col = cell.second;

                for (auto d : directions) {
                    int newRow = row + d.first;
                    int newCol = col + d.second;
                    if (check(newRow, newCol, grid) && vis[newRow][newCol] == 0 && grid[newRow][newCol] == 1) {
                        q.push({newRow, newCol});
                        vis[newRow][newCol] = 1;
                        grid[newRow][newCol] = 2;
                    }
                }
            }
        }
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int mins = -1;
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> vis(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        customBfs(q, vis, grid, &mins);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    return -1; 
                }
            }
        }

        // Returning 0 if no fresh oranges were initially present
        return (mins == -1) ? 0 : mins; 
    }
};
