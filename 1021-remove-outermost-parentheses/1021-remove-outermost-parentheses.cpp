class Solution {
public:
    string removeOuterParentheses(string s) {
        int op = 0;
        string ans = "";
        for(char ch : s) {
            if(ch == '(' && op++ >= 1) ans += ch;
            if(ch == ')' && --op >= 1) ans += ch; 
        }
        return ans;
    }
};