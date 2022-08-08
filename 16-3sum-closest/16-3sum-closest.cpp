class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        int ans = nums[0] + nums[1] + nums[2];
        int l, r, sum, mid;
        for(int i = 0; i < n-2; i++) {
            if(i == 0 || nums[i] != nums[i-1]) {
                l = i+1;
                r = n-1;
                while(l < r) {
                    sum = nums[l] + nums[r] + nums[i];
                    if(target - sum == 0) return sum;
                    else if(target - sum < 0) r--;
                    else l++;
                    ans = (abs(target - ans) < abs(target - sum)) ? ans : sum;
                }
            }
        }
        
        return ans;
    }
};