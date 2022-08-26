class Solution {   
public:
    bool reorderedPowerOf2(int n) {
        unordered_set<string> mp;
        int num;
        string s;
        for(int i = 0; i < 31; i++) {
            num = 1 << i;
            s = to_string(num);
            sort(s.begin(), s.end());
            mp.insert(s);
        }
        s = to_string(n);
        sort(begin(s), end(s));
        return mp.find(s) != mp.end();
    }
};