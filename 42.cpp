//接雨水
//单调栈
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> arr(n,0);
        stack<int> s;
        int res = 0;
        if(n==0) return res;
        s.push(0);
        for(int i=0;i<n;i++)
        {
            if(height[i]<height[s.top()])
            {
                s.push(i);
            }
            else
            {
                while(!s.empty()&&height[i]>height[s.top()])
                {
                    int mid = s.top();
                    s.pop();
                    if(s.empty()) break;
                    int left = s.top();
                    int h = min(height[left],height[i])-height[mid];
                    int w = i-left-1;
                    res+=h*w;
                }
                s.push(i);
            }
        }
        return res;
    }
};
//双指针
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0,right = n-1;
        int left_max = 0,right_max=0;
        int res = 0;
        while(left<right)
        {
            left_max=max(left_max,height[left]);
            right_max = max(right_max,height[right]);
            if(left_max<right_max)
            {
                res+=left_max-height[left];
                left++;
            }
            else
            {
                res+=right_max-height[right];
                right--;
            }
        }
        return res;
    }
};