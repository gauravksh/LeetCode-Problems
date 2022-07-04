class Solution {
    void solve(vector<int> &res, int k, int idx) {
        if(res.size()<=1) return;
        int temp = (idx + k) % res.size();
        res.erase(res.begin() + temp);
        solve(res, k, temp);
    }
public:
    int findTheWinner(int n, int k) {
        vector<int> res(n);
        iota(res.begin(),res.end(),1);
        solve(res,k-1,0);
        
        return res[0];
    }
};

// 1 2 3 4 5 6 7 8 9
//     k k k   k  k k