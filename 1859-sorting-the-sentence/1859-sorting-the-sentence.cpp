class Solution {
public:
    string sortSentence(string s) {
        stringstream ss(s);
        string word;
        int len = 0, cnt = 0;
        unordered_map<int, string> mp;
        while(ss >> word) {
            len = word.length() - 1;
            mp[word[len] - '0'] = word.substr(0, len);
            cnt++;
        }
        string ans = "";
        for(int i = 1; i <= cnt; ++i) {
            ans += mp[i];
            ans += " ";
        }
        ans.pop_back();
        return ans;
    }
};