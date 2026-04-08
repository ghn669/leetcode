//爬楼梯
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1);
        dp[1] = 1;
        if(n>=2) dp[2]=2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
//优化空间
class Solution {
public:
    int climbStairs(int n) {
        int lastlast=1;
        int last=2;
        if(n==1) return 1;
        if(n==2) return 2;
        for(int i=3;i<=n;i++)
        {
            int cur=lastlast+last;
            lastlast=last;
            last=cur;
        }
        return last;
    }
};