class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char,int> mp;
        vector<string> res;
        for(auto x : words2) {
            unordered_map<char,int> cur;
            for(char ch : x) {
                cur[ch]++;
                if(cur[ch] > mp[ch]) mp[ch] = cur[ch];
            }
        }
        
        for(auto x : words1) {
            auto tmp = mp;
            for(char ch : x) {
                if(tmp.find(ch) != tmp.end()) {
                    tmp[ch]--;
                    if(tmp[ch] == 0) tmp.erase(ch);
                }
            }
            if(tmp.size() == 0) res.push_back(x);
        }
        return res;
    }
};