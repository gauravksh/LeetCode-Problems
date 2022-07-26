class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int cnt = 0;
        for(auto a : jewels) {
            for(auto b : stones) {
                if(a == b) cnt++;
            }
        }
        return cnt;
    }
};