class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size()-1;
        for(int row = 0; row < m; row++) {
            int start = 0;
            int end = n;
            while(start <= end && start <= n && end >= 0) {
                int mid = start + (end - start)/2;
                if(matrix[row][mid] == target) return true;
                else if(target > matrix[row][mid]) start = mid + 1;
                else if(target < matrix[row][mid]) end = mid-1;
            }
        }
        return false;
    }
};