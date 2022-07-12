class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp;
        vector<int> prev;
        for(int i=1;i<=numRows;i++)
        {  vector<int> curr;
           curr.push_back(1);
            for(int j=1;j<i-1;j++)
            {
                curr.push_back(prev[j-1]+prev[j]);
            }
            if(i>1)curr.push_back(1);
            dp.push_back(curr);
            prev=curr;
        }
        return dp;
    }
}; 