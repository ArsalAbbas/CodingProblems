class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n= nums.size();
        
        vector<int> zeros;
        vector<int> ones;
        vector<int> twos;
        
        for(int i=0; i< nums.size() ; i++){
            if(nums[i]==0)
                zeros.push_back(0);
            if(nums[i]==1)
                ones.push_back(1);
            if(nums[i]==2)
                twos.push_back(2);
        }
        int x=0;
        for(int i=0; i< zeros.size(); i++){
            
            nums[x]=0;
            x++;
            
        }
        for(int i=0; i< ones.size(); i++){
            
            nums[x]=1;
            x++;
            
        }
        for(int i=0; i< twos.size(); i++){
            
            nums[x]=2;
            x++;
        }
        
    }
};