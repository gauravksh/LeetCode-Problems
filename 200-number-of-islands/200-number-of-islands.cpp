class Solution {
    int m, n;
    vector<vector<bool>> vis;
    int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    void dfs(vector<vector<char>>& grid, int x, int y) {
        if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] != '1' || vis[x][y]) {
            return;
        }
        
        vis[x][y] = true;
        for (auto dir : dirs) {
            int r = x + dir[0];
            int c = y + dir[1];
            
            dfs(grid, r, c);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        vis.resize(m, vector<bool>(n, false));
        
        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    dfs(grid, i, j);
                    result++;
                }
            }
        }
        
        return result;
    }
};