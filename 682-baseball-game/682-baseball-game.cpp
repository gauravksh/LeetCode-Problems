class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        for(auto op : ops) {
            if(op == "+") {
                int sum = st.top();
                st.pop();
                int val = st.top();
                st.push(sum);
                sum += val;
                st.push(sum);
            }
            else if(op == "D") {
                int val = 2*st.top();
                st.push(val);
            }
            else if(op == "C") {
                st.pop();
            }
            else {
                int val = stoi(op);
                st.push(val);
            }
        }
        int ans = 0;
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};