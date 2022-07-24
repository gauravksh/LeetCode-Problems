class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size()-1;
        int row = 0;
        int col = n;
        while(row < m && col >= 0) {
            // int mid = start + (end - start)/2;
            if(matrix[row][col] == target) return true;
            else if(target > matrix[row][col]) row++;
            else if(target < matrix[row][col]) col--;
        }

        return false;
    }
};