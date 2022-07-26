class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        
        int res = 0, cur = 0;
        res += mp[s[0]];
        for(int i = 1; i < s.size(); ++i) {
            if(s[i-1] == 'I' && (s[i] == 'V' || s[i] == 'X')) res += mp[s[i]] - 2;
            else if(s[i-1] == 'X' && (s[i] == 'L' || s[i] == 'C')) res += mp[s[i]] - 20;
            else if(s[i-1] == 'C' && (s[i] == 'D' || s[i] == 'M')) res += mp[s[i]] - 200;
            else res += mp[s[i]];
            // cout << res;
        }
        return res;
    }
};