class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        string ans;
        vector<bool> flag(s.size());
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') st.push(i);
            else if(s[i] == ')') {
                if(!st.empty() && s[st.top()] == '(') {
                    flag[st.top()] = true;
                    flag[i] = true;
                    st.pop();
                }
                else {
                    st.push(i);
                    flag[i] = false;
                }
            }
            else flag[i] = true;
        }

        for(int i = 0; i < s.size(); i++) {
            if(flag[i]) ans += s[i];
        }
        return ans;
    }
};