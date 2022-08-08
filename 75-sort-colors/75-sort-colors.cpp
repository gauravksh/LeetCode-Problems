class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size(), r = 0, w = 0, b = 0;
        for(int i : nums) {
            if(i == 0) r++;
            else if(i == 1) w++;
            else b++;
        }
        for(int i = 0; i < n; i++) {
            if(r-- > 0) nums[i] = 0;
            else if(w-- > 0) nums[i] = 1;
            else if(b-- > 0) nums[i] = 2;
        }
    }
};