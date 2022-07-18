class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> pref(m+1, vector<int>(n+1));
        
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + matrix[i-1][j-1];
                cout << pref[i][j] << " ";
            }
            cout << endl;
        }
        int res = 0;
        unordered_map<int,int> mp;
        for(int r1 = 1; r1 <= m; r1++) {
            for(int r2 = r1; r2 <= m; r2++) {
                mp.clear();
                mp[0] = 1;
                int sum = 0;
                for(int c1 = 1; c1 <= n; c1++) {
                    sum = pref[r2][c1] - pref[r1-1][c1];
                    res += mp[sum - target];
                    mp[sum]++;
                }
                
            }
        }
        return res;
    }
};