class Solution {
    bool isPowerOf2(string num) {
        int n = stoi(num);
        if((n & (n-1)) == 0) return true;
        return false;
    }
    
public:
    bool reorderedPowerOf2(int n) {
        string num = to_string(n);
        sort(begin(num), end(num));
        if(num[0] != '0' && isPowerOf2(num)) return true;
        
        while(next_permutation(num.begin(), num.end())) {
            if(num[0] == '0') continue;
            if(isPowerOf2(num)) return true;
        }
        
        return false;
    }
};