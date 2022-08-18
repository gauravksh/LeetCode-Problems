class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        
        for (int x : arr) {
            mp[x]++;
        }
        
        vector<int> v;
        for (auto it : mp) {
            v.push_back(it.second);
        }
        
        sort(v.rbegin(), v.rend());
        int res = 0, cnt = n;
        for (int i = 0; i < v.size(); i++) {
            cnt -= v[i];
            res++;
            if (cnt <= n/2) break;
        }
        
        return res;
    }
};