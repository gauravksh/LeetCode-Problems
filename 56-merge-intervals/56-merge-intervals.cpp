class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        stack<int> st;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int start, end;
        for(auto x : intervals) {
            if(st.size() && st.top() >= x[0]) {
                if(x[1] > st.top()) {
                    st.pop();
                    st.push(x[1]);
                }
            }
            else {
                if(!st.empty()) {
                    end = st.top();
                    st.pop();
                    start = st.top();
                    st.pop();
                    ans.push_back({start,end});
                    st.push(x[0]);
                    st.push(x[1]);
                }
                else {
                    st.push(x[0]);
                    st.push(x[1]);
                }
            }
        }
        if(!st.empty()) {
            end = st.top();
            st.pop();
            start = st.top();
            st.pop();
            ans.push_back({start,end});
        }
        return ans;
    }
};