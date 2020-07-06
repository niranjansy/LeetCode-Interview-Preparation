// https://leetcode.com/problems/minimum-path-sum/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int min_path[m][n];
        min_path[0][0] = grid[0][0];
        for(int i=1; i<m; i++)
            min_path[i][0] = min_path[i-1][0] + grid[i][0];
        for(int j=1; j<n; j++)
            min_path[0][j] = min_path[0][j-1] + grid[0][j];
        
        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                min_path[i][j] = min(min_path[i-1][j], min_path[i][j-1]) + grid[i][j];
            }
        }
        
        return min_path[m-1][n-1];
    }
};