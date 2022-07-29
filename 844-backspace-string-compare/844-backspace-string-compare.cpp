class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> strS;
        stack<char> strT;
        
        for(char ch : s) {
            if(ch == '#' && !strS.empty()) strS.pop();
            else if(ch != '#') strS.push(ch);
        }
        for(char ch : t) {
            if(ch == '#' && !strT.empty()) strT.pop();
            else if(ch != '#') strT.push(ch);
        }
        if(strS == strT) return true;
        return false;
    }
};