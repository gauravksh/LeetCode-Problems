class Solution {
    void solve(vector<vector<string>>& ans, vector<string>& cur, int col, vector<int>& row, vector<int>& upDiagonal, vector<int>& lowDiagonal, int& n) {
        
        if(col == n) {
            ans.push_back(cur);
            return;
        }
        
        for(int i = 0; i < n; i++) {
            if(row[i] != 1 && lowDiagonal[col + i] != 1 && upDiagonal[n-1 + col-i] != 1) {
                row[i]++;
                upDiagonal[n-1 + col-i]++;
                lowDiagonal[col+i]++;
                cur[i][col] = 'Q';
                // cout<< cur << " ";
                solve(ans, cur, col + 1, row, upDiagonal, lowDiagonal, n);
                cur[i][col] = '.';
                lowDiagonal[col+i]--;
                upDiagonal[n-1 + col-i]--;
                row[i]--;
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n,'.');
        vector<string> cur(n, s);
        vector<int> row(n);
        vector<int> upDiagonal(2*n - 1);
        vector<int> lowDiagonal(2*n - 1);
        solve(ans, cur, 0, row, upDiagonal, lowDiagonal, n);
        
        return ans;
    }
};