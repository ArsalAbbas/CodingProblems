//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    bool dfs(vector<int> adj[], vector<int> &vis,vector<int> &pathVis, int cur){
        vis[cur]=1;
        pathVis[cur]=1;
        for(int i:adj[cur]){
            if(!vis[i] ){
                if (dfs(adj,vis,pathVis,i)) return true;
            }
            else if(pathVis[i])
                return true;
        }
                pathVis[cur]=0;
        return false;
        
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        vector<int> pathVis(V,0);
        for(int i=0; i<V; i++){
            if(!vis[i]) {
                if(dfs(adj,vis,pathVis,i))
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends