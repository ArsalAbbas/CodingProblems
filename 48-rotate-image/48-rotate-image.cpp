class Solution {
public:
    
    vector<vector<int>> transpose(vector<vector<int>>& matrix){
        int temp;
        for(int i=0; i< matrix.size(); i++){
            
            for(int j=0; j< i; j++){
                
                temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
                
            }
            
        }
        
        return matrix;
        
    }
    
    vector<int> reverseRow(vector<int> row){
        
        int i=0;
        int j=row.size()-1;
        int temp;
        while(i<j){
            
            temp=row[i];
            row[i]=row[j];
            row[j]=temp;
            i++;
            j--;
        }
        return row;
        
    }
    
    void rotate(vector<vector<int>>& matrix) {
        
        transpose(matrix);
        
        for(int i=0; i< matrix.size() ; i++){
            
            matrix[i]=reverseRow(matrix[i]);
            
        }
    }
};