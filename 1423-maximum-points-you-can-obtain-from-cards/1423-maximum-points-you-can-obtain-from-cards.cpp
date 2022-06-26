class Solution {
public:
 int maxScore(vector<int>& nums, int k) {
        int n= nums.size();
        int sum=0;
        for(int i=0;i<k;i++) sum+=nums[i];
        int res=sum;
        int j=n-1;
        for(int i=k-1;i>=0;i--){
            sum-=nums[i];
            sum+=nums[j--];
            res= max(res,sum);
        }
        return res;
    }
};