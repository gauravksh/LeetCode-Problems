class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> cur(2,-1);
        int n = nums.size();
        if(n == 0) return cur;
        int start = 0, end = n - 1;
        int mid;
        while(start < end) {
            mid = start + (end - start)/2;
            // if(target == nums[mid]) break;
            if(target > nums[mid]) start = mid + 1;
            else end = mid;
        }
        if(target != nums[start]) return cur;
        cur[0] = start;
        end = n - 1;
        while(start < end) {
            mid = start + (end - start)/2 + 1;
            if(target < nums[mid]) end = mid - 1;
            else start = mid;
        }
        cur[1] = end;
        return cur;
    }
};