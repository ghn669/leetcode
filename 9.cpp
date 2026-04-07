//回文数
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long temp = x;
        long sum = 0;
        while(temp>0)
        {
            int num = temp%10;
            sum = sum*10 + num;
            temp = temp/10;
        }
        if(sum==x) return true;
        else return false;
    }
};