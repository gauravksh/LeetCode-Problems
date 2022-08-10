class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX, sum = 0, j = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            while(sum >= target) {
                sum -= nums[j];
                ans = min(ans, i - j + 1);
                j++;
            }
        }
        
        return ans == INT_MAX ? 0 : ans;
    }
};