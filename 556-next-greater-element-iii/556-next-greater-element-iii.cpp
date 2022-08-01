class Solution {
public:
    int nextGreaterElement(int n) {
        string dig = to_string(n);
        next_permutation(begin(dig), end(dig));
        long long ans = stoll(dig);
        return (ans > INT_MAX || ans <= n ? -1 : ans);
    }
};