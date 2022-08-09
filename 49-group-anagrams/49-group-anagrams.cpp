class Solution {

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        string s;
        for(auto x : strs) {
            s = x;
            sort(s.begin(), s.end());
            mp[s].push_back(x);
        }
        for(auto &it : mp) {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};