class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<long long> pq;
        int ans = 0, n = stations.size();
        if(n == 0) return target <= startFuel ? 0 : -1;
        int remFuel = startFuel, dist = 0, prevDist = 0;
        
        for(int i = 0; i < n; i++) {
            dist = stations[i][0] - prevDist;
            prevDist = stations[i][0];
            remFuel = remFuel - dist;
            while(remFuel < 0 && !pq.empty()) {
                remFuel += pq.top();
                pq.pop();
                ans++;
            }
            if(remFuel < 0) return -1;
            pq.push(stations[i][1]);
        }
        
        dist = target - prevDist;
        while(remFuel < dist && !pq.empty()) {
            remFuel += pq.top();
            pq.pop();
            ans++;
        }
        
        return dist <= remFuel ? ans : -1;
    }
};