class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=1;
        for(int i=1;i<nums.size();i++){
            // cout<<nums[i]<<endl;
            // cout<<"............"<<endl;
        if(nums[i]==nums[i-1])
            continue;
        else{
         nums[k]=nums[i];
        k++;
        }
            // cout<<nums[k]<<endl;
            
        }
        return k;
    }
};
/*
 ,  .
1,1,2
if 1==1

if 1==2
nums[]
*/