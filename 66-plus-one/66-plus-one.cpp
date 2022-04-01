class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        bool carry=1;
        int i=1;
        while(carry and i<=n)
        {
            digits[n-i]++;
            if(digits[n-i]==10)
            {
                digits[n-i]=0;
                i++;
            }
            else
                carry=0;
        }
        if(carry)
        {
            digits[0]=1;
            digits.push_back(0);
        }
        return digits;
    }
};