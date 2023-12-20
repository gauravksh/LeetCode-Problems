class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size(), minIdx = 0;
        for(int i = 0; i < n; i++) {
            minIdx = i;
            for(int j = i+1; j < n; j++) {
                if(nums[j] < nums[minIdx]) minIdx = j;   
            }
            swap(nums[minIdx], nums[i]);
        }
    }
};