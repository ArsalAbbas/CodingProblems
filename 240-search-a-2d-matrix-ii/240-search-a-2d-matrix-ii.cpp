class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {

		int m = matrix.size();
		int n = matrix[0].size();
		
		// Start from top right corner
		int i = 0;
		int j = n - 1;

		while(i >= 0 && i < m &&  j >= 0 &&  j < n){

			if(matrix[i][j] == target){
				return true;
			}
			else if(matrix[i][j] > target){ // Go left
				j--;
			}
			else if(matrix[i][j] < target){ // Go down
				i++;
			}
		}

		return false;
	}
};