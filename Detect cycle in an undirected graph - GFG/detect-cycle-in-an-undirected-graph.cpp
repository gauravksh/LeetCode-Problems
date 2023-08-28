//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int vis[100001] = {0};
    bool solve(int node, vector<int> adj[]) {
        vis[node] = 1;
        queue<pair<int, int>> q;
        q.push({node, -1});
        
        while(!q.empty()) {
            int src = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto x : adj[src]) {
                if(!vis[x]) vis[x] = 1, q.push({x,src});
                else if(x != parent) return true;
            }
        }
        
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        for(int i = 0; i < V; i++) {
            if(!vis[i]) if(solve(i, adj)) return true;
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends