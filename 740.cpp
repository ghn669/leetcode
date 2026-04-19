//删除并增加点数（打家劫舍变体）
class Solution {
public:
    int rob(vector<int> sum)
    {
        int lastlast = sum[0];
        int last = max(sum[0],sum[1]);
        for(int i=2;i<sum.size();i++)
        {
            int cur = max(last,lastlast+sum[i]);
            lastlast = last;
            last = cur;
        }
        return last;
    }
    int deleteAndEarn(vector<int>& nums) {
        int max_size = 0;
        for(int num : nums)
        {
            max_size = max(max_size,num);
        }
        vector<int> sum(max_size+1);
        for(int num:nums)
        {
            sum[num]+=num;
        }
        return rob(sum);
    }
};