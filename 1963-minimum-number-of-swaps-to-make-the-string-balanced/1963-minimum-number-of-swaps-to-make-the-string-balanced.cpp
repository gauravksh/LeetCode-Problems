class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        for(char ch : s) {
            if(ch == '[') st.push(ch);
            else if(st.size() > 0 && st.top() == '[') st.pop();
            else st.push(ch);
        }
        int bal = st.size()/2;
        return ceil(bal*1.0/2);
    }
};