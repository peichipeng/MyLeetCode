class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int lowestPrice = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] - lowestPrice > maxProfit) {
                maxProfit = prices[i] - lowestPrice;
            }
            lowestPrice = min(lowestPrice, prices[i]);
        }
        return maxProfit;
    }
};