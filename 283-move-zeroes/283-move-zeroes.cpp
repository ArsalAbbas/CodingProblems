class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int j=nums.size()-1;
        int c=0;
        int x=0;
        for(int i=0; i< nums.size(); i++){
            
            if(nums[i]!=0){
                nums[x]=nums[i];
                x++;
            }
            else c++;
            
        }
        while(c!=0){
            
            nums[j]=0;
            j--;
            c--;
        }
    }
};