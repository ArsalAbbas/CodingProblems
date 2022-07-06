class Solution {
public:
    void printMatrix(vector<vector<int>>& matrix){
         for(int i=0; i< matrix.size() ; i++){
            for(int j=0; j< matrix[0].size() ; j++){
                
                cout<<matrix[i][j]<<" ";;;
                
            }
            cout<<endl;
    }
        cout<<endl;
        
    }
    void setZeroes(vector<vector<int>>& matrix) {
         printMatrix(matrix);
       
        int colSize=matrix[0].size();
        int rowSize=matrix.size();
        bool flag=true;
        
        for(int i=0; i< rowSize ; i++)
            for(int j=0; j< colSize ; j++){
                
                if(matrix[i][j]==0){
                    if(j==0)
                        flag=false;
                    else{
                        matrix[i][0]=0;
                        matrix[0][j]=0;
                    }
                    
                }
                
                
            }
                cout<<"Flag Matrix:"<<flag<<endl;

                printMatrix(matrix);

        cout<<"Output:"<<endl;
        for(int i=rowSize-1; i >= 0 ; i--)
            for(int j= colSize-1 ; j >= 0 ; j--){
                
                if(j==0)
                {
                    if(!flag)
                    matrix[i][j]=0;
                    continue;
                }
                if(matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j]=0;
                
            }
        
        
        printMatrix(matrix);
       
    }
};