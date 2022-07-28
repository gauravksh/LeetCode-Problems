class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;
        unordered_set<char> assignedVal;
        for(int i = 0; i < s.length(); i++) {
            if(mp.find(t[i]) != mp.end()) {
                if(mp[t[i]] != s[i]) return false;
            }
            if(mp.find(t[i]) == mp.end() && assignedVal.find(s[i]) != assignedVal.end()) return false;
            mp[t[i]] = s[i];
            assignedVal.insert(s[i]);
        }
        return true;
    }
};