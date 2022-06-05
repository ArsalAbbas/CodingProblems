class Solution {
public:
    
    vector<vector<string>> ans;
    int total = 0;
    
    // boolean arrays to mark columns and left and right diagonals
    bool visited_cols[9], left_diag[20], right_diag[20];
    
    
    void solveNQueensUtil(int row, int n, vector<string> &placed){
        if(row == n){
            ans.push_back(placed);
            total++;
            return;
        }
        
        // Iterate on cols
        for(int i=0;i<n;i++){
            if(!visited_cols[i] && !right_diag[n+row-i] && !left_diag[row+i]){
                placed[row][i] = 'Q';
                visited_cols[i] = right_diag[n+row-i] = left_diag[row+i] = true;
                solveNQueensUtil(row+1, n, placed);
                visited_cols[i] = right_diag[n+row-i] = left_diag[row+i] = false;
                placed[row][i] = '.';
            }
        }
    }
    
    void solveNQueens(int n) {
        vector<string> placed(n, string(n,'.'));
        solveNQueensUtil(0, n, placed);
        return;
    }
    
    int totalNQueens(int n) {
        solveNQueens(n);
        return total;
    }
};