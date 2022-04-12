class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int c = count(nums.begin(),nums.end(),target);
        if(c == 0){
            return lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        }else{
            return find(nums.begin(),nums.end(),target) - nums.begin();
        }
        return 0;
    }
};