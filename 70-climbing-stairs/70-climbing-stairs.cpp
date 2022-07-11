class Solution {
    int dp[50];
    int solve(int cur, int n) {
        if(cur > n) return 0;
        if(dp[cur] != -1) return dp[cur];
        if(cur == n) return 1;
        return dp[cur] = solve(cur + 1, n) + solve(cur + 2, n);
    }
public:
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(0,n);
    }
};