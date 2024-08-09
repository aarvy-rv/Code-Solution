#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:

    bool isMagicSquare(int r,int c,vector<vector<int>> &grid ){

        int rSum = rowSums(r,c,grid);
        if(rSum == -1)
            return false;

        int cSum = colSums(r,c,grid);
        if(cSum == -1)
            return false;

        int dSum = diagonalsSum(r,c,grid);
        if(dSum == -1)
            return false;

        if(rSum != cSum || cSum != dSum)
            return false;

        return true; 
    }

    int rowSums(int r,int c,vector<vector<int>> &grid){
        vector<bool> visited(10,false);
        int sum = 0;
        for(int i = 0;i<3;i++){
            int rowSum = 0;
            for(int j = 0;j<3;j++){
                int cellValue = grid[r+i][c+j]; 
                if(cellValue > 9 || cellValue == 0 || visited[cellValue])
                    return -1;
                visited[cellValue] = true;
                rowSum+=cellValue;
            }

            if( i == 0){
                sum = rowSum;
            }
            else{
                if(rowSum != sum)
                    return -1;
            }
        }
        return sum;
    }

    int colSums(int r,int c,vector<vector<int>> &grid){
        int sum = 0;
        for(int j = 0;j<3;j++){
            int colSum = 0;
            for(int i = 0;i<3;i++){
                colSum+= grid[r+i][c+j];
            }
            if(j == 0){
                sum = colSum;
            }
            else{
                if(sum!=colSum)
                    return -1;
            }
        }
        return sum;
    }
    int diagonalsSum(int r,int c,vector<vector<int>> &grid){
        int ldSum = grid[r][c] + grid[r+1][c+1] + grid [r+2][c+2];
        int rdSum = grid[r][c+2] + grid[r+1][c+1] + grid [r+2][c];

        if(ldSum != rdSum)
            return -1;
        
        return ldSum;
    } 
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int cntOfMagicSquares = 0;
        int r = grid.size();
        int c = grid[0].size();

        if(r<3 || c<3)
            return 0;

        for(int i = 0; i <= r-3;i++ ){
            for(int j = 0;j <= c-3;j++){
                if(isMagicSquare(i,j,grid))
                    cntOfMagicSquares++;
            }
        }
        return cntOfMagicSquares;
        
    }
};