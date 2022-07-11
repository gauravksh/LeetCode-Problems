class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minSell[prices.size()];
        minSell[0] = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            minSell[i] = min(prices[i],minSell[i-1]);
            profit = max(profit, prices[i] - minSell[i-1]);
        }
        return profit;
    }
};