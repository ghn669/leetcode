class Solution {
public:
    vector<vector<int>> ans;
    void func(vector<int>& nums,int start)
    {
        if(start==nums.size()){
            ans.push_back(nums);
        }
        for(int i=start;i<nums.size();i++){
            swap(nums[start],nums[i]);
            func(nums,start+1);
            swap(nums[start],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        func(nums,0);
        return ans;
    }
};