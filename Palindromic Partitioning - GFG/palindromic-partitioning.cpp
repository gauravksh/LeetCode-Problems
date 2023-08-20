//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int dp[501][501];
    bool isPalindrome(string &s, int i, int j) {
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    int solve(string &s, int i, int j) {
        if(i >= j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(isPalindrome(s, i, j)) return dp[i][j] = 0;
        int ans = INT_MAX, cur, right, left;
        for(int k = i; k < j; k++) {
            if(dp[i][k] != -1) left = dp[i][k];
            else dp[i][k] = left = solve(s, i, k);
            if(dp[k+1][j] != -1) right = dp[k+1][j];
            else dp[k+1][j] = right = solve(s, k+1, j);
            cur = left + right + 1;
            ans = min(ans, cur);
        }
        
        return dp[i][j] = ans;
    }
    
public:
    int palindromicPartition(string str)
    {
        memset(dp, -1, sizeof(dp));
        return solve(str, 0, str.length()-1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends