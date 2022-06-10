class Solution {
public:

int lengthOfLongestSubstring(string s) {
    int ans=0;
    int st=0,end=0;
     int prev_occ[150]={0};//return prev_occ+1
    while(st<s.size()&&end<s.size()){
        while(end<s.size()&&prev_occ[s[end]]==0){
            prev_occ[s[end]]=end+1;
            end++;
        }    
        ans=max(ans,end-st);
        while(st<prev_occ[s[end]]-1){
            prev_occ[s[st]]=0;
            st++;
        }
        prev_occ[s[end]]=end+1;
        st++;
        end++;
    }
    return ans;
}
};