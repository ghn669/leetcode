//二叉树的层平均值
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root,int level,vector<double>& sum,vector<int>& cnt)
    {
        if(root==nullptr) return;
        if(level<sum.size())
        {
            sum[level]+=root->val;
            cnt[level]+=1;
        }
        else
        {
            sum.push_back(1.0*root->val);
            cnt.push_back(1);
        }
        dfs(root->left,level+1,sum,cnt);
        dfs(root->right,level+1,sum,cnt);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> sum;
        vector<int> cnt;
        vector<double> average;
        dfs(root,0,sum,cnt);
        for(int i=0;i<sum.size();i++)
        {
            average.push_back(sum[i]/cnt[i]);
        }
        return average;
    }
};