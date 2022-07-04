class Solution {
    vector<string> keys = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    void solve(vector<string>& res, string cur, int idx, int n, string &digits) {
        if(idx == n) {
            res.push_back(cur);
            return;
        }
        int tmp = digits[idx] - '0';
        for(int i = 0; i < keys[tmp].size(); i++) {
            solve(res, cur + keys[tmp][i], idx + 1, n, digits);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) {
            return res;
        }
        int n = digits.length();
        solve(res, "", 0,n, digits);
            
        return res;
    }
};