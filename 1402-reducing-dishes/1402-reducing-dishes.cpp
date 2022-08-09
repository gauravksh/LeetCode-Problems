class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        sort(begin(s), end(s));
        int maxx = 0, curMax = 0;
        int n = s.size();
        int cnt = 1, res = 0;
        for(int i = n-1; i >= 0; i--) { 
            curMax += s[i];
            res += curMax;
            maxx = max(maxx, res);
        }
        return maxx;
    }
};