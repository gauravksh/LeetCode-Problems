class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int cnt = 0, n = arr.size();
        unordered_map<int,int> mp;
        for(int x : arr) {
            mp[x]++;
        }
        sort(arr.begin(), arr.end());
        for(int x : arr) {
            if(mp[x]) {
                mp[x]--;
                if(x < 0 && x%2 == 0) {
                    if(mp[x/2]) {
                        cnt += 2;
                        mp[x/2]--;
                    } 
                }
                else if(mp[2*x]) {
                    cnt += 2;
                    mp[2*x]--;
                }
            }
        }
        return cnt == n;
    }
};