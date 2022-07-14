class Solution {
    bool valid(vector<vector<char>>& board, int row, int col, char ch) {
        for(int i = 0; i < 9; i++) {
            if(ch == board[row][i]) return false;
            if(ch == board[i][col]) return false;
            if(ch == board[3*(row/3) + i/3][3*(col/3) + i%3]) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                    for(char ch = '1'; ch <= '9'; ch++) {
                        if(valid(board, i, j, ch)) {
                            board[i][j] = ch ;
                            if(solve(board)) return true;
                            else board[i][j] = '.';
                        }
                    }
                    // cout <<i<<j;
                return false;
            }
        }
        }
        return true;
    }
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};