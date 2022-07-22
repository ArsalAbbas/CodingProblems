// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int price=INT_MAX;
//         int profit=0;
//     for(int i=0; i< prices.size() ; i++){
        
//         price=min(price,prices[i]);
//         profit=max(profit, prices[i]-price);
        
//     }
//         return price;
//     }
// };
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, minBuy = INT_MAX;
        for(int &x:prices){
            minBuy = min(minBuy,x);
            ans = max(ans,x-minBuy);
        }
        return ans;
    }
};