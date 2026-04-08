//回文子串
class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));
        int res = 0;
        int i,j;
        for(int i=s.size()-1;i>=0;i--)
        {
            for(int j=i;j<s.size();j++)
            {
                if(s[i]==s[j])
                {
                    if(j-i<=1)
                    {
                        dp[i][j]=true;
                        res++;
                        continue;
                    }
                    else if(dp[i+1][j-1]==true)
                    {
                        dp[i][j]=true;
                        res++;
                    }
                }
            }
        }
        return res;
    }
};