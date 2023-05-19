//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> grid){
        vis[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        q.push({row,col});

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int delRow=-1; delRow<=1; delRow++)
                for(int delCol=-1; delCol<=1; delCol++){
                    int nRow= row+delRow;
                    int nCol= col+delCol;
            if( nRow>=0 && nRow<n && nCol<m && nCol>=0  && grid[nRow][nCol]=='1'&& !vis[nRow][nCol] ){
                            vis[nRow][nCol]=1;
                            q.push({nRow,nCol});
                        }
                }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
         int n=grid.size();
         int m=grid[0].size();

         vector<vector<int>> vis(n,vector<int>(m,0));
        int count=0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(!vis[i][j] && grid[i][j]=='1'){
                    bfs(i,j,vis,grid);
                    count++;
                }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends