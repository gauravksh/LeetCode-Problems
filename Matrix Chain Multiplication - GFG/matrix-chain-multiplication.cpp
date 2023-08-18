//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int dp[101][101];
    int solve(int i, int j, int *arr) {
        if(i >= j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int res = INT_MAX, cur;
        for(int k = i; k < j; k++) {
            cur = solve(i, k, arr) + solve(k+1, j, arr) + arr[i-1] * arr[k] * arr[j];
            res = min(res, cur);
        }
        
        return dp[i][j] = res;
    }
    
public:
    int matrixMultiplication(int N, int arr[])
    {   
        memset(dp, -1, sizeof(dp));
        return solve(1, N-1, arr);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends