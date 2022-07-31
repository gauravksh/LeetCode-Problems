class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = pushed.size();
        int m = popped.size();
        int i = 0, j = 0;
        while(i < m && j < n) {
            if(i < m) st.push(pushed[i++]);
            while(j < n && st.size() > 0 && st.top() == popped[j]) {
                st.pop();
                j++;
            }
        }
        if(j < n) return false;
        return true;
    } 
};