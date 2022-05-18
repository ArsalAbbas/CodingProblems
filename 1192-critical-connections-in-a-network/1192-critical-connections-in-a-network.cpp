class Solution {
public:
    int dfs(vector<vector<int>> &adjlist, int current, int prev, int depth,vector<int> &visited,vector<vector<int>> &output){
        visited[current]=depth;
        int mn = INT_MAX;
        for(int i=0;i<adjlist[current].size();i++){
            int node = adjlist[current][i];
            if(node == prev) continue;
            if(visited[node]){
                mn = min(visited[node],mn);
            }
            else{
                int b = dfs(adjlist,node,current,depth+1,visited,output);
                if(b>depth) output.push_back({current,node});
                mn = min(b,mn);
            }
        }
        return mn;
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adjlist(n,vector<int>());
        for(int i=0;i<connections.size();i++){
            vector<int> edge = connections[i];
            adjlist[edge[0]].push_back(edge[1]);
            adjlist[edge[1]].push_back(edge[0]);
        }
        vector<int> visited(n,0);
        vector<vector<int>> output;
        dfs(adjlist,connections[0][0],-1,1,visited,output);
        return output;
    }
};