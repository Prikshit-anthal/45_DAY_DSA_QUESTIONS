class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int r = maxDepth(root->right);
        int l = maxDepth(root->left);
        return r > l ? r + 1 : l + 1;
    }
};