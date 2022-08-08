class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(begin(nums), end(nums));
        int l, r, sum;
        for(int i = 0; i < n-2; i++) {
            if(i == 0 || nums[i-1] != nums[i]) {
                l = i+1;
                r = n-1;
                while(l < r) {
                    sum = nums[l] + nums[r];
                    if(sum == -nums[i]) {
                        ans.push_back({nums[i], nums[l], nums[r]});
                        while(l < r && nums[l] == nums[l+1]) l++;
                        while(r > l && nums[r] == nums[r-1]) r--;
                        l++;
                        r--;
                    }
                    else if(sum > -nums[i]) r--;
                    else l++;
                }
            }
        }
        
        return ans;
    }
};