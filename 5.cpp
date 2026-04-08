//最长回文串
class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));
        int i,j;
        int start=0;
        int maxlen=1;
        for(int i=s.size()-1;i>=0;i--)
        {
            for(int j=i;j<s.size();j++)
            {
                if(s[i]==s[j])
                {
                    if(j-i<=1)
                    {
                        dp[i][j]=true;
                    }
                    else if(dp[i+1][j-1]==true)
                    {
                        dp[i][j]=true;
                    }
                    if(dp[i][j]==true&&maxlen<j-i+1)
                    {
                        maxlen=j-i+1;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start,maxlen);
    }
};