//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  private:
    void dfsHelper(vector<int> adj[], vector<int> &vis, int curr){
        vis[curr]=1;
        for(int i: adj[curr])
            if(!vis[i]) dfsHelper(adj,vis,i);
    }
    // void printAdj(vector<int> adj[]){
    //             int i=0;
    //     for(auto it: adj){
    //         cout<<i++<< "->";
    //         for(auto i: it){
    //             cout<<i<<" ";
    //         }
    //         cout<<endl;
    //     }
    // }
    void printVis(vector<int> vis){
        int i=0;
        for(auto it: vis){
            cout<<i++<<"->";
            cout<<it<<endl;
        }
        cout<<"------------"<<endl;
    }
  public:
    int numProvinces(vector<vector<int>> adjM, int V) {
        vector<int> adj[V];
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(adjM[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(V,0);
        int count=0;
        // // printAdj(adj);
        // int i=0;
        // for(auto it: adj){
        //     cout<<i++<< "->";
        //     for(auto i: it){
        //         cout<<i<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<"----------------"<<endl;
        
        // printVis(vis);
        
        for(int i=0; i<V; i++)
            if(!vis[i]) {
                count++;
                dfsHelper(adj,vis,i);
                // printVis(vis);
            }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends