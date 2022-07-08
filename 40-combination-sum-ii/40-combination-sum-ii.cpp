class Solution {
    void solve(vector<vector<int>> &ans, vector<int> &cur, vector<int> &arr, int target, int idx) {
        if(target == 0) {
            ans.push_back(cur);
            return;
        }
        for(int i = idx; i < arr.size(); i++) {
            if(i > idx && arr[i] == arr[i - 1]) continue;
            if(arr[i] > target) break;
            cur.push_back(arr[i]);
            solve(ans, cur, arr, target - arr[i], i + 1);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> cur;
        solve(ans, cur, candidates, target, 0);
        return ans;
    }
};