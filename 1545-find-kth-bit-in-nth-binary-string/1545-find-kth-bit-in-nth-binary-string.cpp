class Solution {
    string solve(int n) {
        if (n == 1) return "0";
        string prev = solve(n-1);
        string inv = prev;
        invert(inv);
        // cout << prev << " " << inv << endl;
        reverse(inv.begin(),inv.end());
        return prev + "1" + inv;
    }
    
    void invert(string &nums) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i]=='0') nums[i] = '1';
            else nums[i] = '0';
        }
    }
    
public:
    char findKthBit(int n, int k) {
        if (n == 1) return '0';
        string res = solve(n);
        return res[k-1];
    }
};