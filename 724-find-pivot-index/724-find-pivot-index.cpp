class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int maxSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            maxSum += nums[i];
        }
        int curSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(curSum == maxSum - curSum - nums[i]) return i;
            curSum += nums[i];
        }
        return -1;
    }
};