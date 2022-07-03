class Solution {
    vector<vector<int>> ans;
public:
    void solve(vector<int>& candidates, vector<int> &cur, int target , int idx) {
        if (idx >= candidates.size())   return;
        if (target == 0) {
            ans.push_back(cur);
            return;
        }
        
        if (candidates[idx] <= target) {
            cur.push_back(candidates[idx]);
            solve(candidates, cur, target - candidates[idx], idx);
            cur.pop_back();
        }
        solve(candidates, cur, target, idx + 1);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        // sort(candidates.begin(),candidates.end());
        solve(candidates, cur, target,0);
        
        return ans;
    }
};