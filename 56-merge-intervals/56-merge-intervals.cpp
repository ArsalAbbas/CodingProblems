class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        vector<int> tempInterval= intervals[0];
        
        
        for(auto it: intervals){
            
            if(it[0]<=tempInterval[1]){
                tempInterval[1]=max(it[1], tempInterval[1]) ;
            }
            else{
                
                merged.push_back(tempInterval);
                tempInterval=it;
            }
                
            
        }
               merged.push_back(tempInterval);
     
        return merged;
    }
};