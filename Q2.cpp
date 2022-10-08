// Question Link: https://leetcode.com/problems/pascals-triangle/



// My approach:
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal(numRows);
        pascal[0].push_back(1);
        if(numRows==1) return pascal;
        pascal[1].push_back(1);
        pascal[1].push_back(1);
        for(int i = 2 ; i < numRows ; i++)
        {
            pascal[i].push_back(1);
            for(int j = 1 ; j < i ; j++)
            {
                pascal[i].push_back(pascal[i-1][j-1]+pascal[i-1][j]);
            }
            pascal[i].push_back(1);
            pascal[i].resize(i+1);
        }
        return pascal;
    }
};