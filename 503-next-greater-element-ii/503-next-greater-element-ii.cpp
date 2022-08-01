class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n);
        st.push(-1);
        for(int i = 2*n-1; i >= 0; i--) {
            while(st.size() > 1 && st.top() <= nums[i%n]) st.pop();
            ans[i%n] = st.top();
            st.push(nums[i%n]);
        }
        return ans;
    }
};