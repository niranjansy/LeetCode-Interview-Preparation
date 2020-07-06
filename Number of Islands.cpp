// https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    
    void DFS(vector<vector<char>>& grid, int i, int j)
    {
        int n = grid.size();
        int m = grid[0].size();
        grid[i][j] = '0';
        if((i+1)<n && grid[i+1][j]=='1')
            DFS(grid, i+1, j);
        if((i-1)>=0 && grid[i-1][j]=='1')
            DFS(grid, i-1, j);
        if((j+1)<m && grid[i][j+1]=='1')
            DFS(grid, i, j+1);
        if((j-1)>=0 && grid[i][j-1]=='1')
            DFS(grid, i, j-1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if(n == 0)
            return 0;
        int m = grid[0].size();
        if(m == 0)
            return 0;
        int c = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == '1')
                {
                    DFS(grid, i, j);
                    c++;
                }  
            }
        }
        
        return c;
    }
};