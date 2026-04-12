//买卖股票的最佳时机III
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int k = 2; // 交易k次
        vector<int> buy(k + 1, INT_MIN), sell(k + 1, 0);
        for (int price : prices) {
            for (int i = 1; i <= k; ++i) {
                buy[i] = max(buy[i], sell[i - 1] - price);
                sell[i] = max(sell[i], buy[i] + price);
            }
        }
        return sell[k];
    }
};