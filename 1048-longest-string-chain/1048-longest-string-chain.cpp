class Solution {
    static bool comp(string &a, string &b) {
        return a.size() < b.size();
    }
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> mp;
        sort(words.begin(), words.end(), comp);
        string s;
        int ans = 0;
        for(auto word : words) {
            for(int i = 0; i < word.length(); i++) {
                s = word.substr(0,i);
                s += word.substr(i+1);
                if(mp[s] > 0) mp[word] = max(mp[word],mp[s]+1);
                mp[word] = max(mp[word],1);
            }
            ans = max(ans, mp[word]);
        }
        
        return ans;
    }
};