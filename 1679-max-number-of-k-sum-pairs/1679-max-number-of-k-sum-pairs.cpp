// class Solution {
// public:
//     int maxOperations(vector<int>& nums, int k) {
//         sort(nums.begin(),nums.end());
//         int i=0;
//         int j=nums.size()-1;
//         int c=0;
//         while(i<j){
            
//             if(nums[i]+nums[j]==k)
//             {
//                 c++;
//                 i++;
//                 j--;
//             }
//             else if(nums[i]+nums[j]>k){
//                 j--;
//             }
//             else
//                 i++;
            
//         }
//         return c;
//     }
// };
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int, int> freqMap;
        int ans = 0;
        
        for(int i = 0 ; i < n ; i++){
            
            if(freqMap[k - nums[i]] > 0){
                ans++;
                freqMap[k-nums[i]]--;
            }else{
                freqMap[nums[i]]++;
            }
            
        }
        
        return ans;
        
        
    }
};