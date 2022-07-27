class Solution {
public:
    string reverseOnlyLetters(string s) {
        stack <char> st;
        for(auto x : s) {
            if(isalpha(x)) st.push(x);
        }
        for(int i = 0; i < s.length(); i++) {
            if(isalpha(s[i])) {
                s[i] = st.top();
                st.pop();
            }
        }
        return s;
    }
};