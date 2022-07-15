class Solution {
    int vis[55][55];
    int solve(int ans, int cur, int row, int col, vector<vector<int>>& grid, int m, int n) {
        if(row+1 < n && grid[row+1][col] == 1 && vis[row+1][col] == -1) {
            vis[row+1][col] = 1;
            cur += solve(ans, 1, row+1, col, grid, m, n);
        }
        if(row-1 >= 0 && grid[row-1][col] == 1 && vis[row-1][col] == -1) {
            vis[row-1][col] = 1;
            cur += solve(ans, 1, row-1, col, grid, m, n);
        }   
        if(col+1 < m && grid[row][col+1] == 1 && vis[row][col+1] == -1) {
            vis[row][col+1] = 1;
            cur += solve(ans, 1, row, col+1, grid, m, n);
        }   
        if(col-1 >= 0 && grid[row][col-1] == 1 && vis[row][col-1] == -1) {
            vis[row][col-1] = 1;
            cur += solve(ans, 1, row, col-1, grid, m, n);
        }
        ans = max(cur,ans);
        // cout << row << col << ans << endl;
        return ans;

    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        memset(vis, -1, sizeof(vis));
        int m = grid[0].size();
        int n = grid.size();
        int cur = 0;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(vis[i][j] == -1 && grid[i][j] == 1) {
                    cur++;
                    vis[i][j] = 1;
                    ans = max(ans,solve(0, 1, i, j, grid, m, n));
                    cur--;
                }
            }
        }
        return ans;
    }
};