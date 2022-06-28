class Solution {
public:
    string reverseWords(string s) {
        int l = 0, r = 0, n = s.length();
        while (r < n) {
            while (s[r] != ' ' && r < n) {
                r++;
            }
            int tmp = r;
            while (l < r) {
                swap(s[l],s[r-1]);
                l++;
                r--;
            }
            r = tmp + 1;
            l = r;
        }
        return s;
    }
};