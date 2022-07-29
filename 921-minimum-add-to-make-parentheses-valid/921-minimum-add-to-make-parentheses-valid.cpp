class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(char ch : s) {
            if(ch == ')') {
                if(!st.empty() && st.top() == '(') st.pop();
                else st.push(ch);
            }
            else st.push(ch);
        }
        int res = 0;
        while(!st.empty()) {
            res++;
            st.pop();
        }
        return res;
    }
};