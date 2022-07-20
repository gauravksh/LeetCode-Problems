class Solution {
    
    bool isSubsequence(string& s, string &t) {
        int l = 0, r = 0;
        
        while (l < s.length() && r < t.length()) {
            if(t[r] == s[l]) {
                l++;
                r++;
            }
            else r++;
        }
        return (l == s.length()) ? true : false;
    }
    
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int res = 0;
        unordered_map<string,int> mp;
        for(auto x : words){
            if(mp.find(x) != mp.end()) {
                if(mp[x] > 0) {
                    res++;
                    mp[x]++;
                }
                else continue;
            }
            else {
                if(isSubsequence(x, s)) {
                    res++;
                    mp[x]++;
                }
                else mp[x] = -1;
            }
        }
        
        return res;
    }
};