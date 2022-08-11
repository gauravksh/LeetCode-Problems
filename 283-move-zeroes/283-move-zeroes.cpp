class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), i = 0, j = 1;
        
        while(i < n && j < n) {
            if(nums[j] == 0) while(j < n-1 && nums[j] == 0) j++;
            if(nums[i] == 0) swap(nums[i++], nums[j++]);
            else {
                i++;
                if(j <= i) j = i+1;
            }
        }
    }
};