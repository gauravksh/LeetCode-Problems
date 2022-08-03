class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = 0;
        int val = tickets[k];
        for(int i = 0; i < tickets.size(); i++) {
            if(tickets[i] <= val - 1) ans += tickets[i];
            else ans += val - 1;
        }
        for(int i = 0; i <= k; i++) {
            if(tickets[i] >= val) ans++;
        }
        return ans;
    }
};