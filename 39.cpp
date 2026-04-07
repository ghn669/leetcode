//组数总和
class Solution {
public:
    vector<vector<int>> res;
    vector<int> arr;
    void dfs(int pos,vector<int> candidates,int target)
    {
        if(target==0)
        {
            res.push_back(arr);
            return;
        }
        for(int i=pos;i<candidates.size();i++)
        {
            if(candidates[i]<=target)
            {
                arr.push_back(candidates[i]);
                dfs(i,candidates,target-candidates[i]);
                arr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(0,candidates,target);
        return res;
    }
};