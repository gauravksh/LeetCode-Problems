class Solution {
public:
    vector<int> diStringMatch(string s) {
        int l = 0, r = s.length();
        vector<int> res(r+1);
            
        for(int i = 0; i < s.length(); i++) {
            if (s[i] == 'I')
                res[i] = l++;
            else
                res[i] = r--;        
        }
        
        res[s.length()] = (s.back() == 'I') ? l : r;
        
        return res;
    }
};