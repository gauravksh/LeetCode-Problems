class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        queue<int> q;
        int cnt = 0, sum = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(q.size() == k) {
                if(sum*1.0/k >= threshold) cnt++;
                sum -= q.front();
                q.pop();
            }
            q.push(arr[i]);
            sum += arr[i];
        }
        if(sum*1.0/k >= threshold) cnt++;
        
        return cnt;
    }
};