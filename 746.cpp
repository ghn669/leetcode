//最小花费爬楼梯
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1);
        dp[0]=0;
        dp[1]=0;
        for(int i=2;i<=cost.size();i++)
        {
            dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
        }
        return dp[cost.size()];
    }
};
//优化空间
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int lastlast=0;
        int last=0;
        if(cost.size()==1) return cost[0];
        if(cost.size()==2) return min(cost[0],cost[1]);
        for(int i=2;i<=cost.size();i++)
        {
            int cur = min(last+cost[i-1],lastlast+cost[i-2]);
            lastlast=last;
            last=cur;
        }
        return last;
    }
};