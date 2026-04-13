//斐波那契数
class Solution {
public:
    int fib(int n) {
        int lastlast=0;
        int last =1;
        if(n==0) return lastlast;
        if(n==1) return last;
        for(int i=2;i<=n;i++)
        {
            int cur = last+lastlast;
            lastlast = last;
            last = cur;
        }
        return last;
    }
};