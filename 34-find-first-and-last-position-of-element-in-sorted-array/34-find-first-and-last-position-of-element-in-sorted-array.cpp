class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // vector<int> pair(binSearch(nums,target,true),binSearch(nums,target,false));
        vector<int> pair(2,-1);
        pair[0]=binSearch(nums,target,true);
        pair[1]=binSearch(nums,target,false);
        return pair;
    }
    
    int binSearch(vector<int> nums,int target, bool firstPos){
    
        int start=0, end=nums.size()-1,mid;
        int k=-1,i;
        while(start<=end){
            mid = start +(end - start) /2 ;
            if(nums[mid]==target){
                k=mid;
            if(firstPos)
                end=mid-1;
            else
                start=mid+1;
        }
            else if(target>nums[mid]){
                start=mid+1;
                mid=(start+end)/2;
        }
            else{
                end=mid-1;
                mid=(start+end)/2;
        }
            }
      cout<<k<<endl;
            return k;
    }
};