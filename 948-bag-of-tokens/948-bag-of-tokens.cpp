class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0;
        int l = 0, r = tokens.size()-1;
        sort(begin(tokens), end(tokens));
        int ans = 0;
        while(l <= r && (power >= tokens[l] || score)) {
            while(l <= r && power >= tokens[l]) {
                power -= tokens[l++];
                score++;
            }
            ans = max(score, ans);
            if(score && l <= r) {
                score--;
                power += tokens[r--];
            }
        }
        
        return ans;
    }
};