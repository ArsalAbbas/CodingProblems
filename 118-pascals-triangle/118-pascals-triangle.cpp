class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> vect(numRows);
        
        for(int i=0; i< numRows; i++){
            vect[i].resize(i+1);
            vect[i][0]=1;
            vect[i][i]=1;
            for(int j=1; j<i; j++){
                
                vect[i][j]=vect[i-1][j-1]+vect[i-1][j];
                
            }
            
            
        }
        return vect;
        
    }
};