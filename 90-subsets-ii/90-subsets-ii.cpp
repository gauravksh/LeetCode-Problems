class Solution {
    void solve(vector<vector<int>>& ans, vector<int> cur, int idx, vector<int>& nums) {
        ans.push_back(cur);
        for(int i = idx; i < nums.size(); i++) {
            if(i > idx && nums[i] == nums[i-1]) continue;
            cur.push_back(nums[i]);
            solve(ans, cur, i + 1, nums);
            cur.pop_back();
            // cur.pop_back();
            // if(cur.size() > 0) cur.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        solve(ans, cur, 0, nums);
        
        return ans;
    }
};