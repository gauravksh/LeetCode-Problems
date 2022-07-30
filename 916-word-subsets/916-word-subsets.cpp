class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> mp(26);
        vector<string> res;
        for(auto x : words2) {
            vector<char> cur(26);
            for(char ch : x) {
                cur[ch - 'a']++;
                if(cur[ch - 'a'] > mp[ch - 'a']) mp[ch - 'a'] = cur[ch - 'a'];
            }
        }
        
        for(auto x : words1) {
            vector<int> tmp(26);
            for(char ch : x) tmp[ch - 'a']++;
            int i;
            for(i = 0; i < 26; i++) {
                if(mp[i] > tmp[i]) break;
            }
            if(i == 26) res.push_back(x);
        }
        return res;
    }
};