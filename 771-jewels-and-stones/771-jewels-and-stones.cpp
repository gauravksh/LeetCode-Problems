class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> j(jewels.begin(), jewels.end());
        int cnt = 0;
        
        for(auto a : stones) {
            if(j.find(a) != j.end()) cnt++;
        }
        return cnt;
    }
};