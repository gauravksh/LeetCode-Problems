class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int cur = 0, res = 0;
        int left = 0;
        for(int i = 0; i < fruits.size(); i++) {
            mp[fruits[i]]++;
            cur++;
            if(mp.size() > 2) {
                while(mp.size() > 2 && left < fruits.size()) {
                    if(mp[fruits[left]] == 1) mp.erase(fruits[left]);
                    else mp[fruits[left]]--;
                    left++;
                    cur--;
                }
            }
            res = max(cur, res);
        }
        return res;
    }
};