class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = INT_MAX;
        int l, r, sum, mid;
        sort(begin(nums), end(nums));
        for(int i = 0; i < n-2; i++) {
            if(i == 0 || nums[i] != nums[i-1]) {
                l = i+1;
                r = n-1;
                while(l < r) {
                    sum = nums[l] + nums[r] + nums[i];
                    if(target - sum == 0) return sum;
                    else if(target - sum < 0) r--;
                    else l++;
                    if(ans == INT_MAX) ans = sum;
                    else ans = (abs(target - ans) < abs(target - sum)) ? ans : sum;
                }
            }
        }
        
        return ans;
    }
};