class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int ans = (nums[0]%2 ? -1 : nums[0]), cnt = 1, freq = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[i-1] || nums[i]%2) {
                if(cnt > freq) {
                    ans = nums[i-1];
                    freq = cnt;
                }
                if(nums[i]%2 == 0 && ans == -1) ans = nums[i];
                cnt = 1;
            }
            else {
                cnt++;
                if(cnt > freq) {
                    ans = nums[i-1];
                    freq = cnt;
                }
            }
        }
        
        return ans;
    }
};