class Solution 
{
    public:
    void setZeroes(vector<vector<int>>& matrix) 
{
        vector<pair<int,int>> xy;
        pair<int,int> p;
        for(int i=0; i< matrix.size(); i++)
{
            
            for( int j=0; j< matrix[i].size() ; j++)
{
                
                    // cout<<matrix[i][j]<<" ";
                if(matrix[i][j]==0)
{
                    p.first=i;
                    p.second=j;
                    xy.push_back(p); 
}       
}
}
         for(int i=0; i< xy.size(); i++)
{
             
             for(int j=0; j<matrix[0].size();j++)
                 matrix[xy[i].first][j]=0;
             for(int j=0; j<matrix.size();j++)
                 matrix[j][xy[i].second]=0;
}             
}
};