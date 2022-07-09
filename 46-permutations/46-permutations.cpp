class Solution {
    void solve(vector<vector<int>>& ans, vector<int> &cur, vector<int>& freq, vector<int>& nums) {
        if(cur.size() == nums.size()) {
            ans.push_back(cur);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if (!freq[i]) {
                freq[i]++;
                cur.push_back(nums[i]);
                solve(ans, cur, freq, nums);
                cur.pop_back();
                freq[i]--;
            }
        }
        
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        vector<int> freq(nums.size() + 1);
        vector<vector<int>> ans;
        solve(ans, cur, freq, nums);
        
        return ans;
    }
};