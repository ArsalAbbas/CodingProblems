class Solution {
public:
   int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
       int ans=0;
       int len =boxTypes.size();
       vector<pair<int,int>> boxes;
       for(int i=0;i<len;i++){
           boxes.push_back(make_pair(boxTypes[i][1],boxTypes[i][0]));
       }
       sort(boxes.begin(),boxes.end());
       int num=0;
       int i=len-1;
       while(truckSize && i>=0){
           if(boxes[i].second <=truckSize){
               num=boxes[i].second;
           }
           else{
               num=truckSize;
           }
           
           ans= ans+ boxes[i].first*num;
           truckSize= truckSize-num;
       i=i-1;
       }
       
       return ans;
   }
};