class Solution {
public:
    int nextGreaterElement(int n) {
        string dig = to_string(n);
        int idx = -1;
        for(int i = dig.size() - 2; i >= 0; i--) {
            if(dig[i] < dig[i+1]) {
                idx = i;
                break;
            }
        }
        if(idx == -1) return -1;
        for(int i = dig.size() - 1; i >= idx + 1; i--) {
            if(dig[i] > dig[idx]) {
                swap(dig[i], dig[idx]);
                break;
            }
        }
        reverse(dig.begin() + idx + 1, dig.end());
        long long ans = stoll(dig);
        
        return ans > INT_MAX ? -1 : ans;
    }
};