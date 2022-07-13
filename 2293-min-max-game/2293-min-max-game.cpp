class Solution {
    int solve(vector<int>& nums, vector<int>& newNums, int n) {
        cout<< nums[n-1];
        // if(n == 2) return min(nums[0],nums[1]);
        if(n == 1) return nums[0];
        for(int i = 0; i < n/2; i++) {
            
            if(!(i&1)) newNums[i] = min(nums[2*i], nums[2*i + 1]);
            else newNums[i] = max(nums[2*i], nums[2*i + 1]);
            // cout<< newNums[i];
        }
        return solve(newNums, newNums, n/2);
    }
public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> newNums(n/2);
        return solve(nums, newNums, n);
    }
};