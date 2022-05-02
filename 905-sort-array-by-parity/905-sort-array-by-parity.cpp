class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        int temp;
        while(i<j){
            
            if(nums[i]%2!=0 && nums[j]%2!=1)
            {
            temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
            i++;
            j--;
            }
            if(nums[i]%2==0)
                i++;
            if(nums[j]%2==1)
                j--;
        }
        return nums;
    }
};