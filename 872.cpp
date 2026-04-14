//叶子相似的树
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        if(root->left==nullptr&&root->right==nullptr) return 1;
        int depth = INT_MAX;
        if(root->left!=nullptr) depth = min(minDepth(root->left),depth);
        if(root->right!=nullptr) depth = min(minDepth(root->right),depth);
        return depth+1;
    }
};