class Solution {
    static bool comparator(vector<int> a,vector<int> b) {
        return a[1] > b[1];
    }
    
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort (boxTypes.begin(),boxTypes.end(),comparator);
        int maxUnits = 0;
        
        maxUnits = min(truckSize, boxTypes[0][0]) * boxTypes[0][1];
        truckSize -= boxTypes[0][0];
        
        for (int i = 1; i < boxTypes.size(); i++) {
            int boxes = boxTypes[i][0], units = boxTypes[i][1];
            if (truckSize > 0) {
                maxUnits += min(truckSize, boxes) * units;
                truckSize -= min(truckSize, boxes);
            }
            else {
                break;
            }
        }
        
        return maxUnits;
    }
};