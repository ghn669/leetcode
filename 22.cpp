//括号字符串生成
class Solution {
public:
    vector<string> res;
    string t;
    void dfs(int l,int r,int n)
    {
        if(l==n&&r==n)
        {
            res.push_back(t);
        }
        if(l<n)
        {
            t.push_back('(');
            dfs(l+1,r,n);
            t.pop_back();
        }
        if(r<l)
        {
            t.push_back(')');
            dfs(l,r+1,n);
            t.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        dfs(0,0,n);
        return res;
    }
};