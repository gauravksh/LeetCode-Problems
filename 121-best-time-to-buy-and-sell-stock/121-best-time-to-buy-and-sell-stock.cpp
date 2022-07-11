class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minSell = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            minSell = min(prices[i],minSell);
            profit = max(profit, prices[i] - minSell);
        }
        return profit;
    }
};