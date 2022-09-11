class Solution {
public:
    int dp[1001][101][2]; // dp state for curridx,k,buy/sell
    int solve(int k, vector<int>& prices,int i,int stat)
    {
        int n=prices.size();
      if(!k or i==n)return 0;
        
        if(dp[i][k][stat]!=-1)return dp[i][k][stat]; 
        int p=0;
        int p1=0;
       if(stat) // already buyed
       {
            p=prices[i]+solve(k-1,prices,i+1,0);
           p1=solve(k,prices,i+1,stat);
       }
        else // if not buyed
        {
            p=-prices[i]+solve(k,prices,i+1,1);
            p1=solve(k,prices,i+1,stat);
        }
        return dp[i][k][stat]=max(p,p1);
        
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
     return solve(k,prices,0,0);
    }
};