class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        int x=0,y=n;
        int m=2*n;
        while(x<n){
            ans.push_back(nums[x]);
            ans.push_back(nums[y]);
            x++;y++;
        }
        return ans;
    }
};