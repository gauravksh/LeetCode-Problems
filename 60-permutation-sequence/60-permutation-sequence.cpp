class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> v;
        for(int i = 1; i <= n; i++) {
            fact*= i;
            v.push_back(i);
        }
        string res = "";
        int idx = fact/n;
        k--;
        // cout << res + to_string(v[(k-1)/idx]);
        while(true) {
            res += to_string(v[k/idx]);
            // cout << (k-1)/idx;
            v.erase(v.begin() + k/idx);
            if(v.size() == 0) break;
            k = k % idx;
            n--;
            idx = idx/n;
            cout << k<< n;
        }
        return res;
    }
};