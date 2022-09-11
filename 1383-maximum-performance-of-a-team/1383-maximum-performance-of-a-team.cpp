class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> eff;
        int mod = 1e9 + 7;
        for(int i = 0; i < n; i++) {
            eff.push_back(make_pair(efficiency[i], speed[i]));
        }
        sort(rbegin(eff), rend(eff));
        priority_queue<int, vector<int>, greater<int>> pq;
        long sum = 0, res = 0;
        for(auto x : eff) {
            sum += x.second;
            pq.push(x.second);
            if(pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            res = max(res, sum * x.first);
        }
        
        return res % mod;
    }
};