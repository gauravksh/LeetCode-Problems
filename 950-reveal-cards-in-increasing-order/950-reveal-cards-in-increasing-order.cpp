class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int> ans(n);
        queue<int> q;
        for(int i = 0; i < n; i++) q.push(i);
        sort(begin(deck), end(deck));
        for(int i = 0; i < n; i++) {
            ans[q.front()] = deck[i];
            q.pop();
            if(!q.empty()) {
                int val = q.front();
                q.pop();
                q.push(val);
            }
        }
        return ans;
    }
};