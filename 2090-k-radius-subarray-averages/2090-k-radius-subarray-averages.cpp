class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        int size = 2*k + 1;
        vector<int> ans(n, -1);
        if(n < size) return ans;
        long sum = 0;
        for(int i = 0; i < k; i++) {
            sum += nums[i];
        }
        for(int i = k; i < n; i++) {
            sum += nums[i];
            if(i >= size-1) {
                ans[i-k] = sum/size;
                sum -= nums[i-size+1];
            }
        }
        
        return ans;
    }
};