class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis;
        for(int i=0;i<n;i++){
            int pos = upper_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
            if(pos >= lis.size()){
                lis.push_back(nums[i]);
            }else{
                lis[pos] = nums[i];
            }
        }
        return nums.size() - 1 <= lis.size();
    }
};