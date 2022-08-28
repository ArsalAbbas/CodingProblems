class Solution {
public:
	vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
		unordered_map < int, priority_queue<int, vector<int>, greater<int>>> mp;
		int n = mat.size(), m = mat[0].size();

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				int diff = i - j;
				mp[diff].push(mat[i][j]);
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				int diff = i - j;
				mat[i][j] = mp[diff].top();
				mp[diff].pop();
			}
		}
		return mat;
	}
};
