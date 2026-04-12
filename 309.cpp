//买卖股票的最佳时机含冷冻期
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(3,0));
        //dp[i][0]持有股票
        //dp[i][1]不持有股票且在冷冻期
        //dp[i][2]不持有股票且不在冷冻期
        dp[0][0]=-prices[0];
        dp[0][1]=0;
        dp[0][2]=0;
        for(int i=1;i<prices.size();i++)
        {
            dp[i][0]=max(dp[i-1][0],dp[i-1][2]-prices[i]);
            dp[i][1]=dp[i-1][0]+prices[i];
            dp[i][2]=max(dp[i-1][1],dp[i-1][2]);
        }
        return max(dp[prices.size()-1][1],dp[prices.size()-1][2]);
    }
};