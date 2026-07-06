class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;
        int maxprofit = 0;
        while(r < prices.size()){
            int profit = prices[r] - prices[l];

            if(profit > maxprofit){
                maxprofit = profit;
            }
            if(prices[r] < prices[l]){
                l = r;
            }
            r++;
        }
        return maxprofit;
    }
};
