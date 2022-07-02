class Solution {
    const int mod = 1e9+7;
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        long long maxHcut = max(horizontalCuts[0],h - horizontalCuts[horizontalCuts.size()-1]),maxVcut = max(verticalCuts[0],w-verticalCuts[verticalCuts.size()-1]);
        
        for (int i = 0; i < horizontalCuts.size()-1; i++) {
            if (horizontalCuts[i+1] - horizontalCuts[i] > maxHcut)
                maxHcut = horizontalCuts[i+1] - horizontalCuts[i];
        }
        for (int i = 0; i < verticalCuts.size()-1; i++) {
            if (verticalCuts[i+1] - verticalCuts[i] > maxVcut)
                maxVcut = verticalCuts[i+1] - verticalCuts[i];
        }
        // cout << maxVcut;
        return (maxVcut * maxHcut) % mod ;
    }
};