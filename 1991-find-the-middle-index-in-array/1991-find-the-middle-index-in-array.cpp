class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size()-1;
        for(int i = 1; i <= n; i++) {
            nums[i] += nums[i-1];
        }
        
        int l = 0, left = 0, right = 0;
        while (l < nums.size()) {
            if (l == 0) {
                left = 0;
                right = nums[n] - nums[0];
            }
            else if (l == nums.size()-1) {
                right = 0;
                left = nums[l-1];
            }
            else {
                left = nums[l-1];
                right = nums[n] - nums[l];
            }
            if(left == right) return l;
            l++;
        }
        
        return -1;
    }   
};