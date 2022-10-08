// Question Link: https://leetcode.com/problems/set-matrix-zeroes/submissions/

// Striver Approach:
Class solution {    
    public:
    void setZeroes(vector>& matrix) {
          int rows = matrix.size(),
              cols = matrix[0].size();
        
          vector row(rows,-1) ;
          vector col(cols,-1) ;
        
          for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
              if (matrix[i][j] == 0) {
                 row[i] = 0;
                 col[j] = 0;
              }
            }
          }
          for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
              if (row[i] == 0 || col[j]==0) {
                matrix[i][j] = 0;
              }
            }
          }
    }
};

// My Force Approach
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        queue<pair<int,int>> q;
        for(int i = 0 ; i < matrix.size() ; i++)
        {
            for(int  j = 0 ; j < matrix[0].size() ; j++)
            {
                if(matrix[i][j]==0) q.push({i,j});
            }
        }
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = 0 ; i < matrix[0].size() ; i++) matrix[row][i] = 0;
            for(int i = 0 ; i < matrix.size() ; i++) matrix[i][col] = 0;
        }
        return;
    }
};

// Brute Force Approach
Traverse through the matrix and mark each element that is needed to be changed to 0 as -1. Then, traverse the matrix again and change those -1 to 0.