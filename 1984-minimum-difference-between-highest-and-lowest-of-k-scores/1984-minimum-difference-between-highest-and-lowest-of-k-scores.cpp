class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int res = INT_MAX;
        if (nums.size() == 1) return 0;
        for(int i = 0; i <= nums.size() - k; i++) {
            int temp = nums[i+k-1] - nums[i];
            res = min(res,temp);
        }
        
        return res;
    }
};