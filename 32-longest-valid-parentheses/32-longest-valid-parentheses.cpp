class Solution {
public:
    int longestValidParentheses(string s) {
        int l=0,r=0,n=s.size(),t=0;
        for(int i=0;i<n;i++)
        {
            s[i]=='('?l++:r++;
            if(r>l)
                l=0,r=0;
            else if(l==r) // when l==r store max consecuive brackets
                t=max(t,l);
        }
        l=0,r=0;
        for(int i=n-1;i>=0;i--)
        {
            s[i]=='('?l++:r++;
            if(l>r)
                l=0,r=0;
            else if(l==r)
                t=max(t,l);
        }
        return 2*t;
    }
};