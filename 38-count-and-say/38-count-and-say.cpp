class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string s = countAndSay(n-1);
        string res = "";
        int count = 1;
        
        for(int i = 1; i <= s.length(); i++) {
            if (i == s.length()) res += to_string(count) + s[i-1];
            else if(s[i] == s[i-1]) {
                count++;
            }
            else {
                res += to_string(count) + s[i-1];
                count = 1;
            }
        }
        
        return res;
    }
};