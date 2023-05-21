//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>> mat)
	{
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> distance(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++){
                if(mat[i][j]==1)
                {
                q.push({{i,j},0});
                vis[i][j]=1;
                }
                else vis[i][j]=0;
            }
         
        int delRow[]={-1,1,0,0};
        int delCol[]={0,0,-1,1};

        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int dist=q.front().second;
            q.pop();
            distance[row][col]=dist;

            for(int i=0; i<4; i++){
                int nrow=row+delRow[i];
                int ncol=col+delCol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0){
                        vis[nrow][ncol]=1;
                        q.push({{nrow,ncol},dist+1});
                    }
            }
        }
        return distance;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends