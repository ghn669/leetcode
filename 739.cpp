class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> s;
        vector<int> res(n,0);
        if(n==0) return res;
        s.push(0);
        for(int i=0;i<n;i++)
        {
            if(temperatures[i]<=temperatures[s.top()])
            {
                s.push(i);
            }
            else
            {
                while(!s.empty()&&temperatures[i]>temperatures[s.top()])
                {
                    res[s.top()]=i-s.top();
                    s.pop();
                }
                s.push(i);
            }
        }
        return res;
    }
};