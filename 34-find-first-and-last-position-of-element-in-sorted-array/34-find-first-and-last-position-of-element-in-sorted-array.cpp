class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> cur;
        int i = 0;
        while(i < nums.size() && nums[i] <= target) {
            if (nums[i] == target && cur.empty()) {
                cur.push_back(i);
            }
            i++;
        }
        if(!cur.empty()) cur.push_back(i-1);
        if(cur.empty()) return {-1,-1};
        return cur;
    }
};