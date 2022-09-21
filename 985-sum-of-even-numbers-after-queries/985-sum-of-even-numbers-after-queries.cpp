class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> ans;
        int sum = 0;
        int cur = 0;
        for(int i = 0; i < n; i++) {
            if(!(nums[i]&1)) sum += nums[i];
        }
        int idx, val;
        for(auto x : queries) {
            idx = x[1];
            val = x[0];
            cur = nums[idx];
            nums[idx] += val;
            if(!(cur&1) && nums[idx]&1) sum -= cur;
            else if(!(cur&1) && !(nums[idx]&1)) sum += val;
            else if(cur&1 && !(nums[idx]&1)) sum += nums[idx];
            ans.push_back(sum);
        }
        
        return ans;
    }
};