class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        int longest = 0;
        
        for(auto n:nums){
            s.insert(n);
        }
        
        for(auto num : s){
            if(s.count(num-1)) continue;
            
            else{
                int number = num;
                int count = 1;
                
                while(s.count(number+count)){
                    count++;
                }
                
                longest = max(longest,count);
            }
        }
        return longest;
    }
};