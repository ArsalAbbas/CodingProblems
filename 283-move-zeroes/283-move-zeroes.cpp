class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int j=nums.size()-1;
        int c=0;
        
        for(int i=0; i< nums.size() ; i++)
            if(nums[i]==0)
                c++;
        
        int x=0;
        for(int i=0; i< nums.size(); i++){
            
            if(nums[i]!=0){
                nums[x]=nums[i];
                x++;
            }
            
        }
        while(c!=0){
            
            nums[j]=0;
            j--;
            c--;
        }
    }
};