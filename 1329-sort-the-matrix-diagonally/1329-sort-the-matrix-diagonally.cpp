class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        unordered_map<int, vector<int>> mp;
        int m = mat.size(), n = mat[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                mp[i-j].push_back(mat[i][j]);
            }
        }
        for(auto &it : mp) {
            sort(begin(it.second), end(it.second), greater<int>());
        }
        int idx = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                idx = mp[i-j].size() - 1;
                mat[i][j] = mp[i-j][idx];
                mp[i-j].pop_back();
            }
        }
        return mat;
    }
};