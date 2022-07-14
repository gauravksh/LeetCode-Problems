class Solution {
    void solve(int& ans, int& cur, int idx, int& n, vector<int>& nums) {
        if(idx == n) {
            // cout << cur;
            ans += cur;
            return;
        }
        for(int i = idx; i < n; i++) {
            cur^= nums[i];
            solve(ans, cur, i+1, n, nums);
            cur^= nums[i];
        }
        ans += cur;
    }
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int cur = 0;
        solve(ans, cur, 0, n, nums);
        
        return ans;
    }
};