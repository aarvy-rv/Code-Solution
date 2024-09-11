#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    void dfs(int r,int c,vector<vector<bool>> &vis,vector<vector<int>> &image,int newColor,int existingColor){
        if(r < 0 || c < 0 || r >= image.size() || c >= image[0].size() || vis[r][c] == 1 || image[r][c] != existingColor)
            return;
        
        vis[r][c] = 1;   
        image[r][c] = newColor;
        dfs(r-1,c,vis,image,newColor,existingColor);
        dfs(r,c+1,vis,image,newColor,existingColor);
        dfs(r+1,c,vis,image,newColor,existingColor);
        dfs(r,c-1,vis,image,newColor,existingColor);
            
    }
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
     
        int rows = image.size();
        int cols = image[0].size();
        
        int existingColor = image[sr][sc];
        
        vector<vector<bool>> vis(rows,vector<bool>(cols,0));
        
        dfs(sr,sc,vis,image,newColor,existingColor);
        
        return image;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }
    }
    return 0;
}

