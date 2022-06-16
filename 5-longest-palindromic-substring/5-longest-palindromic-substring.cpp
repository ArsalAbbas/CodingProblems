class Solution {
public:
string longestPalindrome(string str) {

    int n = str.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    int count = 0;
    int start = -1;
    
    for(int diff = 0;diff<n ;diff++)
    {
        int j = diff;
        for(int i = 0;j<n;i++,j++)
        {
            if(diff == 0){
                dp[i][j] = 1;
            }
            else if(diff == 1){
                dp[i][j] = (str[i] == str[j]) ? 1:0;
            }
            
            else if(str[i] == str[j]){
                dp[i][j] = dp[i+1][j-1];
               
            }
            
            if(dp[i][j]){
                if(count < j-i+1){
                    count = j-i+1;
                    start = i;
                }   
            }
        }
    }    
    return str.substr(start,count);
}
};