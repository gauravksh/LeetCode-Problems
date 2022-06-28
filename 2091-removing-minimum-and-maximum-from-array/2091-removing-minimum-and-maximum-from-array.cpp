class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return 1;
        }
        int mx = INT_MIN,mxInd,mn = INT_MAX,mnInd;
        
        for(int i = 0; i<n; i++) {
            if (nums[i] > mx) {
                mx = nums[i];
                mxInd = i;
            }
            if (nums[i] < mn) {
                mn = nums[i];
                mnInd = i;
            }
        }
        
        if (mxInd < mnInd) swap(mnInd,mxInd);
        int delR,delL,delMix,ans;
        
        delL = n - mnInd;
        delR = mxInd + 1;
        
        delMix = mnInd + 1 + n - mxInd;
        
        ans = min({delR,delL,delMix});
        return ans;
    }
};