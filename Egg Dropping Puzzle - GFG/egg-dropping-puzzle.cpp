//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int dp[201][201];
    int solve(int k, int n) {
        if(k <= 1) return n;
        if(n <= 1) return n;
        if(dp[k][n] != -1) return dp[k][n];
        int res = INT_MAX, temp;
        for(int i = 1; i <= n; i++) {
            temp = dp[k-1][n-i] != -1 ? dp[k-1][n-i] : solve(k-1, n-i);
            temp = 1 + max(temp, dp[k][i-1] != -1 ? dp[k][i-1] : solve(k, i-1));
            res = min(res, temp);
        }

        return dp[k][n] = res;
    }
    int eggDrop(int k, int n) 
    {
        memset(dp, -1, sizeof(dp));
        return solve(k, n);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends