class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int open = 0, mx = 0;
        vector<int> ans(seq.size());
        for(char ch : seq) {
            if(ch == '(') open++;
            else open--;
            mx = max(open,mx);
        }
        open = 0;
        for(int i = 0; i < seq.size(); i++) {
            if(seq[i] == '(' && ++open <= mx/2) {
                ans[i] = 1;
            }
            else if(seq[i] == ')' && open-- <= mx/2) {
                ans[i] = 1;
            }
        }
        return ans;
    }
};