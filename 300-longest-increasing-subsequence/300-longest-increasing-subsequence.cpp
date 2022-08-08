class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    //     set<pair<int,int>> s;
    //     int num;
    //     int ans = 1;
    //     for(int i = 0; i < nums.size(); i++) {
    //         num = nums[i];
    //         auto lowBound = s.lower_bound({num, i});
    //         // lowBound--;
    //         cout << lowBound->first;
    //         while(lowBound != s.begin() && (lowBound->first < num)) {
    //             lowBound--;
    //         }
    //         if(lowBound == s.begin()) s.insert({num, 1});
    //         else {
    //             s.insert({num, lowBound->second + 1});
    //             ans = max(ans, lowBound->second + 1);
    //         }
    //     }
    //     return ans;
        int ans = 1;
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    ans = max(ans, dp[i]);
                }
            }
        }
        return ans;
    }
};