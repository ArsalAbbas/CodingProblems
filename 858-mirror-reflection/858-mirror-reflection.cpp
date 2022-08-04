class Solution {
public:
    int mirrorReflection(int p, int q) {
        int LCM=lcm(p,q);
        if((LCM/q)%2==0)
            return 2;
        
        return (LCM/p)%2;
    }
};