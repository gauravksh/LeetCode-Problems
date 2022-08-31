class Solution {
public:
   
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& v) {
        int n = grid.size();
        int m = grid[0].size();
        
        v[i][j] = true;
        
        if(i>0 && !v[i-1][j] && grid[i-1][j] >= grid[i][j])
            dfs(grid, i-1, j, v);
        if(j>0 && !v[i][j-1] && grid[i][j-1] >= grid[i][j])
            dfs(grid, i, j-1, v);
        if(i<n-1 && !v[i+1][j] && grid[i+1][j] >= grid[i][j])
            dfs(grid, i+1, j, v);
        if(j<m-1 && !v[i][j+1] && grid[i][j+1] >= grid[i][j])
            dfs(grid, i, j+1, v);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>atl(n, vector<bool>(m, false));
        vector<vector<bool>>pac(n, vector<bool>(m, false));
        
        for(int i=0;i<m;i++) { 
            dfs(grid, 0, i, pac);
            dfs(grid, n-1, i, atl);
        }
        
        for(int i=0;i<n;i++) { 
            dfs(grid, i, 0, pac);
            dfs(grid, i, m-1, atl);
        }
        
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(atl[i][j] && pac[i][j])
                    ans.push_back({i, j});
        
        return ans;
    }
};