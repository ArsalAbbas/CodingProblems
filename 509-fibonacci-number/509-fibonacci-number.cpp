class Solution {
public:
    int fib(int n) {
        // if(n==0)
        //     return 0;
        // if(n==1)
        //     return 1;
        // // return fib(n-1)+fib(n-2);
        return (n==0) ? 0 : (n==1) ? 1 : fib(n-1) + fib(n-2);
        // int x=0;
        // int y=1;
        // int temp;
        // for(int i=0; i<n ; i++){
        //     temp=y;
        //     y=x;
        //     x=x+temp;
        // }
        // return x;
            
    }
};