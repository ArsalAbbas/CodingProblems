class Solution {
public:
    int pivotIndex(vector<int>& nums) {
    int sum=0,left_sum=0,n=nums.size();
    for(int i=0 ; i<n ; i++){
        sum=sum+nums[i];
    }
    for(int i=0; i<n ; i++){
        sum=sum-nums[i];
        if(left_sum==sum)
            return i;
        else
            left_sum=left_sum + nums[i];
    }
    return -1;
    
}
};
