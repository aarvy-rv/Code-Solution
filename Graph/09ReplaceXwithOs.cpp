//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    void dfs(int r, int c, vector<vector<int>>& vis, vector<vector<char>>& mat) {
        if (r < 0 || r >= mat.size() || c < 0 || c >= mat[0].size() || mat[r][c] == 'X' || vis[r][c] == 1)
            return;

        vis[r][c] = 1;

        dfs(r - 1, c, vis, mat); 
        dfs(r + 1, c, vis, mat); 
        dfs(r, c - 1, vis, mat); 
        dfs(r, c + 1, vis, mat); 
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        int rows = mat.size();
        int cols = mat[0].size();
        
        vector<vector<int>> vis(rows, vector<int>(cols, 0));

       for (int i = 0; i < rows; i++) {
            if (mat[i][0] == 'O' && !vis[i][0])
                dfs(i, 0, vis, mat);
            if (mat[i][cols - 1] == 'O' && !vis[i][cols - 1])
                dfs(i, cols - 1, vis, mat);
        }
        
        for (int j = 0; j < cols; j++) {
            if (mat[0][j] == 'O' && !vis[0][j])
                dfs(0, j, vis, mat);
            if (mat[rows - 1][j] == 'O' && !vis[rows - 1][j])
                dfs(rows - 1, j, vis, mat);
        }

        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 'O' && !vis[i][j]) {
                    mat[i][j] = 'X'; 
                }
            }
        }

        return mat;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends