class Solution {
public:
    bool isPowerOfThree(int n) {
        
        double nn=log10(n)/log10(3);
        if(floor(nn)==nn && n!=0)
            return true;
        return false;
        
    }
};
// class Solution {
// public:
//     bool isPowerOfThree(int n) {
//         if(n==0){
//             return false;
//         }
        
//         while(n%3==0){
//             n=n/3;
//         }
//         if(n==1){
//             return true;
//         }else{
//             return false;
//         }
//     }
// };