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
            auto it = lower_bound(nums.begin(), nums.end(), val);
            if(it == nums.end()) res[i] = n;
            else if(*it == val) res[i] = (it - nums.begin() + 1);
            else res[i] = (it - nums.begin());
        }
        
        return res;
    }
};