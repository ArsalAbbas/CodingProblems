class Solution {
public:
	vector<pair<int, int>> dirs = { {-1, 0},{0, -1},{0 , 1},{1 , 0}};

	vector<vector<int>> maxPath;
	int SIZE_ROW, SIZE_COL;

	int findMaxPath(int x, int y, vector<vector<int>>& matrix) {
		if(maxPath[x][y] > 0)
			return maxPath[x][y];

		int res = 1;
		
		for(auto& [dir_x, dir_y] : dirs) {
			int adj_x = x + dir_x, adj_y = y + dir_y;

			if(adj_x < 0 || adj_x >= SIZE_ROW || adj_y < 0 || adj_y >= SIZE_COL || matrix[adj_x][adj_y] <= matrix[x][y])
				continue;

			int currentMaxPath = findMaxPath(adj_x, adj_y, matrix) + 1;
			res = max(currentMaxPath, res);
		}
		return maxPath[x][y] = res;
	}

	int longestIncreasingPath(vector<vector<int>>& matrix) {
		SIZE_ROW = matrix.size(), SIZE_COL = matrix[0].size();
		maxPath.resize(SIZE_ROW, vector<int>(SIZE_COL, 0));

		int ans = 0;

		for(int row = 0; row < SIZE_ROW; row++) 
			for(int col = 0; col < SIZE_COL; col++) 
				ans = max(ans, findMaxPath(row, col, matrix));

		return ans;
	}
};