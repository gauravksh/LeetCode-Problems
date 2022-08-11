class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        cin.tie(nullptr);
        int cnt = 0;
        unordered_set<int> st;
        for (int x : arr) {
            if (x == 0) {
                cnt++;
                continue;
            }
            st.insert(x);
        }
        
        if (cnt >= 2) return true;
        for (int x : arr) {
            if (st.find(2*x) != st.end()) return true;
        }
        return false;
    }
};