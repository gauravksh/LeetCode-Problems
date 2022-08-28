class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size(), m = queries.size();
        sort(nums.begin(), nums.end());
        for(int i = 1; i < n; i++) {
            nums[i] += nums[i-1];
        }
        vector<int> res(m);
        for(int i = 0; i < m; i++) {
            int val = queries[i];
            res[i] = upper_bound(nums.begin(), nums.end(), val) - nums.begin();
        }
        
        return res;
    }
};