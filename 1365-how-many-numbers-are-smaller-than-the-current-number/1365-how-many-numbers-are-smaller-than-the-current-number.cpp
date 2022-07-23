class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map<int,int> mp;
        auto sorted = nums;
        sort(sorted.begin(), sorted.end());
        
        for(int i = 0; i < nums.size(); i++) {
            if(mp.find(sorted[i]) == mp.end()) mp[sorted[i]] = i;
        }
        for(int i = 0; i < nums.size(); i++) {
            sorted[i] = mp[nums[i]];
        }
        return sorted;
    }
};