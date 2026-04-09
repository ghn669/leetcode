//目标和
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        if (sum < abs(target) || (sum + target) % 2 != 0) {
            return 0;
        }
        int len = (sum+target)/2;
        vector<int> dp(len+1,0);
        dp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=len;j>=nums[i];j--)
            {
                dp[j]+=dp[j-nums[i]];
            }
        }
        return dp[len];
    }
};