class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max=INT_MIN;
        for (auto it:accounts)
            if (accumulate(it.begin(),it.end(),0)>max) max=accumulate(it.begin(),it.end(),0);
        return max ;
    }
};