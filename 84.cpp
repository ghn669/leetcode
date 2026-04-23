class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n = heights.size();
        stack<int> s;
        int res = 0;
        if(n==0) return res;
        for(int i=0;i<n;i++)
        {
            while(!s.empty()&&heights[i]<heights[s.top()])
            {
                int mid = s.top();
                s.pop();
                int left = s.empty() ? -1 : s.top();
                int w = i - left - 1;
                res = max(res, heights[mid] * w);
            }
            s.push(i);
        }
        return res;
    }
};