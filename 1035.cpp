class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> dp(m+1,0);
        for(int i=1;i<=n;i++)
        {
            int pre = 0;
            for(int j=1;j<=m;j++)
            {
                int temp = dp[j];
                dp[j]=nums1[i-1]==nums2[j-1]?pre+1:max(dp[j],dp[j-1]);
                pre = temp;
            }
        }
        return dp[m];
    }
};