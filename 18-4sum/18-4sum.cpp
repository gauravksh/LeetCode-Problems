class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int i = 0, j = 0, k = 0,mid = 0, l = 0, n = nums.size();
        long long rem = 0, sum = 0;
        vector<vector<int>> ans;
        
        for(i = 0; i < n; i++){
            for(j = i+1; j < n; j++) {
                rem = nums[i] + nums[j];
                k = j+1;
                l = n-1;
                        
                while(k < l) {
                    
                    sum = rem + nums[k] + nums[l];
                    if(sum == target) {
                        ans.push_back({nums[i], nums[j], nums[l], nums[k]});
                        while(k < l && nums[k] == nums[k+1]) k++;
                        while(l > k && nums[l] == nums[l-1]) l--;
                        l--;
                        k++;

                    }
                    else if(sum - target > 0) l--;
                    else k++;
                }
                
                while(j+1 < n && nums[j] == nums[j+1]) j++;
            }
            while(i+1 < n && nums[i] == nums[i+1]) i++;
        }
        
        return ans;
    }
};