class Solution {
    bool isValid(int row, int col, vector<vector<char>>& board) {
        char num = board[row][col];
        int cnt = 0;
        for(int i = 0; i < 9; i++) {
            if(num == board[row][i] && i != col) return false;
            if(num == board[i][col] && i != row) return false;
            if(num == board[3*(row/3) + i/3][3*(col/3) + i%3]) {
                cnt++;
                if(cnt > 1) return false;
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                if(!isValid(i, j, board)) {
                    return false;
                }
            }
        }
        return true;
    }
};