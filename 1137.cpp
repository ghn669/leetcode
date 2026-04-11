//泰伯纳妾数
class Solution {
public:
    int tribonacci(int n) {
        int lastlastlast=0; if(n==0) return 0;
        int lastlast=1;if(n==1) return 1;
        int last=1;if(n==2) return 1;
        for(int i=3;i<=n;i++)
        {
            int cur = lastlastlast+lastlast+last;
            lastlastlast=lastlast;
            lastlast=last;
            last=cur;
        }
        return last;
    }
};