//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    int vis[501][501];
    int M, N;
    int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    bool isValid(int i, int j) {
        return i >= 0 && i < N && j >= 0 && j < M;
    }
    
    void solve(vector<vector<int>>& grid, vector<pair<int,int>> &cur, int row, int col, int row0, int col0) {
        vis[row][col] = 1;
        for(auto dir : dirs) {
            int i = dir[0] + row;
            int j = dir[1] + col;
            if(isValid(i,j) && !vis[i][j] && grid[i][j]) {
                cur.push_back({i-row0, j-col0});
                solve(grid, cur, i, j, row0, col0);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        N = grid.size();
        M = grid[0].size();
        set<vector<pair<int, int>>> st;
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(!vis[i][j] && grid[i][j]) {
                    vector<pair<int,int>> v = {{0,0}};
                    solve(grid, v, i, j, i, j);
                    st.insert(v);
                }
            }
        }
        
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends