class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i-1];
        }
        for(int i = 0; i < nums.size(); i++) {
            if(i == 0) {
                if(nums[nums.size()-1] - nums[i] == 0) return i;
            }
            else if(i == nums.size()-1) {
                if(nums[i-1] == 0) return i;
            }
            else {
                if(nums[i-1] == nums[nums.size()-1] - nums[i]) 
                    return i;
            }
        }
        return -1;
    }
};