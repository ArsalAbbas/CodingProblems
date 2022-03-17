class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        int s=nums[0];
        for(int i=0;i<n-1;i++){
            s=s+nums[i+1];
            nums[i+1]=s;
        }
        return nums;
    }
};