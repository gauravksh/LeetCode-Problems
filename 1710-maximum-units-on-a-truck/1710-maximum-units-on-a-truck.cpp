class Solution {
    static bool comparator(vector<int> a,vector<int> b) {
        return a[1] > b[1];
    }
    
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort (boxTypes.begin(),boxTypes.end(),comparator);
        int maxUnits = 0, totBoxes = 0, i = 0;
        
        while(totBoxes <= truckSize && i < boxTypes.size()) {
            totBoxes += boxTypes[i][0];
            maxUnits += boxTypes[i][0]*boxTypes[i++][1];
        }
        if (totBoxes > truckSize) 
            return maxUnits - (totBoxes - truckSize) * boxTypes[--i][1];
        else return maxUnits;
    }
};