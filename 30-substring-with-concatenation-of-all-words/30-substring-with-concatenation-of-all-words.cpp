class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> mp;
        for(auto x : words) {
            mp[x]++;
        }
        int n = s.size();
        int wordLen = words[0].size();
        int totalLen = words.size() * wordLen;
        int left = 0, right = 0;
        auto temp = mp;
        string sub;
        vector<int> res;
        
        while (left < (n - totalLen + 1) && right < (n - wordLen + 1)) {
            sub = s.substr(right, wordLen);
            if(temp.find(sub) != temp.end()) {
                if(!temp[sub]) {
                    left++;
                    right = left;
                    temp = mp;
                }
                else {
                    temp[sub]--;
                    right += wordLen;
                }
            }
            else {
                left++;
                right = left;
                temp = mp;
            }
            if(right - left == totalLen) {
                res.push_back(left);
                temp = mp;
                left++;
                right = left;
            }
        }
        
        return res;
    }
};