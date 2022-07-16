class Solution {
    bool possible(vector<vector<int>>& grid, int i, int j){
        int row = grid.size();
        int col = grid[0].size();
        
        return i>=0 && i<row && j>=0 && j<col && grid[i][j]==1;
        
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j, int &cur, vector<vector<int>>& vis){
        vis[i][j] = 1;
        cur++;
        int rnx[4] = {-1, 0, 0, 1};
        int cnx[4] = {0, -1, 1, 0};
        
        for(int k=0; k<4; k++){
            int r = i+rnx[k];
            int c = j+cnx[k];
            if(possible(grid, r, c) && !vis[r][c]){
                dfs(grid, r, c, cur, vis);
            }
        }
        
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int mx=0;
        int cur=0;
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<int>> vis(row, vector<int> (col, 0));
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    cur=0;
                    dfs(grid, i, j, cur, vis);
                    mx = max(mx, cur);
                }
            }
        }
        return mx;
    }
};