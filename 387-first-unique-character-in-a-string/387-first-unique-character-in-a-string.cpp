class Solution {
public:
    int firstUniqChar(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int mp[256] = {};
        for(char x : s) mp[x]++;
        for(int i = 0; i < s.size(); i++) {
            if(mp[s[i]] == 1) return i; 
        }
        
        return -1;
    }
};