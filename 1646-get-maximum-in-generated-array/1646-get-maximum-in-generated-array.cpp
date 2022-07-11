class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> nums(n+2);
        if(n < 2) return n;
        nums[1] = 1;
        for(int i = 1; i <= n/2; i++) {
            nums[2*i] = nums[i];
            nums[2*i + 1] = nums[i] + nums[i+1];
        }
        return *max_element(nums.begin(),nums.begin() + n+1);
    }
};