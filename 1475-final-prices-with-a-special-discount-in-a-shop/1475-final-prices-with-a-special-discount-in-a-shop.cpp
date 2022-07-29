class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> s;
        s.push(0);
        int n = prices.size() - 1;
        for(int i = n; i >= 0; i--) {
            int cur = prices[i];
            while(s.top() > cur) s.pop();
            int val = s.top();
            s.push(prices[i]);
            prices[i] -= val;
            }
        return prices;
    }
};