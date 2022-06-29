class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        int l = 0 , r = 0;
        string res;
        
        while(l < n && r < m) {
            res.push_back(word1[l++]);
            res.push_back(word2[r++]);
        }
        
        while(l < n) res.push_back(word1[l++]);
        while(r < m) res.push_back(word2[r++]);
        
        return res;
    }
};