class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int> pos;
        int l = 0, r = 0, res = INT_MAX;
        int n = cards.size();
        
        while (r < n) {
            if (pos.find(cards[r]) != pos.end()) {
                l = pos[cards[r]];
                res = min(res, r - l + 1);
            }
            pos[cards[r]] = r;
            r++;
        }
        return (res == INT_MAX) ? -1 : res;
    }
};