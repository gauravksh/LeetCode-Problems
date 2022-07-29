class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        unordered_map<char,char> mp;
        unordered_set<char> assigned;
        vector<string> res;
        
        for(auto &x : words) {
            mp.clear();
            assigned.clear();
            bool flag = true;
            if(x.size() != pattern.size()) continue;
            for(int i = 0; i < x.size(); i++) {
                if(mp.find(x[i]) != mp.end()) {
                    if(mp[x[i]] != pattern[i]) {
                        flag = false;
                        break;
                    }
                    else continue;
                }
                if(assigned.find(pattern[i]) != assigned.end()) {
                    flag = false;
                    break;
                }
                mp[x[i]] = pattern[i];
                assigned.insert(pattern[i]);
            }
            if(flag) res.push_back(x);
        }
        
        return res;
    }
};