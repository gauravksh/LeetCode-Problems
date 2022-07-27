class Solution {
public:
    int maxDepth(string s) {
        int cur = 0, res = 0;
        for(auto x :s) {
            if(x == '(') {
                cur++;
                res = max(cur,res);
            }
            if(x == ')') cur--;
        }
        
        return res;
    }
};