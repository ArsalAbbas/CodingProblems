class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int price=*max_element(prices.begin(), prices.end()),profit=0;
    for(auto it:prices){
        price=min(price,it);
        profit=max(profit,it-price);
    }
        return profit;
    }
};