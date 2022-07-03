class Solution {
    vector<vector<int>> ans;
public:
    void solve(vector<int>& candidates, vector<int> &cur, int target , int idx) {
        // base case
        if (target == 0) {
            ans.push_back(cur);
            return;
        }
        
        for (int i = idx; i < candidates.size(); i++) {
            if (candidates[i] <= target) {
                cur.push_back(candidates[i]);
                solve(candidates, cur, target - candidates[i], i);
                cur.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        // sort(candidates.begin(),candidates.end());
        solve(candidates, cur, target,0);
        
        return ans;
    }
};