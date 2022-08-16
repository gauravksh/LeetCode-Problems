class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, n = numbers.size(), right = n-1;
        int sum = 0;
        
        while(left < right) {
            sum = numbers[left] + numbers[right];
            if(sum == target) return {left + 1, right + 1};
            else if(sum < target) {
                left++;
                while(left < right && numbers[left] == numbers[left-1]) {
                    left++;
                }
            }
            else {
                right--;
                while(left < right && numbers[right] == numbers[right+1]) {
                    right--;
                }
            }
        }
        
        return {};
    }
};