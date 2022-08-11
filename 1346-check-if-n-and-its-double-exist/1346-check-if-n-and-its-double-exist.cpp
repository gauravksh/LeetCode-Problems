class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(int x : arr) {
            mp[x]++;
        }
        for(int x : arr) {
            if(mp.find(2*x) != mp.end()) {
                if(x == 0 && --mp[2*x]) return true;
                else if(x != 0) return true;
            }
        }
        
        return false;
    }
};