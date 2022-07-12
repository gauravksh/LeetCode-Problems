class Solution {
    double calcPow(double x, long long n) {
        if(n == 0) return 1;
        double ans = myPow(x, n/2);
        ans *= ans;
        if(n&1) ans *= x;
        return ans;
    }
public:
    double myPow(double x, int n) {
        if(n < 0) {
            long k = -1 * (long)n;
            return 1/calcPow(x, k);
        }
        return calcPow(x, n);
    }
};