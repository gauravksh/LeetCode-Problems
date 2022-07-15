class Solution {
    int m,n;
    int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    bool vis[51][51];
    
    bool isValid(int i, int j) {
        if(i < 0 || i >= m || j < 0 || j >=n) return false;
        return true;
    }
    
    void dfs(vector<vector<int>>& image, int row, int col, int val, int& color) {
        
        image[row][col] = color;
        
        for(int i = 0; i < 4; i++) {
            int x = row + dir[i][0];
            int y = col + dir[i][1];
            if(isValid(x, y) && image[x][y] == val && vis[x][y]) {
                vis[x][y] = false;
                dfs(image, x, y, val, color);
            }
        }
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        memset(vis, true, sizeof(vis));
        m = image.size();
        n = image[0].size();
        vis[sr][sc] = false;
        dfs(image, sr, sc, image[sr][sc], color);
        
        return image;
    }
};