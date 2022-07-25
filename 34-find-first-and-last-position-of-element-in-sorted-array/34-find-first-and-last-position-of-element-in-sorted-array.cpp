class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0, end = n - 1;
        vector<int> cur(2,-1);
        if(n == 0) return cur;
        while(start < end) {
            int mid = start + (end - start)/2;
            if(target > nums[mid]) start = mid + 1;
            else end = mid;
        }
        if(nums[start] != target) return cur;
        cur[0] = start;
        end = n - 1;
        while(start < end) {
            int mid = start + (end - start)/2 + 1;
            if(target  < nums[mid]) end = mid - 1;
            else start = mid;
        }
        cur[1] = end;
        return cur;
    }
};