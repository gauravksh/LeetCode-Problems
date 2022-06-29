class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minVal = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            nums[i]+= nums[i-1];
            if (nums[i] < minVal) minVal = nums[i];
        }
        return (1 - minVal < 1) ? 1 : 1 - minVal; 
    }
};