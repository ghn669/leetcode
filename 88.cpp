class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int res[m+n];
        int p=0,q=0;
        int cnt = 0;
        while(p!=m||q!=n)
        {
            if(p==m)
            {
                res[cnt++] = nums2[q++];
                continue;
            }
            if(q==n)
            {
                res[cnt++]=nums1[p++];
                continue;
            }
            if(nums1[p]<=nums2[q])
            {
                res[cnt++] = nums1[p++];
            }
            else
            {
                res[cnt++] = nums2[q++];
            }
        }
        for(int i=0;i<m+n;i++)
        {
            nums1[i]=res[i];
        }
    }
};