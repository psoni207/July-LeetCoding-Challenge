class Solution {
    private:
    int total;
public:
    int maxProfit(vector<int>& prices) {
        total = prices.size();
        
        if(total <= 1) {
            return 0;
        }
        
        vector<int> buyProfit(total);
        vector<int> sellProfit(total);
        
        buyProfit[0] = -prices[0];
        sellProfit[0] = 0;
        
        buyProfit[1] = max(buyProfit[0],-prices[1]);
        
        sellProfit[1] = max(sellProfit[0],buyProfit[0]+prices[1]);
        
        for(int i = 2; i < total; i++) {
            buyProfit[i] = max(buyProfit[i-1],sellProfit[i-2]-prices[i]);
            sellProfit[i] = max(sellProfit[i-1],buyProfit[i-1]+prices[i]);
        }
        
        return sellProfit[total-1];
        
    }
};