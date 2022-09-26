class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        int n=nums.size();
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                long rhs=long(target)-nums[i]-nums[j];
                int low=j+1, high=n-1;
                while(low<high){
                    long lhs=nums[low]+nums[high];
                    if(lhs>rhs)
                        high--;
                    else if(rhs>lhs)
                        low++;
                    else
                        st.insert({nums[low++],nums[high--],nums[i],nums[j]});
                }
            }
        }
        
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};