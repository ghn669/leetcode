//打家劫舍III
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
    vector<int> robtree(TreeNode* root)
    {
        if(root==nullptr) return {0,0};
        vector<int> leftdp=robtree(root->left);
        vector<int> rightdp=robtree(root->right);
        int val1=max(leftdp[0],leftdp[1])+max(rightdp[0],rightdp[1]);
        int val2=root->val+leftdp[0]+rightdp[0];
        return {val1,val2};
    }
    int rob(TreeNode* root) {
        vector<int> dp = robtree(root);
        return max(dp[0],dp[1]);
    }
};