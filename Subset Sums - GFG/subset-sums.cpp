// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
    void solve(vector<int>& ans,int sum, int idx, vector<int>& arr, int n) {
        if(idx == n) {
            ans.push_back(sum);
            return;
        }
        sum += arr[idx];
        solve(ans, sum, idx + 1, arr, n);
        sum -= arr[idx];
        solve(ans, sum, idx + 1, arr, n);
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        solve(ans, 0, 0, arr, N);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends