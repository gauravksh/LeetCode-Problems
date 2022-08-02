class Solution {
    int dp[1005][1005];
    int isPal(int i, int j, string& s) {
        if(dp[i][j] != -1) return dp[i][j]; 
        else {
            if(i == j) return dp[i][j] = 1;
            if(j - i == 1 && s[i] == s[j]) return dp[i][j] = 1;
            if(s[i] == s[j]) {
                if(j > 0 && i < s.length()) return isPal(i + 1, j - 1, s);
            }
            return dp[i][j] = 0;
        }
    }
public:
    int countSubstrings(string s) {
        memset(dp, -1, sizeof(dp));
        int n = s.length();
        int cnt = 0;
        // dp[0][0] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(isPal(i, j, s)) cnt++;
            }
        }
        return cnt;
    }
};