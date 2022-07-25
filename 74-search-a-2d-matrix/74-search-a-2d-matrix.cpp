class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int start=0;
        int end=(matrix.size()*matrix[0].size())-1;
        int mid;
        int i,j;
        if(!matrix.size()) return false;
        while(start<=end){
            mid=start+(end-start)/2;
            i=mid/matrix[0].size();
            j=mid%matrix[0].size();
            
            if(matrix[i][j]>target)
                end=mid-1;
            else if(matrix[i][j]<target)
                start=mid+1;
            else
                return true;
        }
        return false;
        
    }
};