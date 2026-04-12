//无重复字符的最长字串
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max,left,right;
        left=0;
        right=0;
        max=0;
        while(s[right]!='\0')
        {
            if(left<=right)
            {
                for(int i=left;i<right;i++)
                {
                    if(s[i]==s[right])
                    {
                        left = i+1;
                        break;
                    }
                }
            }
            max = max<right-left+1?right-left+1:max;
            right++;
        }
        return max;
    }
};