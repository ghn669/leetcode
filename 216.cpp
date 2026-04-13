//组合总数III
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void dfs(int start,int n,int k)
    {
        if(n<0)
        {
            return;
        }
        if(n==0&&path.size()==k)
        {
            res.push_back(path);
            return;
        }
        for(int i=start;i<=9&&i<=n;i++)
        {
            path.push_back(i);
            dfs(i+1,n-i,k);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1,n,k);
        return res;
    }
};