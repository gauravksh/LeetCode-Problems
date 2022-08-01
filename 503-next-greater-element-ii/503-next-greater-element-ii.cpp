class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n);
        st.push(-1);
        for(int i = n-1; i >= 0; i--) {
            st.push(nums[i]);
        }
        for(int i = n-1; i >= 0; i--) {
            while(st.size() > 1 && st.top() <= nums[i]) st.pop();
            ans[i] = st.top();
            st.push(nums[i]);
        }
        return ans;
    }
};