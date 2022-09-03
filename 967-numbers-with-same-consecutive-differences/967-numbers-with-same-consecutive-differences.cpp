class Solution {
    vector<int> res;
    void solve(vector<int>& pos, string num, int n, int k) {
        if(num.size() == n) {
            int cur = stoi(num);
            res.push_back(cur);
            return;
        }
        char j;
        string temp;
        for(int i = 0; i < pos.size(); i++) {
            j = pos[i] + '0';
            if(j == '0' && num == "") continue;
            if(num == "" || abs(num.back() - j) == k) {
                temp = num;
                num += j;
                solve(pos, num, n, k);
                num = temp;
            }
        }
    }
    
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> pos(10);
        iota(begin(pos), end(pos), 0);
        solve(pos, "", n, k);
        return res;
    }
};