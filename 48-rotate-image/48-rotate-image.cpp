class Solution {
private:   
    void transpose(vector<vector<int>>& m, int &n) {
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                swap(m[i][j], m[j][i]);
            }
        }
    }
    
    void reflect(vector<vector<int>>& m, int&n) {
        for(auto &arr : m) {
            reverse(arr.begin(), arr.end());
        }
    }
    
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();    
        transpose(matrix, n);
        reflect(matrix, n);
    }
};