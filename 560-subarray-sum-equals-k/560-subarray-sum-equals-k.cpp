class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int N = nums.size();
        unordered_map<int,int> mp;
        mp[0] = 1;
        
        int sum = 0, res = 0;
        for (int i = 0; i < N; i++) {
            sum += nums[i];
            res += mp[sum - k];
            mp[sum]++;
        }
        
        return res;
    }
};