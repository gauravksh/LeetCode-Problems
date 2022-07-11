class Solution {
    int dp[1005];
    
    int helper(vector<int>& cost, int idx, int minVal) {
        if(idx >= cost.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        // minVal += cost[idx];
        
        return dp[idx] = cost[idx] + min(helper(cost, idx + 1, minVal), helper(cost, idx + 2, minVal));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // int idx = min()
        memset(dp,-1,sizeof(dp));
        return min(helper(cost, 0, 0), helper(cost, 1, 0));   
    }
};