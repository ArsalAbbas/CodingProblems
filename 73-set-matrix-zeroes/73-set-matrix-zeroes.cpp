// class Solution 
// {
//     public:
// //     void setZeroes(vector<vector<int>>& matrix) 
// // {
// //         vector<pair<int,int>> xy;
// //         pair<int,int> p;
// //         for(int i=0; i< matrix.size(); i++)
// // {
            
// //             for( int j=0; j< matrix[i].size() ; j++)
// // {
                
// //                     // cout<<matrix[i][j]<<" ";
// //                 if(matrix[i][j]==0)
// // {
// //                     p.first=i;
// //                     p.second=j;
// //                     xy.push_back(p); 
// // }       
// // }
// // }
// //          for(int i=0; i< xy.size(); i++)
// // {
             
// //              for(int j=0; j<matrix[0].size();j++)
// //                  matrix[xy[i].first][j]=0;
// //              for(int j=0; j<matrix.size();j++)
// //                  matrix[j][xy[i].second]=0;
// // }             
// // }
//     void setZeroes(vector<vector<int>>& matrix) {
//     set<int> row;
//     set<int> col;
	
// 	//If element is zero, insert its position in row & col set
//     for(int i=0; i<matrix.size(); i++)
//         for(int j=0; j<matrix[0].size(); j++)
//             if(matrix[i][j]==0)
//                 row.insert(i), col.insert(j);
	
// 	//Set row elements to zero if zero is present in row
//     for(auto itr=row.begin(); itr!=row.end(); itr++)
//         for(int j=0; j<matrix[0].size(); j++)
//             matrix[*itr][j] = 0;
	
// 	//Set column elements to zero if zero is present in column
//     for(auto itr=col.begin(); itr!=col.end(); itr++)
//         for(int j=0; j<matrix.size(); j++)
//             matrix[j][*itr] = 0;
// }
// };
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        
        int H = matrix.size();
        int W = matrix[0].size();
        
        // find the last 0 row
        int last_0_row = -1;
        for (int y = H - 1; y >= 0 && last_0_row == -1; y--)
            for (int x = 0; x < W; x++)
                if (matrix[y][x] == 0)
                {
                    last_0_row = y;
                    break;
                }
        if (last_0_row == -1)
            return;
        
        // go row by row
        for (int y = 0; y < last_0_row; y++)
        {
            bool this_is_a_0_row = false;
            
            for (int x = 0; x < W; x++)
            {
                if (matrix[y][x] == 0)
                {
                    this_is_a_0_row = true;
                    matrix[last_0_row][x] = 0;
                }
            }
            
            if (this_is_a_0_row)
            for (int x = 0; x < W; x++)
            {
                matrix[y][x] = 0;
            }
        }
        
        // set collums to 0
        for (int y = 0; y < H; y++)
        for (int x = 0; x < W; x++)
        {
            if (matrix[last_0_row][x] == 0)
                matrix[y][x] = 0;
        }
        
        // set the last 0 row 
        for (int x = 0; x < W; x++)
        {
            matrix[last_0_row][x] = 0;
        }
    }
};