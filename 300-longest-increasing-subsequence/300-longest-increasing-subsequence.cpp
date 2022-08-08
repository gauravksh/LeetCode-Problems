class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int > v;
        v.push_back(nums[0]);
        for(int i = 1;i < nums.size(); i++){
            auto idx = lower_bound(v.begin(), v.end(),nums[i]);
            if (idx == v.end()) v.push_back(nums[i]);
            else *idx = nums[i];
        }
        
        return v.size();
    }
};