class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n-1; i += 2) {
            ans += nums[i];
        }
        return ans;
    }
};