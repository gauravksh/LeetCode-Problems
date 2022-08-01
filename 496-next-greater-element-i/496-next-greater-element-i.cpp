class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        for(int i = 0; i < nums2.size(); i++) {
            mp[nums2[i]] = i;
        }
        vector<int> ans(nums1.size());
        for(int i = 0; i < nums1.size(); i++) {
            int idx = mp[nums1[i]];
            int val = nums1[i];
            for(int j = idx+1; j < nums2.size(); j++) {
                if(nums2[j] > val) {
                    ans[i] = nums2[j];
                    break;
                }
            }
            if(ans[i] == 0) ans[i] = -1;
        }
        return ans;
    }
};