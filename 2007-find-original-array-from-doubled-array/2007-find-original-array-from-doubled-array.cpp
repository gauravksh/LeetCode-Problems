class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        unordered_map<int, int> mp;
        if (changed.size()&1) return {};
        sort(begin(changed), end(changed));
        for(int x : changed) {
            mp[x]++;
        }
        vector<int> ans;
        for(int x : changed) {
            if(mp[x] > 0) {
                mp[x]--;
                if(mp[2*x] > 0) {
                    mp[2*x]--;
                    ans.push_back(x);
                }
                else return {};
            }
        }
        return ans;
    }
};