class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        int res = 1;
        vector<int> dp(n,1);
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]<nums[i])
            {
                dp[i]=dp[i-1]+1;
            }
            res = max(res,dp[i]);
        }
        return res;
    }
};