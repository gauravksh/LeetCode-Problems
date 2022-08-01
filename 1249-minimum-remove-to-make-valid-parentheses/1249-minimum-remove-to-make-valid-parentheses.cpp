class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>> st;
        string ans;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') st.push({'(', i});
            else if(s[i] == ')') {
                if(!st.empty() && st.top().first == '(') st.pop();
                else st.push({')', i});
            }
        }
        vector<int> flag;
        while(!st.empty()) {
            flag.push_back(st.top().second);
            st.pop();
        }
        int i = 0, m = flag.size(), j = m - 1, n = s.length();
        while(i < n) {
            if(j >= 0 && i == flag[j]) {
                j--;
                i++;
            }
            else {
                ans += s[i++];
            }
        }
        return ans;
    }
};