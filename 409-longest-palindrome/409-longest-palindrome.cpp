class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(char ch : s) {
            mp[ch]++;
        }
        bool flag = false;
        int ans = 0, cnt = 0;
        for(auto &it : mp) {
            if(it.second&1) {
                ans += it.second - 1;
                flag = true;
            }
            else ans += it.second;
        }
        if(flag) ans++;
        return ans;
    }
};