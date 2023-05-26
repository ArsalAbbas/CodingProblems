//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    // void dfs(vector<int> &vis,vector<int> adj[], stack<int> &st, int cur){
    //     vis[cur]=1;
    //     for(auto it: adj[cur])
    //         if(!vis[it]){
    //         dfs(vis,adj,st,it);
    //         }
    //         st.push(cur);    
    // }
    //   void bfs(vector<int> &vis,vector<int> adj[], queue<int> &q,vector<int> &ans,vector<int> &indegree){
    //         while(!q.empty()){
    //               int cur=q.front();
    //               q.pop();
    //               ans.push_back(cur);
    //               vis[cur]=1;
    //               for(auto it: adj[cur]){
    //                   indegree[it]--;
    //                   if(indegree[it]==0 &&!vis[it]) 
    //                     q.push(it);
    //               }
    //         }
    // }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   // vector<int> vis(V,0);
	   // stack<int> st;
	    
	   // for(int i=0; i<V; i++)
	   //     if(!vis[i]) dfs(vis,adj,st,i);
	       
	   //vector<int> res; 
	   //while(!st.empty()){
	   //    res.push_back(st.top());
	   //    st.pop();
	   //}
	   vector<int> indegree(V,0);
	   for(int i=0; i<V; i++){
	       for(auto it: adj[i])
	            indegree[it]++;
	   }
	   vector<int> res;
	   queue<int> q;
	   for(int i=0; i<V; i++){
	       if(!indegree[i]) q.push(i);
	   }
	   while(!q.empty()){
                  int cur=q.front();
                  q.pop();
                  res.push_back(cur);

                  for(auto it: adj[cur]){
                      indegree[it]--;
                      if(indegree[it]==0) 
                        q.push(it);
                  }
            }
	   //for(auto it: res) cout<<it<<endl;
	   return res;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends