class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int n = arr.size();
        vector<pair<int,int>> v;
        for (int i = 0; i < arr.size(); i++) {
            v.push_back({abs(x - arr[i]), arr[i]});
        }
        
        sort(v.begin(), v.end());
        vector<int> res;
        for(int i = 0; i < k; i++) {
            res.push_back(v[i].second);
        }
        
        sort(res.begin(), res.end());
        return res;
    }
};