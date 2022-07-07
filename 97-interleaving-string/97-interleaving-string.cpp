class Solution {
public:
    bool solve(int i,int j,int k,string &s1,string &s2,string &s3,vector<vector<int>>&dp){
        if(i==s1.size() && j==s2.size()){
            if(k==s3.size())return true;
            else return false;
        }
        if(dp[k][i]!=-1)return dp[k][i];
        bool left=false,right=false;
        if(i<s1.size() &&  s3[k]==s1[i]){
            left = solve(i+1,j,k+1,s1,s2,s3,dp);
        }
        if(j < s2.size() && s3[k]==s2[j]){
            right=solve(i,j+1,k+1,s1,s2,s3,dp);
        }
        return dp[k][i]= left || right;
    }
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>>dp(s3.size()+1,vector<int>(s1.size()+1,-1));
        return solve(0,0,0,s1,s2,s3,dp);
    }
};