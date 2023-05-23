//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
 bool bfs(int start, vector<int> adj[],vector<int> &vis){
     	    queue<int> q;
	    q.push(start);
	    vis[start]=0;
	    while(!q.empty()){
	        int cur=q.front();
	        q.pop();
	        for(auto it: adj[cur]){
	            if(vis[it]==-1){
	                vis[it]=!vis[cur]; 
	                q.push(it);
	            }
	            else if(vis[it]==vis[cur]) return false;
	            
	        }
	    }
	    return true;
 }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    
        vector<int> vis(V,-1);
        for(int i=0; i<V; i++){
            if(vis[i]==-1)
            if(bfs(i,adj,vis)==false) return false;
        }
	    return true;
	    
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends