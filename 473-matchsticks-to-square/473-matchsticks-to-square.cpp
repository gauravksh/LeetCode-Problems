class Solution {
    bool dp[16];
    bool solve(vector<int>& arr, int curSum, int& target, int sides, int idx, int& n) {
        if(sides == 0) return true;
        if(curSum > target) return false;
        // if(idx == n) return false;
        if(curSum == target) {
            return solve(arr, 0, target, sides - 1, 0, n);
        }
        for(int i = idx; i < n; i++) {
            if(!dp[i]) {
                dp[i] = true;
                curSum += arr[i];
                if(solve(arr, curSum, target, sides, i + 1, n)) return true;
                curSum -= arr[i];
                dp[i] = false;
            }
        }
        return false;
    }
    
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        memset(dp, false, sizeof(dp));
        // for(int i = 1; i < n; i++) matchsticks[i] += matchsticks[i-1];
        int sum = accumulate(matchsticks.begin(), matchsticks.end(),0);
        cout << sum;
        if(sum%4 != 0) return false;
        int target = sum/4;
        // return true;
        // vector<int> cur;
        return solve(matchsticks, 0, target, 3, 0, n);
    }
};