class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int st = 0, ed = nums.size() - 1;
        while(st < ed) nums[st++] = nums[ed--] - nums[st];
        return accumulate(nums.begin(),nums.begin()+nums.size()/2,0);
    }
};