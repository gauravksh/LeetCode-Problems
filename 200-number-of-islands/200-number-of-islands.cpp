class Solution {
    int m, n;
    int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    void dfs(vector<vector<char>>& grid, int x, int y) {
        if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] != '1') {
            return;
        }
        
        grid[x][y] = '0';
        for (auto dir : dirs) {
            int r = x + dir[0];
            int c = y + dir[1];
            
            dfs(grid, r, c);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        
        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    result++;
                }
            }
        }
        
        return result;
    }
};