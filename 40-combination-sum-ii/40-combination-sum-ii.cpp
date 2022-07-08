class Solution {
    void solve(set<vector<int>> &ans, vector<int> &cur, vector<int> &arr, int target, int idx) {
        if(target  < 0) return;
        if(idx >= arr.size()) return;
        if(arr[idx] == target) {
            cur.push_back(arr[idx]);
            ans.insert(cur);
            cur.pop_back();
            return;
        }
        cur.push_back(arr[idx]);
        solve(ans, cur, arr, target - arr[idx], idx + 1);
        cur.pop_back();
        int i = idx;
        while(i < arr.size() && arr[i] == arr[idx]) i++;
        solve(ans, cur, arr, target, i);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        set<vector<int>> ans;
        vector<int> cur;
        solve(ans, cur, candidates, target, 0);
        vector<vector<int>> res;
        for(auto x : ans) {
            res.push_back(x);
        }
        
        return res;
    }
};