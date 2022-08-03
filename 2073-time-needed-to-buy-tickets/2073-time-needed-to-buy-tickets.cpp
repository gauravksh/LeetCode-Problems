class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = 0;
        int val = tickets[k];
        for(int i = 0; i < tickets.size(); i++) {
            if(i <= k) {
                if(tickets[i] <= val) ans += tickets[i];
                else ans += val;
            }
            else {
                if(tickets[i] < val) ans += tickets[i];
                else ans += val - 1;
            }
        }
        return ans;
    }
};