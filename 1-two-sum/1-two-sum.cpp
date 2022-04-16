#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
//    vector<int> res;
//         for(auto i=nums.begin(); i<nums.end()-1;i++){
//             for(auto j=i+1;j<nums.end(); j++){
                
//                 int sum=nums.at(i-nums.begin())+nums.at(j-nums.begin());//line 11
//                 if(sum==target){
//                     res.push_back(i-nums.begin());
//                     res.push_back(j-nums.begin());
//                     return res;
//                     break;
//                 }
//             }
//         }
//         res.clear();
//         return res;
        vector<int> ans;
        unordered_map<int,int> mapping;
        
        for(int i=0;i<nums.size();i++){
            
            if(mapping.find(target-nums[i])!=mapping.end()){
                
                ans.push_back(mapping[target-nums[i]]);
                ans.push_back(i);
                
            }
            
            mapping[nums[i]]=i;
            
        }return ans;
        
    }
};