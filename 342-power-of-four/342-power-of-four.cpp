class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==0) return false;
        double d=log(n)/log(4);
        if(floor(d)==d)
            return true;
        return false;
    }
};