class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int len = 0;
        for(auto x : intervals) {
            if(len == 0) {
                ans.push_back(x);
                len++;
            }
            else{
                if(ans[len-1][1] >= x[0]) {
                    if(ans[len-1][1] < x[1]) ans[len-1][1] = x[1];
                }
                else {
                    ans.push_back(x);
                    len++;
                }
            }
        }
        return ans;
    }
};