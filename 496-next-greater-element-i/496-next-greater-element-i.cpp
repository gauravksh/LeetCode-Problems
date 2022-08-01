class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int n = nums1.size(), m = nums2.size();
        st.push(-1);
        unordered_map<int,int> mp;
        for(int i = m - 1; i >= 0; i--) {
            while(st.size() > 1 && st.top() < nums2[i]) st.pop();
            mp[nums2[i]] = st.top();
            st.push(nums2[i]);
        }
        vector<int> res(n);
        for(int i = 0; i < n; i++) {
            res[i] = mp[nums1[i]];
        }
        return res;
    }
};