class Solution {
public:
    int myAtoi(string s) {
        string num = "";
        bool sign = true, flag = false, sF = true;
        for(int i = 0; i < s.size(); i++) {
            if(isdigit(s[i])) {
                num += s[i];
                flag = true;
            }
            else if(s[i] == '-' && !flag && sF) {
                sign = false;
                sF = false;
                }
            else if(s[i] == '+' && !flag && sF) {
                sign = true;
                sF = false;
                }
            else if(s[i] == ' ' && (flag || !sF)) break;
            else if(!isdigit(s[i]) && s[i] != ' ') break;
        }
        long long ans = 0;
        for(auto ch : num) {
            int digit = ch - '0';
            ans = ans * 10 + digit;
            if(ans > INT_MAX) return (sign) ? INT_MAX : INT_MIN; 
        }
        
        return (sign) ? ans : -ans;
    }
};