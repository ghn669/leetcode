class Solution {
public:
    int numDecodings(string s) {
        int len = s.size();
        vector<int> dp(len,0);
        if(s[0]=='0') return 0;
        dp[0]=1;
        for(int i=1;i<len;i++)
        {
            int a = s[i]-'0';
            int b = (s[i-1]-'0')*10+a;
            if(a>=1&&a<=9) dp[i]=dp[i-1];
            if(b>=10&&b<=26)
            {
                if(i>1) dp[i]+=dp[i-2];
                else dp[i]+=1;
            }
        }
        return dp[len-1];
    }
};