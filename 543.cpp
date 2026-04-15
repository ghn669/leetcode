//二叉树的直径
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
    int res = 0;
    int depth(TreeNode* root)
    {
        if(root==nullptr) return -1;
        int left = depth(root->left)+1;
        int right = depth(root->right)+1;
        res = max(res,left+right);
        return max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return res;
    }
};