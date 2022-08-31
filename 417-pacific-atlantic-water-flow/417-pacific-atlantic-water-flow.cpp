class Solution {
    int r,c;
    vector<vector<int>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    vector<vector<bool>> vis;
    void dfs(vector<vector<int>>& m, int i, int j, bool &p, bool &a) {
        if(i == 0 || j == 0) p = true;
        if(i == r-1 || j == c-1) a = true;
        if(p && a) return;
        int row, col;
        
        for(auto dir : dirs) {
            row = dir[0] + i;
            col = dir[1] + j;
            if(row < 0 || row >= r || col >= c || col < 0) continue;
            if(m[row][col] <= m[i][j] && !vis[row][col]) {
                vis[row][col] = true;
                dfs(m, row, col, p, a);
                vis[row][col] = false;
            }
        }
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        r = heights.size();
        c = heights[0].size();
        // vector<vector<bool>
        vis.resize(r, vector<bool>(c, false));
        bool a = false, p = false;
        vector<vector<int>> res;
        
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                vis[i][j] = true;
                dfs(heights, i, j, p, a);
                vis[i][j] = false;
                if(p && a) res.push_back({i,j});
                p = false;
                a = false;
            }
        }
        
        return res;
    }
};