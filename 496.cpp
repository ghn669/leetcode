class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        stack<int> s;
        unordered_map<int,int> um;
        for(int i=0;i<n;i++)
        {
            um[nums1[i]]=i;
        }
        vector<int> res(n,-1);
        if(m==0) return res;
        s.push(0);
        for(int i =0;i<m;i++)
        {
            if(nums2[i]<=nums2[s.top()])
            {
                s.push(i);
            }
            else
            {
                while(!s.empty()&&nums2[i]>nums2[s.top()])
                {
                    if(um.count(nums2[s.top()])>0)
                    {
                        res[um[nums2[s.top()]]]=nums2[i];
                    }
                    s.pop();
                }
                s.push(i);
            }
        }
        return res;
    }
};