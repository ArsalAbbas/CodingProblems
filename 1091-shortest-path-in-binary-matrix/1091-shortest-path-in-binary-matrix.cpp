class Solution {
public:
    vector<pair<int, int>> movements = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

bool isValidMove(int &x, int &y, int &n, vector<vector<int>> &grid){
    if(x < 0 || y < 0 || x >= n || y >= n || grid[x][y] == 1) return false;
    return true;
}

int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
    
    int n = grid.size();
    
    if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
    if(n == 1) return 1;
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    grid[0][0] = 1;
    
    int ans = 0;
    
    while(!q.empty()){
        ans++;
        int size = q.size();
        
        for(int i=0;i<size;i++){
            auto p = q.front();
            q.pop();
            
            for(auto &x: movements){
                int movX = p.first + x.first;
                int movY = p.second + x.second;
                
                if(isValidMove(movX, movY, n, grid)){
                    grid[movX][movY] = 1;
                    q.push({movX, movY});
                }
            }
        }
        if(grid[n-1][n-1] == 1) break;
    }
    
    if(grid[n-1][n-1] != 1) return -1;
    return (ans+1);
    
}
};