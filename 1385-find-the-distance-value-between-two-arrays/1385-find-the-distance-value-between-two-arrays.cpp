class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(begin(arr2), end(arr2));
        int cnt = 0;
        for(int i = 0; i < arr1.size(); i++) {
            int val = arr1[i];
            auto idx = upper_bound(arr2.begin(), arr2.end(), val + d);
            auto idx2 = lower_bound(arr2.begin(), arr2.end(), val - d);
            if(idx == idx2) cnt++;
        }
        return cnt;
    }
};