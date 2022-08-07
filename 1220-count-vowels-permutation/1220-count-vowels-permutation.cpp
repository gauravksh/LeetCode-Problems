class Solution {
public:
    int countVowelPermutation(int n) {
        long long mod = 1e9 + 7;
        long long dp[2][5];
        for(int i = 0; i < 5; i++) {
            dp[0][i] = 1;
        }
        int prev, next;
        for(int i = 1; i < n; i++) {
            prev = (i&1 ? 0 : 1);
            next = (i&1 ? 1 : 0);
            dp[next][0] = dp[prev][1] % mod;
            dp[next][1] = (dp[prev][0] + dp[prev][2]) % mod;
            dp[next][2] = (dp[prev][0] + dp[prev][1] + dp[prev][3] + dp[prev][4]) % mod;
            dp[next][3] = (dp[prev][2] + dp[prev][4]) % mod;
            dp[next][4] = dp[prev][0] % mod;
        }
        long long res = 0;
        for(int i = 0; i < 5; i++) {
            res = (res + dp[next][i]) % mod;
        }
        return res;
    }
};