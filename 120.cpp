//三角形最小路径和
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.size(),0);
        dp[0]=triangle[0][0];
        for(int i=1;i<triangle.size();i++)
        {
            for(int j=i;j>=0;j--)
            {   
                if(j==0)
                {
                    dp[j]+=triangle[i][j];
                    continue;
                }
                if(j==i)
                {
                    dp[j]=dp[j-1]+triangle[i][j];
                    continue;
                }
                dp[j]=min(dp[j],dp[j-1])+triangle[i][j];
            }
        }
        int min_val = dp[0];
        for(int val : dp)
        {
            min_val = min(min_val,val);
        }
        return min_val;
    }
};