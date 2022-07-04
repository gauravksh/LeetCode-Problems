class Solution {
    void solve(int n, string cur, int open, int close, vector<string>& res) {
        if (cur.length() == 2*n) {
            res.push_back(cur);
            return;
        }
        if (open < n) solve(n, cur + "(", open+1, close,res);
        if (close < open) solve(n, cur + ")", open, close+1, res);
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        solve(n, "", 0, 0, res);
        return res;
    }
};