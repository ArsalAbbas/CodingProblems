class Solution {
public:
    int candy(vector<int>& nums) {
        //Try 1
//         int c=0;
//         if(ratings[0]>ratings[1])
//             c++;
//         if(ratings[ratings.size()-1]>=ratings[ratings.size()-2])
//             c++;
//         cout<<c<<endl;
//         for(int i=1;i<ratings.size()-1;i++){
//             if(ratings[i]>ratings[i-1] && ratings[i]>ratings[i+1])
//                 c++;
//         cout<<c<<endl;
            
//         }
//         c+=ratings.size();
//                 cout<<c<<endl<<endl;
// //[1,2,3,1,2]
// // 1 2 3 1 2 
// //2
//         return c;
        
 //Try 2       
//         vector<int> allocation(ratings.size(),1);
//         for(int i=0;i<ratings.size();i++){
//             if (i==0)
//             {
//                 if(ratings[i]>ratings[i+1])
//                     allocation[i]=allocation[i+1]+1;
//                 continue;
//             }
//             if (i==ratings.size()-1)
//             {
//                 if(ratings[i]>ratings[i-1])
//                     allocation[i]=allocation[i-1]+1;
//                 continue;

//             }
//             if(ratings[i]==ratings[i-1] && ratings[i]==ratings[i+1])
//                 continue;
            
//             if(ratings[i]>ratings[i-1] || ratings[i]>ratings[i+1])
//                 // allocation[i]=max(allocation[i+1],allocation[i-1])+1;
//                 allocation[i]=ratings[i]>ratings[i-1]?(allocation[i-1]+1):(allocation[i+1]+1);

//         // cout<<c<<endl;
            
//         }
//         for(auto it: allocation)
//             cout<<it<<endl;
        
//         return accumulate(allocation.begin(),allocation.end(),0
        
        //Try 3- Split try 2
        
         int l = nums.size();
        if(l<=1)
            return l;
        
        vector<int> allocation(l,1);
        for(int i=1;i<l;i++){
            if(nums[i]>nums[i-1])
                allocation[i]=allocation[i-1]+1;
        }
        for(int i=l-2;i>=0;i--){
            if(nums[i]>nums[i+1])
                allocation[i]=max(allocation[i],allocation[i+1]+1);
        }
        return accumulate(allocation.begin(),allocation.end(),0);
        
    }
};