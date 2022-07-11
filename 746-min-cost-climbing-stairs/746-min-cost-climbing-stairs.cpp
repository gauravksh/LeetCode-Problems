class Solution {
public:
    int minCostClimbingStairs(vector<int>& nums) {
        nums.push_back(0);
        int dp[nums.size() + 1];
        dp[0] = 0;
        dp[1] = 0;
        for(int i = 2; i <= nums.size(); i++) {
            // dp[i] = nums[i];
            dp[i] = min(nums[i-1] + dp[i-1], dp[i-2] + nums[i-2]);
        }
        return dp[nums.size()-1];
    }
};