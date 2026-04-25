class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p=0,q=0;
        int n = nums.size();
        while(q<n)
        {
            if(nums[q]!=0)
            {
                swap(nums[p],nums[q]);
                p++;
            }
            q++;
        }
    }
};