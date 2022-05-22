class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        int ans = 0;
        for(int gap=1;gap<=n;gap++){
            for(int i=0;i<n-gap+1;i++){
				// Case 1:
                if(gap==1) dp[i][i] = 1;
				//Case 2:
                else if(gap==2){
                    if(s[i]==s[i+1]) dp[i][i+1] = 1;
                    else dp[i][i+1] = 0;
                }
				//Case 3:
                else if(s[i]==s[i+gap-1] && dp[i+1][i+gap-2]>0) dp[i][i+gap-1] = 1;
                else dp[i][i+gap-1] = 0;
				
				//add the count to the result
                ans += dp[i][i+gap-1];
            }
        }
        return ans;
    }
};