class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size(), ans = 0, cur = 1, prev = 0;
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i-1]) cur++;
            else {
                prev = cur;
                cur = 1;
            }
            ans += (prev >= cur ? 1 : 0);
        }
        
        return ans;
    }
};