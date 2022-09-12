class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        vector<int> visited(tokens.size(),0);
        int j=tokens.size()-1,score=0,ans=0;
        for(int i=0;i<tokens.size();i++)
        {
            if(!visited[i]){
                if(tokens[i]<=power){
                    score++;
                    power-=tokens[i];
                    visited[i]=1;
                }
                else if(score>0 and !visited[j]){
                    score--;
                    power+=tokens[j];
                    visited[j]=1;
                    j--;
                    i--;
                }
            ans=max(ans,score);
            } 
        }
        return ans;
    }
};