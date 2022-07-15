class Solution {
    vector<vector<bool>> vis;
    vector<vector<int>> grid;
    int M, N;
    
    int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
public:
    bool isValid(int i, int j) {
        if (i < 0 || j < 0 || i >= M || j >= N ||
            vis[i][j] || grid[i][j] == 0) {
            return false;
        }
        return true;
    }
    
    int dfs(int i, int j) {
        vis[i][j] = true;
        
        int cur_area = 1;
        for (auto dir : dirs) {
            int x = i + dir[0];
            int y = j + dir[1];
            
            if (isValid(x, y)) {
                cur_area += dfs(x, y);
            }
        }
        
        return cur_area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        this->grid = grid;
        M = grid.size(), N = grid[0].size();
        vis = vector<vector<bool>> (M, vector<bool>(N, false));
        
        int max_area = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] && !vis[i][j]) {
                    max_area = max(max_area, dfs(i, j));
                }
            }
        }
        
        return max_area;
    }
};