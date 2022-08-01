class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx = -1, n = nums.size();
        for(int i = n-2; i >= 0; i--) {
            if(nums[i] < nums[i+1]) {
                idx = i;
                break;
            }
        }
        if(idx != -1) {
            for(int i = n-1; i >= idx+1; i--) {
                if(nums[i] > nums[idx]) {
                    swap(nums[i],nums[idx]);
                    break;
                } 
            }
            reverse(begin(nums) + idx + 1, end(nums));
        }
        else sort(begin(nums), end(nums));
    }
};