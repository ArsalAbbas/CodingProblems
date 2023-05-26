//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private: 
    bool dfs(vector<int> adj[],vector<int> &vis, vector<int> &pathVis,int cur,vector<int> &check){
        vis[cur]=1;
        pathVis[cur]=1;
        check[cur]=0;
        for(auto it: adj[cur]){
            if(!vis[it]){

                if(dfs(adj,vis,pathVis,it,check)) return true;
            }
            else if(pathVis[it]==1)
                return true;

        }
        check[cur]=1;
        pathVis[cur]=0;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here

        vector<int> vis(V,0);
        vector<int> pathVis(V,0);
        vector<int> safe;
        vector<int> check(V,0);

        for(int i=0; i<V; i++)
            if(!vis[i]) 
            dfs(adj,vis,pathVis,i,check);

        for(int i=0; i<V; i++){
            if(check[i])
                safe.push_back(i);
        }
        return safe;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends