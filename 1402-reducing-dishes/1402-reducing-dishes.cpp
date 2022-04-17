class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        
        sort(satisfaction.begin(),satisfaction.end(),greater<int>());
        
          int i=0,sum=0,ans=0,n=satisfaction.size();
        
        while (i<n && satisfaction[i]+sum>=0) {

            ans+=satisfaction[i]+sum;
            sum+=satisfaction[i];
            i++;
            
        }
        
        return ans;
    }
};