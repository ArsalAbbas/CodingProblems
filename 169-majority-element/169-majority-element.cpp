class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Sol 1- nlogn
        // sort(nums.begin(),nums.end());
        // return nums[nums.size()/2];    
            // cout<<*max_element(nums.begin(),nums.end())<<endl;
        
        
        //Sol 2 - memory limit
        //     vector<int> mapping(INT_MAX,0);
        //     for(int i=0; i< nums.size(); i++)
        //     {
        //         mapping[nums[i]]++;
        //     }
        // int maxVote=0;
        // int maxElem;
        // for(int i=0; i< nums.size(); i++)
        //     {
        //     if(mapping[nums[i]]>maxVote)
        //         maxElem=nums[i];
        //     }
        // return maxElem;
        
        //Sol 3 - Moore's voting algorithm
        
        int candidate=nums[0],freq=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==candidate)
                freq++;
            if(nums[i]!= candidate)
                freq--;
            if(freq==0)
            {
                candidate=nums[i];
                freq=1;
            }
        }
        return candidate;
    }
};