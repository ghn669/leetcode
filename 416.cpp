//分割等和子集
//01背包
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int x : nums) sum += x;
        if (sum % 2 != 0) return false;
        int target = sum / 2;

        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        for (int i = 1; i <= n; ++i) {       // 这里要 <=n
            for (int j = 1; j <= target; ++j) {
                if (j < nums[i-1]) {          // 必须判断防止越界
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j - nums[i-1]] + nums[i-1]);
                }
            }
        }

        return dp[n][target] == target;
    }
};