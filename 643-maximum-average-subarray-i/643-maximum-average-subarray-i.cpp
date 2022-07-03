class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double res = INT_MIN, temp = 0;
        for(int i = 1; i < nums.size(); i++) {
            nums[i]+= nums[i-1];
        }
        
        for(int i = k - 1; i < nums.size(); i++) {
            if (i == k - 1) temp = nums[i]*1.0/k;
            else temp = (nums[i] - nums[i-k])*1.0/k;
            res = max(temp,res);
        }
        return res;
    }
};