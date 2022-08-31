class Solution {
public:
    vector<int> ver{+1, -1, 0, 0};
    vector<int> hor{0, 0, +1, -1};
    bool valid (int x, int y) {
        return x >= 0 and x < n and y >= 0 and y < m;
    }
    void bfs(queue<pair<int, int>> q, vector<vector<bool>>& visited, vector<vector<int>>& heights, vector<vector<int>>& jan) {
         while(!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                pair<int, int> node = q.front();
                q.pop();
                jan[node.first][node.second]++;
                for (int dir = 0; dir < 4; ++dir) {
                    int x = node.first + ver[dir], y = node.second + hor[dir];
                    if (valid(x, y) and !visited[x][y] and heights[x][y] >= heights[node.first][node.second]) {
                        visited[x][y] = true;
                        q.push({x, y});
                    } 
                }
            }
        }
    }
    int n, m;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size(), m = heights[0].size();
        vector<vector<bool>> visited1(n, vector<bool>(m, false));
        vector<vector<bool>> visited2(n, vector<bool>(m, false));
        vector<vector<int>> jan(n, vector<int>(m, 0));
        queue<pair<int, int>> q1, q2;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
               if (i == 0 or j == 0) {
                   q1.push({i, j});
                   visited1[i][j] = true;
               }
               if (i == n - 1 or j == m - 1) {
                   q2.push({i, j});
                   visited2[i][j] = true;
               } 
            }
        }
        bfs(q1, visited1, heights, jan);
        bfs(q2, visited2, heights, jan);
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (jan[i][j] == 2) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};